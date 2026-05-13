#include "assembler.h"
#include "registers.h"
#include "symboltable.h"
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void emit_asm(const char *format, ...);
int is_constant(char *s);
int is_global(char *name);
int is_string_literal(char *s);
int current_arg_idx = 0;
char *newLabel();
char current_function_name[256];
const char* arg_regs[] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
FILE *asm_fp;
extern symbol *head;

typedef struct {
    char *name;
    int offset;
} StackVar;

StackVar stack_map[100];
int stack_ptr = 0;
int current_offset = 0;

int get_param_count(symbol *func_sym) {
   int count = 0;
    symbol *s = head;
    while (s != NULL) {
        if (s->scope == func_sym->scope + 1 && !s->is_function && s->parent_function && strcmp(s->parent_function, func_sym->name) == 0) {
            count++;
        }
        s = s->next;
    }
    return count;
}

char *get_param_name(symbol *func_sym, int index) {
    char *names[100];
    int count = 0;
    symbol *s = head;
    while (s != NULL) {
        if (s->scope == func_sym->scope + 1 && !s->is_function && s->parent_function && strcmp(s->parent_function, func_sym->name) == 0) {
            names[count++] = s->name;
        }
        s = s->next;
    }
    if (index < 0 || index >= count) return NULL;
    return names[count - 1 - index];
}

int get_stack_offset(char *var_name) {
    for (int i = 0; i < stack_ptr; i++) {
        if (strcmp(stack_map[i].name, var_name) == 0) {
            return stack_map[i].offset;
        }
    }
    int element_count = 1;
    symbol *sym = lookUpSymbol(var_name);
    if (sym && sym->type == ARRAY) {
        element_count = sym->array_size;
    }
    current_offset -= 8 * element_count;
    stack_map[stack_ptr].name = strdup(var_name);
    stack_map[stack_ptr].offset = current_offset;
    stack_ptr++;
    return current_offset;
}

// Helper to load any operand (Global, Local, or Constant) into a register
void load_to_reg(char *name, int reg_idx) {
    if (is_constant(name)) {
        emit_asm("movq $%s, %s", name, get_reg_name(reg_idx));
    } else if (is_global(name)) {
        emit_asm("movq %s(%%rip), %s", name, get_reg_name(reg_idx));
    } else {
        emit_asm("movq %d(%%rbp), %s", get_stack_offset(name), get_reg_name(reg_idx));
    }
}

// Helper to store a register into a variable (Global or Local)
void store_from_reg(int reg_idx, char *dest_name) {
    if (is_global(dest_name)) {
        emit_asm("movq %s, %s(%%rip)", get_reg_name(reg_idx), dest_name);
    } else {
        emit_asm("movq %s, %d(%%rbp)", get_reg_name(reg_idx), get_stack_offset(dest_name));
    }
}

void emit_asm(const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(asm_fp, "  ");
    vfprintf(asm_fp, format, args);
    fprintf(asm_fp, "\n");
    va_end(args);
}

void generate_asm(struct IR_Instr *ir_head, const char *filename) {
    asm_fp = fopen(filename, "w");
    if (!asm_fp) { perror("File error"); return; }

    fprintf(asm_fp, ".section .data\n");
    fprintf(asm_fp, "  format_int: .string \"%%d\\n\"\n");
    fprintf(asm_fp, "  format_str: .string \"%%s\\n\"\n");
    fprintf(asm_fp, "  format_float: .string \"%%f\\n\"\n");
    fprintf(asm_fp, "  format_char: .string \"%%c\\n\"\n");

    // Dynamic Global Declarations
    extern symbol *head; 
    symbol *temp_s = head;
    while (temp_s != NULL) {
        if (temp_s->scope == 0 && !temp_s->is_function) { // Only global variables, not functions
            if (temp_s->type == ARRAY) {
                fprintf(asm_fp, "  %s: .zero %d\n", temp_s->name, temp_s->array_size * 8);
            } else {
                fprintf(asm_fp, "  %s: .quad 0\n", temp_s->name);
            }
        }
        temp_s = temp_s->next;
    }
    
    fprintf(asm_fp, "\n.section .text\n");
    fprintf(asm_fp, ".globl main\n");

    struct IR_Instr *curr = ir_head;
    init_registers();

    while (curr) {
        if (strcmp(curr->op, "label") == 0) {
           fprintf(asm_fp, "%s:\n", curr->arg1);
               }
        else if (curr->op[0] == 'L' && (curr->op[1] >= '0' && curr->op[1] <= '9')) {
           fprintf(asm_fp, "%s:\n", curr->op);
          }
        else if (strcmp(curr->op, "func") == 0) {
            stack_ptr = 0; 
            current_offset = 0; // Reset for every new function
            strncpy(current_function_name, curr->arg1, sizeof(current_function_name)-1);

            fprintf(asm_fp, "%s:\n", curr->arg1);
            emit_asm("pushq %%rbp");
            emit_asm("movq %%rsp, %%rbp");
            emit_asm("subq $248, %%rsp");

            symbol *func_sym = lookUpSymbol(curr->arg1);
            int param_count = get_param_count(func_sym); 
    
            for (int i = 0; i < param_count; i++) {
                    char* p_name = get_param_name(func_sym, i);
                    // This registers the parameter in the stack map FIRST
                    int offset = get_stack_offset(p_name); 
                    emit_asm("movq %s, %d(%%rbp)", arg_regs[i], offset);
                }
          } 
        else if (strcmp(curr->op, "=") == 0) {
           int r = allocate_register("tmp");
           load_to_reg(curr->arg1, r);
           store_from_reg(r, curr->result);
           free_register(r);
        }
        else if (strcmp(curr->op, "+") == 0) {
            int r1 = allocate_register(curr->arg1);
            int r2 = allocate_register(curr->arg2);
            load_to_reg(curr->arg1, r1);
            load_to_reg(curr->arg2, r2);
            emit_asm("addq %s, %s", get_reg_name(r2), get_reg_name(r1));
            store_from_reg(r1, curr->result);
            free_register(r1); free_register(r2);
        }
        else if (strcmp(curr->op, "*") == 0) {
            int r1 = allocate_register(curr->arg1);
            int r2 = allocate_register(curr->arg2);
            load_to_reg(curr->arg1, r1);
            load_to_reg(curr->arg2, r2);
            emit_asm("imulq %s, %s", get_reg_name(r2), get_reg_name(r1));
            store_from_reg(r1, curr->result);
            free_register(r1); free_register(r2);
        }
        else if (strcmp(curr->op, "/") == 0) {
             // x86-64 idivq requires the dividend in RAX
            emit_asm("movq %d(%%rbp), %%rax", get_stack_offset(curr->arg1));
            emit_asm("cqto"); // Sign-extend RAX into RDX:RAX
            int r2 = allocate_register("div_val");
            load_to_reg(curr->arg2, r2);
            emit_asm("idivq %s", get_reg_name(r2));
             // The quotient is now in RAX
            emit_asm("movq %%rax, %d(%%rbp)", get_stack_offset(curr->result));
            free_register(r2);
        }
        else if (strcmp(curr->op, "array_load") == 0) {
            int r_idx = allocate_register("idx");
            load_to_reg(curr->arg2, r_idx);
            int r_target = allocate_register("arrload");
            if (is_global(curr->arg1)) {
                emit_asm("movq %s(, %s, 8), %s", curr->arg1, get_reg_name(r_idx), get_reg_name(r_target));
            } else {
                emit_asm("movq %d(%%rbp, %s, 8), %s", get_stack_offset(curr->arg1), get_reg_name(r_idx), get_reg_name(r_target));
            }
            store_from_reg(r_target, curr->result);
            free_register(r_target);
            free_register(r_idx);
        }
        else if (strcmp(curr->op, "array_store") == 0) {
            int r_idx = allocate_register("idx");
            load_to_reg(curr->arg1, r_idx);
            int r_val = allocate_register("val");
            load_to_reg(curr->arg2, r_val);
            if (is_global(curr->result)) {
                emit_asm("movq %s, %s(, %s, 8)", get_reg_name(r_val), curr->result, get_reg_name(r_idx));
            } else {
                emit_asm("movq %s, %d(%%rbp, %s, 8)", get_reg_name(r_val), get_stack_offset(curr->result), get_reg_name(r_idx));
            }
            free_register(r_val);
            free_register(r_idx);
        }
        else if (strcmp(curr->op, "-") == 0) {
            int r1 = allocate_register("math");
            
            load_to_reg(curr->arg1, r1);
            
            if (is_constant(curr->arg2)) {
                emit_asm("subq $%s, %s", curr->arg2, get_reg_name(r1));
            } else {
                int r2 = allocate_register("sub_val");
                load_to_reg(curr->arg2, r2);
                emit_asm("subq %s, %s", get_reg_name(r2), get_reg_name(r1));
                free_register(r2);
            }
            
            store_from_reg(r1, curr->result);
            free_register(r1);
        }
        else if (strcmp(curr->op, "print") == 0) {
           
          emit_asm("pushq %%rax");
          emit_asm("pushq %%rcx");
          emit_asm("pushq %%rdx");
          emit_asm("pushq %%rsi");
          emit_asm("pushq %%rdi");

          if (curr->arg1[0] == '"') { 
       
            char *str_label = newLabel();
            emit_asm(".section .data");
            fprintf(asm_fp, "  %s: .string %s\n", str_label, curr->arg1);
            emit_asm(".section .text");
            emit_asm("movq $format_str, %%rdi");
            emit_asm("movq $%s, %%rsi", str_label);
              } 
          else if (curr->arg1[0] == '\'') {
        
            emit_asm("movq $format_char, %%rdi");
            emit_asm("movq $%d, %%rsi", (int)curr->arg1[1]); 
            emit_asm("movq $0, %%rax");
            emit_asm("call printf");
              }
          else if (strcmp(curr->arg1, "true") == 0 || strcmp(curr->arg1, "false") == 0) {
       
            emit_asm("movq $format_int, %%rdi");
            emit_asm("movq $%d, %%rsi", strcmp(curr->arg1, "true") == 0 ? 1 : 0);
                    }
          else {
       
               emit_asm("movq $format_int, %%rdi"); 
               int r = allocate_register("p");
               load_to_reg(curr->arg1, r);
               emit_asm("movq %s, %%rsi", get_reg_name(r));
               free_register(r);
               }

              emit_asm("movq $0, %%rax"); 
              emit_asm("call printf");

    
               emit_asm("popq %%rdi");
               emit_asm("popq %%rsi");
               emit_asm("popq %%rdx");
               emit_asm("popq %%rcx");
               emit_asm("popq %%rax");
        }
        else if (strcmp(curr->op, "arg") == 0) {
           
            if (current_arg_idx < 6) {
                if (is_constant(curr->arg1)) {
                    emit_asm("movq $%s, %s", curr->arg1, arg_regs[current_arg_idx]);
                } else {
                    
                    emit_asm("movq %d(%%rbp), %s", get_stack_offset(curr->arg1), arg_regs[current_arg_idx]);
                }
                current_arg_idx++;
            }
        }
        else if (strcmp(curr->op, "call") == 0) {
            emit_asm("call %s", curr->arg1);
            
            current_arg_idx = 0;

            if (curr->result) {
            emit_asm("movq %%rax, %d(%%rbp)", get_stack_offset(curr->result));
            }
        }
        else if (strcmp(curr->op, "endfunc") == 0) {
            fprintf(asm_fp, ".%s_exit:\n", current_function_name);
            emit_asm("leave");
            emit_asm("ret");
        }
        else if (strcmp(curr->op, "return") == 0) {
            int r = allocate_register("ret");
            load_to_reg(curr->arg1, r);
            emit_asm("movq %s, %%rax", get_reg_name(r));
            free_register(r);
            emit_asm("jmp .%s_exit", current_function_name); // Jump to the leave/ret block
        }
        else if (strcmp(curr->op, ">") == 0 || strcmp(curr->op, "<") == 0 || strcmp(curr->op, "==") == 0) {
            int r1 = allocate_register("c1");
            int r2 = allocate_register("c2");
            load_to_reg(curr->arg1, r1);
            load_to_reg(curr->arg2, r2);
            emit_asm("cmpq %s, %s", get_reg_name(r2), get_reg_name(r1));

            if (strcmp(curr->op, ">") == 0) emit_asm("setg %%al");
            else if (strcmp(curr->op, "<") == 0) emit_asm("setl %%al");
            else emit_asm("sete %%al");

            emit_asm("movzbq %%al, %s", get_reg_name(r1));
            store_from_reg(r1, curr->result);
            free_register(r1); free_register(r2);
        }
        else if (strcmp(curr->op, "ifnot") == 0) {
            int r = allocate_register("if");
            load_to_reg(curr->arg1, r);
            emit_asm("cmpq $0, %s", get_reg_name(r));
            emit_asm("je %s", curr->arg2);
            free_register(r);
        }
        else if (strcmp(curr->op, "goto") == 0) {
            emit_asm("jmp %s", curr->arg1);
        }
        curr = curr->next;
    }
    fclose(asm_fp);
}