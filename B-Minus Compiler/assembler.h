#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "codegen.h"

void generate_asm(struct IR_Instr *head, const char *filename);

#endif