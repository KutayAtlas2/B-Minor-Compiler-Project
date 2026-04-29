#include "ast.h"
#include <stdlib.h>
#include "symboltable.h"
#include <stdio.h>
#include "parser.tab.h"

extern int current_scope;

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
    
    symbol *s = lookUpRetiredSymbol(n->name); 
    
                if (!s) {
                    fprintf(stderr, "Error: Variable '%s' not found in history\n", n->name);
                    exit(1);
             }
                n->symbol = s;
                n->type = s->type;
                break;
            } 

        case AST_ARRAY_LITERAL: { // The "Access" rule
                symbol *s = lookUpRetiredSymbol(n->name);
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
                n->type = INTEGER; 
                break;
        }

        case AST_BINARY_EXPR: {

             int left_type = semanticAnalysis(n->left);
             int right_type = semanticAnalysis(n->right);

            if (left_type != right_type) {
                fprintf(stderr, "Type Mismatch: Cannot operate on %d and %d\n", left_type, right_type);
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
             semanticAnalysis(n->left);
             semanticAnalysis(n->middle);
             semanticAnalysis(n->right);
        break;
        case AST_FUNCTION_DECL:

              enterScope(); 

             semanticAnalysis(n->left);
             semanticAnalysis(n->middle);
             semanticAnalysis(n->right);

             exitScope();
        break;
        case AST_VARIABLE_DECL:
            // Check the assignment expression if it exists
             if (n->right) {
             int expr_type = semanticAnalysis(n->right);
             int expected_type = n->left->int_value;

             if (expr_type != expected_type) {
            fprintf(stderr, "Semantic Error: Type mismatch in declaration of '%s'. Expected %s, got %s\n", 
                    n->name, typeToString(expected_type), typeToString(expr_type));
            exit(1);
        }
           // hope i dont forget to add this: if (expr_type != n->left->int_value) error!
           // I didnt.
                 }
             break;
        case AST_ASSIGN_EXPR: {
               symbol *s = lookUpRetiredSymbol(n->name);
                if (!s) {
              fprintf(stderr, "Error: Assignment to undeclared variable '%s'\n", n->name);
               exit(1);
                   }
               int expr_type = semanticAnalysis(n->right);
               
               if (s->type != expr_type) {
                    fprintf(stderr, "Semantic Error: Cannot assign type %d to variable '%s' of type %d\n", 
                       expr_type, n->name, s->type);
                    exit(1);
                 }

                n->type = expr_type;
             break;
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
