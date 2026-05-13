#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H


typedef struct symbol {
    char *name;
    int type;        //AST_TYPE 
    int scope; // 0 -> global, 1 -> function
    struct symbol *next;
    int is_function;
    int retired;
    char *parent_function;
} symbol;

void enterScope();
void exitScope();

int insertSymbol(char *name, int type, int is_function, char *parent_function); // add: var -> table

symbol* lookUpSymbol(char *name); // validate passport control ahh function.
symbol* lookUpRetiredSymbol(char *name); //still remember the invalid ones.

#endif