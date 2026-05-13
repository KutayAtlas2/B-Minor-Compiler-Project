#include "ast.h"
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
#include <stdio.h>
#include "parser.tab.h"

extern int current_scope;
static char current_semantic_function[256] = "";

const char *typeToString(int type){
 switch(type){
   case INTEGER:
     return " an integer type";
   break;
   case FLOAT: 
     return "a float type";
   break;
   case STRING:  
    return "a string";
   break; 
    case BOOLEAN: 
     return "a boolean";
    break;
    case CHAR:
     return "a char";
    break;
    case ARRAY:
     return "an array";
    break;
    case VOID:    
     return "a void";
    break;
    default:      
     return "an unknown type";
    break;
 }
}

int semanticAnalysis(struct ast_node *n) {

    if(!n) {return AST_VOID_LITERAL;}

    switch (n->kind) {
        case AST_IDENTIFIER: {
                symbol *s = lookUpSymbolInScope(n->name, current_semantic_function);
                if (!s) {
                    fprintf(stderr, "Error: Variable '%s' not found in current scope\n", n->name);
                    exit(1);
                }
                n->symbol = s;
                n->type = s->type;
                break;
            }

        case AST_ARRAY_LITERAL: { // The "Access" rule
                symbol *s = lookUpSymbolInScope(n->name, current_semantic_function);
                if (!s) {
                     fprintf(stderr, "Error: Array '%s' undeclared\n", n->name);
                     exit(1);
               }

                int index_type = semanticAnalysis(n->right);

                if (s->type != ARRAY) {
                     fprintf(stderr, "Error: '%s' is not an array\n", n->name);
                     exit(1);
               }

                if (index_type != INTEGER) {
                     fprintf(stderr, "Error: Array index for '%s' must be an integer\n", n->name);
                     exit(1);
               }

                n->symbol = s;
                n->type = s->base_type;
                break;
        }

        case AST_BINARY_EXPR: {

             int left_type = semanticAnalysis(n->left);
             int right_type = semanticAnalysis(n->right);

            if (left_type != right_type) {
                fprintf(stderr, "Type Mismatch: Cannot operate on %s and %s\n", typeToString(left_type), typeToString(right_type));
                exit(1);
            }
            n->type = left_type;
            break;
        }
        case AST_BLOCK:
            enterScope(); 

             semanticAnalysis(n->left);
             semanticAnalysis(n->middle);
             semanticAnalysis(n->right);

             exitScope(); 
             break;
        case AST_IF_STMT:
             semanticAnalysis(n->left);
             semanticAnalysis(n->middle);
             semanticAnalysis(n->right);
             break;
        case AST_RETURN_STMT:
        case AST_PRINT_STMT:
        case AST_EXPR_STMT:
             semanticAnalysis(n->left);
             semanticAnalysis(n->middle);
             semanticAnalysis(n->right);
             break;
        case AST_WHILE_STMT:
             semanticAnalysis(n->left);
             semanticAnalysis(n->middle);
             semanticAnalysis(n->right);
             break;
        case AST_CALL_EXPR:
                if (n->left) semanticAnalysis(n->left);

                symbol *s = lookUpFunctionSymbol(n->name);
                if (!s) {
                    fprintf(stderr, "Error: Function '%s' undeclared\n", n->name);
                    exit(1);
                }

                n->type = s->type;
                return n->type;
            break;
        case AST_FUNCTION_DECL: {
             char previous_function[256];
             strncpy(previous_function, current_semantic_function, sizeof(previous_function));
             previous_function[sizeof(previous_function) - 1] = '\0';

             if (n->name) {
                 strncpy(current_semantic_function, n->name, sizeof(current_semantic_function) - 1);
                 current_semantic_function[sizeof(current_semantic_function) - 1] = '\0';
             } else {
                 current_semantic_function[0] = '\0';
             }

             enterScope();
             semanticAnalysis(n->left);
             semanticAnalysis(n->middle);
             semanticAnalysis(n->right);
             exitScope();

             strncpy(current_semantic_function, previous_function, sizeof(current_semantic_function) - 1);
             current_semantic_function[sizeof(current_semantic_function) - 1] = '\0';
             break;
        }
        case AST_VARIABLE_DECL:
            // Check the assignment expression if it exists
             if (n->right) {
                 if (n->left->int_value == ARRAY && n->right->kind == AST_ARRAY_INIT) {
                     int expected_base = n->left->left->int_value;
                     int expected_count = n->left->num_value;
                     int count = 0;
                     struct ast_node *item = n->right->left;

                     while (item) {
                         int expr_type = semanticAnalysis(item);
                         if (expr_type != expected_base) {
                             fprintf(stderr, "Semantic Error: Array initializer for '%s' expects %s but got %s\n",
                                     n->name, typeToString(expected_base), typeToString(expr_type));
                             exit(1);
                         }
                         count++;
                         item = item->next;
                     }

                     if (count != expected_count) {
                         fprintf(stderr, "Semantic Error: Array initializer for '%s' must have %d elements, got %d\n",
                                 n->name, expected_count, count);
                         exit(1);
                     }
                 } else if (n->left->int_value == ARRAY) {
                     fprintf(stderr, "Semantic Error: Cannot assign non-array initializer to array '%s'\n", n->name);
                     exit(1);
                 } else {
                     int expr_type = semanticAnalysis(n->right);
                     int expected_type = n->left->int_value;

                     printf("Debug: Variable %s expects %d, got %d\n", n->name, expected_type, expr_type);

                     if (expr_type != expected_type) {
                         fprintf(stderr, "Semantic Error: Type mismatch in declaration of '%s'. Expected %s, got %s\n",
                                 n->name, typeToString(expected_type), typeToString(expr_type));
                         exit(1);
                     }
                 }
             }
             break;
        case AST_ASSIGN_EXPR: {
               symbol *s = lookUpSymbolInScope(n->name, current_semantic_function);
                if (!s) {
              fprintf(stderr, "Error: Assignment to undeclared variable '%s'\n", n->name);
               exit(1);
                   }
               if (n->left) {
                   int index_type = semanticAnalysis(n->left);
                   if (index_type != INTEGER) {
                       fprintf(stderr, "Semantic Error: Array index for '%s' must be an integer\n", n->name);
                       exit(1);
                   }
                   if (s->type != ARRAY) {
                       fprintf(stderr, "Semantic Error: '%s' is not an array\n", n->name);
                       exit(1);
                   }
                   int expr_type = semanticAnalysis(n->right);
                   if (expr_type != s->base_type) {
                       fprintf(stderr, "Semantic Error: Cannot assign type %s to array '%s' element of type %s\n",
                               typeToString(expr_type), n->name, typeToString(s->base_type));
                       exit(1);
                   }
                   n->type = expr_type;
               } else {
                   int expr_type = semanticAnalysis(n->right);
                   if (s->type != expr_type) {
                        fprintf(stderr, "Semantic Error: Cannot assign type %s to variable '%s' of type %s\n",
                           typeToString(expr_type), n->name, typeToString(s->type));
                        exit(1);
                     }
                    n->type = expr_type;
               }
             break;
            }
        case AST_ARRAY_INIT: {
            struct ast_node *item = n->left;
            while (item) {
                semanticAnalysis(item);
                item = item->next;
            }
            return AST_VOID_LITERAL;
        }
        case AST_INTEGER_LITERAL:
            return n->type = INTEGER; 

        case AST_FLOAT_LITERAL:
            return n->type = FLOAT;

        case AST_STRING_LITERAL:
            return n->type = STRING;

        case AST_BOOLEAN_LITERAL:
            return n->type = BOOLEAN;

        case AST_CHAR_LITERAL:
            return n->type = CHAR;
        default:
            break;
        
    }

  int current_type = n->type;

    // this to process the next one
    if (n->next) {
        semanticAnalysis(n->next);
    }

    return current_type; 
}
