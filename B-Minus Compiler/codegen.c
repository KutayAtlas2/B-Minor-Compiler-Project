#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
#include "codegen.h"
#include <ctype.h>

int temp_count = 0;
int label_count = 0;

struct IR_Instr *ir_head = NULL;
struct IR_Instr *ir_tail = NULL;

void emit(char *op, char *res, char *a1, char *a2) {
    struct IR_Instr *new_i = malloc(sizeof(struct IR_Instr));
    new_i->op = op ? strdup(op) : strdup("UNKNOWN_OP");
    new_i->result = res ? strdup(res) : NULL;
    new_i->arg1 = a1 ? strdup(a1) : NULL;
    new_i->arg2 = a2 ? strdup(a2) : NULL;
    new_i->next = NULL;
    if (a1 == NULL) a1 = "null_err";

    if (!ir_head) {
        ir_head = new_i;
        ir_tail = new_i;
    } else {
        ir_tail->next = new_i;
        ir_tail = new_i;
    }
}
int is_constant(char *s) {
    if (!s) return 0;
    for (int i = 0; s[i]; i++) {
        if (!isdigit(s[i])) return 0;
    }
    return 1;
}
int is_string_literal(char *s) {
    if (!s) return 0;
    return (s[0] == '"');
}
char *intToString(int val){
   char *s = malloc(16);
   sprintf(s, "%d", val);
   return s;

}
char *newTemp(){
    char *t = malloc(16); //16 for the byte size.
    sprintf(t, "t%d", temp_count++);
    return t;
}
char *newLabel() {
    char *l = malloc(16);
    sprintf(l, "L%d", label_count++);
    return l;
}
char *opToString(int op /* as in operation */){
      switch(op)
        {
        case PLUS:   return "+";
        case MINUS:  return "-";
        case MUL:    return "*";
        case DIV:    return "/";
        case ASSIGN: return "=";
        case MOD:    return "%";
        case EXPO:   return "^";
        case EQ:     return "==";
        case NEQ:    return "!=";
        case LT:     return "<";
        case LE:     return "<=";
        case GT:     return ">";
        case GE:     return ">=";
        case AND:    return "&&";
        case OR:     return "||";
        case NOT:    return "!";
        default:     return "?";
      }
}
char *generateIR(struct ast_node *n){
    if(!n) return NULL;

    switch (n-> kind) {
      case AST_INTEGER_LITERAL:
        char *var = intToString(n->int_value);
        return var;
      case AST_BOOLEAN_LITERAL:
        return strdup(n->int_value ? "1" : "0");
      case AST_STRING_LITERAL: 
        return n->string_value ? strdup(n->string_value) : strdup("\"\"");
      case AST_CHAR_LITERAL:
        return n->string_value ? strdup(n->string_value) : strdup("' '");
      case AST_ARRAY_LITERAL: 
      {
         char *index = generateIR(n->right); // Get the index i
         char *target = newTemp();
         emit("array_load", target, n->name, index);
         return target;
      }
      case AST_BINARY_EXPR:
        {
          char *left = generateIR(n->left);
          char *right = generateIR(n->right);
          char *op_str = opToString(n->op);
          char *target = newTemp(); // returns t1, t2, L1, L2, bla bla bla, and so on.
          emit(op_str, target, left, right);

          if (n->left && n->left->kind == AST_INTEGER_LITERAL) {
                free(left);
             }
          if (n->right && n->right->kind == AST_INTEGER_LITERAL) {
                free(right);
             }

          return target;
        }
      case AST_UNARY_EXPR:
        {
         char *op_val = generateIR(n->left);
         char *target = newTemp();
         emit(opToString(n->op), target, op_val, NULL);
         return target;
        }
      case AST_ASSIGN_EXPR:
        {
         char *val = generateIR(n->right);
         if (!val) val = strdup("0"); // Safety net to prevent Segfault
         emit("=", n->name, val, NULL);
         return n->name;
        }
      case AST_IDENTIFIER:
        return n->name ? strdup(n->name) : strdup("unknown_id");
      case AST_BLOCK:
        {
         if (!n->left) return NULL; // for safety
          struct ast_node *stmt = n->left;
          while(stmt) {
             generateIR(stmt);
             stmt = stmt->next;
          }
          return NULL;
        }
      case AST_IF_STMT: 
       {
         char *cond = generateIR(n->left);
         char *labelElse = newLabel();
         char *labelEnd = newLabel();

         emit("ifnot", NULL, cond, labelElse);
         generateIR(n->middle); // if block.
         emit("goto", NULL, labelEnd, NULL);
    
         emit("label", NULL, labelElse, NULL);
         generateIR(n->right);  // else block.
         emit("label", NULL, labelEnd, NULL);
         break;
       }
      case AST_CALL_EXPR:
       { 
         struct ast_node *arg = n->left;
         while(arg){
          char *argName = generateIR(arg);
          emit("param", NULL, argName, NULL);
          arg = arg->next;
         }
         
         char *target = newTemp();
         emit("call", target, n->name, NULL);
         return target;
         break;
       } 
      case AST_WHILE_STMT: 
       {
         char *labelStart = newLabel();
         char *labelEnd = newLabel();
  
         emit("label", NULL, labelStart, NULL);
         char *cond = generateIR(n->left);
         emit("ifnot", NULL, cond, labelEnd);
    
         generateIR(n->right); // the looop... hehe
    
         emit("goto", NULL, labelStart, NULL);
         emit("label", NULL, labelEnd, NULL);

         free(labelStart);
         free(labelEnd);
         if (cond && !is_constant(cond)) free(cond);
         break;
       }
      case AST_VARIABLE_DECL: 
       {
         if (n->right) { // if there is an initial value.
            char *val = generateIR(n->right);
            emit("=", n->name, val, NULL);
            if (n->right->kind == AST_INTEGER_LITERAL) free(val); // free the mem leak. god that took too long to find.
        }
      break;
       }
      case AST_RETURN_STMT:
       {
         char *val = generateIR(n->left);
         emit("return", NULL, val, NULL);
         if (n->left && n->left->kind == AST_INTEGER_LITERAL) free(val); // this too.
         break;
       }
      case AST_PRINT_STMT: 
       {
         struct ast_node *arg = n->left;
         while(arg) {
              char *val = generateIR(arg);
              emit("print", NULL, val, NULL);
              arg = arg->next;
            }
          break; 
       }
      case AST_FUNCTION_DECL: 
       {
         emit("func", NULL, n->name, NULL); // mark(invincible) it function entry.

         struct ast_node *param = n->right;
         while(param) {
            emit("arg", NULL, param->name, NULL); // INCOMING! BRACE FOR PARAMETERS!
            param = param->next;
           }

         generateIR(n->middle);         // process the function body.
         emit("endfunc", NULL, NULL, NULL);
         break;
       }
      case AST_EXPR_STMT:
        {
          if (n->left) generateIR(n->left);
          else if (n->right) generateIR(n->right);
          break;
        }
      default:
          printf("WARNING: Unhandled AST Node Kind: %d\n", n->kind);
        break;
    }
    return NULL;
}
void optimize_ir(struct IR_Instr *head) {
    struct IR_Instr *curr = head;
    while (curr) {
        // Look for binary operations
        if (curr->arg1 && curr->arg2 && is_constant(curr->arg1) && is_constant(curr->arg2)) {
            int a = atoi(curr->arg1);
            int b = atoi(curr->arg2);
            int res = 0;
            int found = 1;

            if (strcmp(curr->op, "+") == 0) res = a + b;
            else if (strcmp(curr->op, "-") == 0) res = a - b;
            else if (strcmp(curr->op, "*") == 0) res = a * b;
            else if (strcmp(curr->op, "/") == 0 && b != 0) res = a / b;
            else found = 0;

            if (found) {
                free(curr->op);
                free(curr->arg1);
                free(curr->arg2);
                
                curr->op = strdup("=");
                curr->arg1 = intToString(res);
                curr->arg2 = NULL; // arg2 is no longer needed for assignment
            }
        }
        curr = curr->next;
    }
}
// same as freeAst, free the ir list to prevent memory leaks.
void free_ir_list(struct IR_Instr *head) {
    struct IR_Instr *curr = head;
    while (curr) {
        struct IR_Instr *temp = curr;
        curr = curr->next;

        // Free all strdup'd strings
        if (temp->op) free(temp->op);
        if (temp->result) free(temp->result);
        if (temp->arg1) free(temp->arg1);
        if (temp->arg2) free(temp->arg2);

        free(temp);
    }
}
//these two functions will create a .dot file
void dump_ir_to_file(const char *filename, struct IR_Instr *head) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    struct IR_Instr *curr = head;
    while (curr) {
        if (strcmp(curr->op, "label") == 0) {
            fprintf(fp, "%s:\n", curr->arg1);
        } else if (strcmp(curr->op, "goto") == 0) {
            fprintf(fp, "  goto %s\n", curr->arg1);
        } else if (strcmp(curr->op, "ifnot") == 0) {
            fprintf(fp, "  ifnot %s goto %s\n", curr->arg1, curr->arg2);
        } else if (strcmp(curr->op, "print") == 0) {
            fprintf(fp, "  print %s\n", curr->arg1);
        } else if (strcmp(curr->op, "=") == 0) {
            fprintf(fp, "  %s = %s\n", curr->result, curr->arg1);
        } else if (curr->result && curr->arg1 && curr->arg2) {
            fprintf(fp, "  %s = %s %s %s\n", curr->result, curr->arg1, curr->op, curr->arg2);
        } else if (curr->result && curr->arg1) {
            fprintf(fp, "  %s = %s %s\n", curr->result, curr->op, curr->arg1);
        } else {
            fprintf(fp, "  %s %s %s\n", curr->op, 
                    curr->arg1 ? curr->arg1 : "", 
                    curr->arg2 ? curr->arg2 : "");
        }
        curr = curr->next;
    }
    fclose(fp);
}
void generate_dot_file(const char *filename, struct IR_Instr *head) {
    FILE *fp = fopen(filename, "w");
    if(!fp) return;
    fprintf(fp, "digraph IR_Flow {\n  node [shape=rect, fontname=\"Courier\"];\n");

    struct IR_Instr *curr = head;
    //define all the nodes.
    while (curr) {
        fprintf(fp, "  instr_%p [label=\"%s | res:%s | arg1:%s | arg2:%s\"];\n", 
                (void*)curr, curr->op, 
                curr->result ? curr->result : "-", 
                curr->arg1 ? curr->arg1 : "-", 
                curr->arg2 ? curr->arg2 : "-");
        curr = curr->next;
    }
    // end of defining.
    curr = head;
    while (curr) {
        if (strcmp(curr->op, "goto") == 0) {
            struct IR_Instr *t = head;
            while(t) {
                if (strcmp(t->op, "label") == 0 && t->arg1 && strcmp(t->arg1, curr->arg1) == 0) {
                    fprintf(fp, "  instr_%p -> instr_%p [color=blue, label=\"jump\"];\n", (void*)curr, (void*)t);
                    break;
                }
                t = t->next;
            }
        } else if (strcmp(curr->op, "ifnot") == 0) {
            
            if (curr->next) fprintf(fp, "  instr_%p -> instr_%p [color=green];\n", (void*)curr, (void*)curr->next);
            
            struct IR_Instr *t = head;
            while(t) {
                if (strcmp(t->op, "label") == 0 && t->arg1 && strcmp(t->arg1, curr->arg2) == 0) {
                    fprintf(fp, "  instr_%p -> instr_%p [color=red, label=\"branch\"];\n", (void*)curr, (void*)t);
                    break;
                }
                t = t->next;
            }
        } else if (curr->next) {
            fprintf(fp, "  instr_%p -> instr_%p;\n", (void*)curr, (void*)curr->next);
        }
        curr = curr->next;
    }
    fprintf(fp, "}\n");
    fclose(fp);
}



