#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H


typedef struct symbol {
    char *name;
    int type;        //AST_TYPE 
    int scope; // 0 -> global, 1 -> function
    struct symbol *next;
    int retired;
} symbol;

void enterScope();
void exitScope();

int insertSymbol(char *name, int type); // add: var -> table

symbol* lookUpSymbol(char *name); // validate passport control ahh function.
symbol* lookUpRetiredSymbol(char *name); //still remember the invalid ones.
#endif