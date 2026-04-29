#ifndef IR_H
#define IR_H

#include "ast.h"

struct IR_Instr {
    char *result;
    char *arg1;
    char *op;
    char *arg2;
    struct IR_Instr *next;
};

char *generateIR(struct ast_node *n);
void optimize_ir(struct IR_Instr *head);
void free_ir_list(struct IR_Instr *head);

#endif