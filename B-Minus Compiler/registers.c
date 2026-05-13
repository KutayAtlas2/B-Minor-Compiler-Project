#include "registers.h"
#include <string.h>
#include <stdlib.h>

Register reg_pool[NUM_REGS];
const char* reg_names[] = {"%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi", "%r8", "%r9"};

void init_registers() {
    for (int i = 0; i < NUM_REGS; i++) {
        reg_pool[i].name = reg_names[i];
        reg_pool[i].is_free = true;
        if(reg_pool[i].temp_name) free(reg_pool[i].temp_name);
        reg_pool[i].temp_name = NULL;
    }
}

int allocate_register(char *temp) {
    for (int i = 0; i < NUM_REGS; i++) {
        if (!reg_pool[i].is_free && reg_pool[i].temp_name && strcmp(reg_pool[i].temp_name, temp) == 0) {
            return i;
        }
    }
    for (int i = 0; i < NUM_REGS; i++) {
        if (reg_pool[i].is_free) {
            reg_pool[i].is_free = false;
            reg_pool[i].temp_name = strdup(temp);
            return i;
        }
    }
    free_register(0);
    reg_pool[0].is_free = false;
    reg_pool[0].temp_name = strdup(temp);
    return 0;
}

void free_register(int i) {
    if (i >= 0 && i < NUM_REGS) {
        reg_pool[i].is_free = true;
        if (reg_pool[i].temp_name) {
            free(reg_pool[i].temp_name);
            reg_pool[i].temp_name = NULL;
        }
    }
}

const char* get_reg_name(int i) { return reg_pool[i].name; }