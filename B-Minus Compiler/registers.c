#include "registers.h"
#include <string.h>
#include <stdlib.h>

Register reg_pool[NUM_REGS];
const char* reg_names[] = {"%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi", "%r8", "%r9"}; // a whole lotta registers (only 8 lmao).

void init_registers() {
    for (int i = 0; i < NUM_REGS; i++) {
        reg_pool[i].name = reg_names[i];
        reg_pool[i].is_free = true;
        reg_pool[i].temp_name = NULL;
    }
}

int allocate_register(char *temp) {
    // check if the temp is already in a register.
    for (int i = 0; i < NUM_REGS; i++) {
        if (!reg_pool[i].is_free && reg_pool[i].temp_name && strcmp(reg_pool[i].temp_name, temp) == 0) {
            return i;
        }
    }

    // attempt to observe a vacant register (yes, very good english, hon hon hon).
    for (int i = 0; i < NUM_REGS; i++) {
        if (reg_pool[i].is_free) {
            reg_pool[i].is_free = false;
            reg_pool[i].temp_name = strdup(temp);
            return i;
        }
    }

    // 3. spilling Logic (Simplest: just yank the register 0 for now)
    // in a REEAL(tuff) compiler, you'd pick the "Least Recently Used" and move it to the stack
    printf("# SPILL: Register pool full, force-clearing %s\n", reg_pool[0].name);
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

const char* get_reg_name(int i) {
    return reg_pool[i].name;
}