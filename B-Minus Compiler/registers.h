#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdio.h>
#include <stdbool.h>

// use 8 general purpose registers cuz this is a simple compiler.
#define NUM_REGS 8

typedef struct {
    const char *name;
    bool is_free;
    char *temp_name; // where t1, t0, etc currently lives.
} Register;

void init_registers();
int allocate_register(char *temp);
void free_register(int reg_index);


// helper to get the register name by index
const char* get_reg_name(int index);

#endif