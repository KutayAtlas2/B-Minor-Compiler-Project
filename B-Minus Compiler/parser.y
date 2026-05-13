%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h" // again, how did you forget to include it TWICE... TWICE!
#include "symboltable.h" // didn't forget it this time tho
#include "codegen.h"
#include "assembler.h"
#include "registers.h"

extern struct IR_Instr *ir_head;
int yylex(void);
void yyerror(const char *s);
struct ast_node *program_root = NULL;
int errors = 0;
static char current_func_name[256] = "";

%}

%union {
    char* id;
    int num;
    double fnum;
    struct ast_node *node;
}
// LOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOONNNNNNNNNNNNNNNNNGGGGGGGGGGGGGGGGGG code line
%type <node> expr stmt stmt_list block var_decl decl_list type func_decl param_list param_list_nonempty param expr_stmt if_stmt while_stmt return_stmt print_stmt expr_list arg_list arg_list_nonempty decl func_body func_suffix

%token <id> IDENTIFIER CHARACTER_LITERAL STRING_LITERAL
%token <num> NUMBER
%token <fnum> FLOAT_LITERAL
%token INTEGER FLOAT BOOLEAN CHAR STRING ARRAY VOID
%token IF ELSE WHILE RETURN PRINT FUNCTION
%token TRUE FALSE
%token PLUS MINUS MUL DIV MOD EXPO ASSIGN EQ NEQ LT LE GT GE AND OR NOT
%token COLON SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACK RBRACK


%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD
%right EXPO
%right NOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%define parse.error verbose

%%

program:
    decl_list { program_root = $1; }
    ;

decl_list:
    decl_list decl {
        if ($1 == NULL) { $$ = $2; }
        else {
            struct ast_node *temp = $1;
            while (temp->next) temp = temp->next;
            temp->next = $2;
            $$ = $1;
        }
    }
    | /* empty */ { $$ = NULL; }
    ;

decl:
    var_decl
    | func_decl
    ;


var_decl:
    IDENTIFIER COLON type SEMICOLON {
        if (!insertSymbol($1, $3->int_value, 0, NULL)) {
            yyerror("Redeclaration of variable in same scope");
        }
        $$ = make_node(AST_VARIABLE_DECL, $3, NULL);
        $$->name = $1;
        }
    | IDENTIFIER COLON type ASSIGN expr SEMICOLON {
        if (!insertSymbol($1, $3->int_value, 0, NULL)) {
            yyerror("Redeclaration of variable in same scope");
        }
        $$ = make_node(AST_VARIABLE_DECL, $3, $5);
        $$->name = $1;
    }
    ;

type:
    INTEGER { $$ = make_node(AST_TYPE, NULL, NULL); $$->int_value = INTEGER; }
    | FLOAT { $$ = make_node(AST_TYPE, NULL, NULL); $$->int_value = FLOAT; }
    | BOOLEAN { $$ = make_node(AST_TYPE, NULL, NULL); $$->int_value = BOOLEAN; }
    | CHAR { $$ = make_node(AST_TYPE, NULL, NULL); $$->int_value = CHAR; }
    | STRING { $$ = make_node(AST_TYPE, NULL, NULL); $$->int_value = STRING; }
    | VOID { $$ = make_node(AST_TYPE, NULL, NULL); $$->int_value = VOID; }
    | ARRAY LBRACK NUMBER RBRACK type { $$ = make_node(AST_TYPE, $5, NULL); $$->int_value = ARRAY; $$->num_value = $3; }
    ;


func_decl:
   IDENTIFIER COLON FUNCTION type { 
        if (!insertSymbol($1, $4->int_value, 1, NULL)) {
            yyerror("Function already exists");
        }
        strncpy(current_func_name, $1, sizeof(current_func_name) - 1);
        current_func_name[sizeof(current_func_name) - 1] = '\0';
    } LPAREN { enterScope(); } param_list RPAREN func_suffix {
        $$ = $10; // func_suffix returns the node
        $$->left = $4;
        $$->right = $8;
        $$->name = $1;
        exitScope();
    }
    ;

func_suffix:
    ASSIGN func_body {
        $$ = make_node(AST_FUNCTION_DECL, NULL, NULL);
        $$->middle = $2;
    }
    | SEMICOLON {
        $$ = make_node(AST_FUNCTION_DECL, NULL, NULL);
        // Prototype, so middle stays NULL
    }
    ;

param_list:
    /* empty */ { $$ = NULL; }
    | param_list_nonempty
    ;

param_list_nonempty:
    param { $$ = $1; }
    | param_list_nonempty COMMA param {
        struct ast_node *temp = $1;
        while(temp->next) temp = temp->next;
        temp->next = $3;
        $$ = $1;
    }
    ;

param:
    IDENTIFIER COLON type {
        if (!insertSymbol($1, $3->int_value, 0, current_func_name)) {
            yyerror("Parameter name already used in this scope");
        }
        $$ = make_node(AST_PARAM, $3, NULL); // param(my money)
        $$->name = $1;
              }
    ;

block:
    LBRACE { enterScope(); } stmt_list RBRACE { 
        exitScope();
        $$ = make_node(AST_BLOCK, $3, NULL); }
    ;

func_body:
    LBRACE stmt_list RBRACE { $$ = make_node(AST_BLOCK, $2, NULL); }
    ;

stmt_list:
    stmt_list stmt {
          if ($1 == NULL) { $$ = $2; }
          else {
              struct ast_node *temp = $1;
              while (temp->next) temp = temp->next;
              temp->next = $2;
              $$ = $1;
          }
      }
    | /* empty */ { $$ = NULL; }
    ;

stmt:
    var_decl
    | expr_stmt
    | if_stmt
    | while_stmt
    | return_stmt
    | print_stmt
    | block
    ;

expr_stmt:
    expr SEMICOLON { $$ = make_node(AST_EXPR_STMT, $1, NULL); }
    ;

if_stmt:
    IF LPAREN expr RPAREN stmt  %prec LOWER_THAN_ELSE {
        $$ = make_node(AST_IF_STMT, $3, $5); 
                } 
    | IF LPAREN expr RPAREN stmt ELSE stmt {
        $$ = make_node(AST_IF_STMT, $3, NULL);
        $$->middle = $5;
        $$->right = $7; 
                }
    ;

while_stmt:
    WHILE LPAREN expr RPAREN stmt {
        $$ = make_node(AST_WHILE_STMT, $3, $5);
                }
    ;

return_stmt:
    RETURN expr SEMICOLON { $$ = make_node(AST_RETURN_STMT, $2, NULL); }
    | RETURN SEMICOLON { $$ = make_node(AST_RETURN_STMT, NULL, NULL); }
    ;

print_stmt:
    PRINT expr_list SEMICOLON { $$ = make_node(AST_PRINT_STMT, $2, NULL); }
    ;

expr_list:
    expr { $$ = $1; }
    | expr_list COMMA expr {
        struct ast_node *temp = $1;
        while(temp->next) temp = temp->next;
        temp->next = $3;
        $$ = $1;
    }
    ;

expr:
    expr PLUS expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = PLUS; }
    | expr MINUS expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = MINUS; }
    | expr MUL expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = MUL; }
    | expr DIV expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = DIV; }
    | expr MOD expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = MOD; }
    | expr EXPO expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = EXPO; }
    | expr EQ expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = EQ; }
    | expr NEQ expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = NEQ; }
    | expr LT expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = LT; }
    | expr LE expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = LE; }
    | expr GT expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = GT; }
    | expr GE expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = GE; }
    | expr AND expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = AND; }
    | expr OR expr { $$ = make_node(AST_BINARY_EXPR, $1, $3); $$->op = OR; }
    | NOT expr { $$ = make_node(AST_UNARY_EXPR, $2, NULL); $$->op = NOT; }
    | LPAREN expr RPAREN {$$ = $2; }
    | IDENTIFIER { 
        symbol *s = lookUpSymbol($1);
        if (!s) {
            yyerror("Variable not declared!");
        }
        $$ = make_node(AST_IDENTIFIER, NULL, NULL);
                   $$-> name = $1; }
    | IDENTIFIER ASSIGN expr { 
        if (!lookUpSymbol($1)) {
            yyerror("Cannot assign to undeclared variable");
        }
        $$ = make_node(AST_ASSIGN_EXPR, NULL, $3);
                   $$-> name = $1; }
    | IDENTIFIER LBRACK expr RBRACK {
        if (!lookUpSymbol($1)) yyerror("Undeclared array identifier");
        $$ = make_node(AST_ARRAY_LITERAL, NULL, $3); //treat array access like a binary op: [Identifier, Index], brilliant
        $$->name = $1;
       }
    | IDENTIFIER LPAREN arg_list RPAREN {
        if (!lookUpSymbol($1)) yyerror("Call to undeclared function");
        $$ = make_node(AST_CALL_EXPR, $3, NULL);
        $$->name = $1;
         }
    | NUMBER { $$ = make_node(AST_INTEGER_LITERAL, NULL, NULL);
                   $$-> int_value = $1; }
    | CHARACTER_LITERAL { $$ = make_node(AST_CHAR_LITERAL, NULL, NULL);
                   $$-> name = $1; }
    | STRING_LITERAL { $$ = make_node(AST_STRING_LITERAL, NULL, NULL);
                   $$-> string_value = $1; }
    | FLOAT_LITERAL { $$ = make_node(AST_FLOAT_LITERAL, NULL, NULL);
                   $$-> float_value = $1; }
    | TRUE { $$ = make_node(AST_BOOLEAN_LITERAL, NULL, NULL);
                   $$-> int_value = 1; }
    | FALSE { $$ = make_node(AST_BOOLEAN_LITERAL, NULL, NULL);
                   $$-> int_value = 0; }
    ;

arg_list:
    /* empty */ { $$ = NULL; }
    | arg_list_nonempty { $$ = $1; }
    ;

arg_list_nonempty:
    expr { $$ = $1; }
    | arg_list_nonempty COMMA expr {
        struct ast_node *temp = $1;
        while(temp->next) temp = temp->next;
        temp->next = $3;
        $$ = $1;
    }
    ;

%%

void yyerror(const char *s) {
    extern int yylineno; 
    errors++;
    fprintf(stderr, "Parse error in line %d: %s\n", yylineno, s);
}

int main(void) {   

    if(yyparse() == 0 && errors == 0) {
        init_registers();
        printf("Parse successful! Starting Semantic Analysis:\n");
        semanticAnalysis(program_root);
        printf("Semantics successful\n");
        struct ast_node *current = program_root;
        while(current) {
           struct ast_node *next_backup = current->next;
    
   
    current->next = NULL;

  
    if (current->kind == AST_FUNCTION_DECL || current->kind == AST_VARIABLE_DECL) {
        generateIR(current);
    }

  
    current->next = next_backup;

  
    current = next_backup;
     }
        printf("\nOptimizing Intermediate Representation...\n");
        optimize_ir(ir_head); 
        dump_ir_to_file("output.ir", ir_head);
        generate_dot_file("graph.dot", ir_head);

        printf("Generating Assembly (output.s)...\n");
        generate_asm(ir_head, "output.s");  

        printf("\nCleaning up memory...\n");
        free_ast(program_root);

        free_ir_list(ir_head);
    }

    else{
        printf("Compilation failed with %d errors.\n", errors);
        return 1;
    }
    return 0;
}
