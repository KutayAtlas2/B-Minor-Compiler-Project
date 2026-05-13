.section .data
  format_int: .string "%d\n"
  format_str: .string "%s\n"
  format_float: .string "%f\n"
  format_char: .string "%c\n"

.section .text
.globl main
test:
  pushq %rbp
  movq %rsp, %rbp
  subq $248, %rsp
  movq %rdi, -8(%rbp)
  movq %rsi, -16(%rbp)
  movq -8(%rbp), %rax
  movq -16(%rbp), %rbx
  imulq %rbx, %rax
  movq %rax, -24(%rbp)
  movq -24(%rbp), %rax
  movq %rax, %rax
  jmp .test_exit
.test_exit:
  leave
  ret
testo:
  pushq %rbp
  movq %rsp, %rbp
  subq $248, %rsp
  movq %rdi, -8(%rbp)
  movq -8(%rbp), %rax
  movq $5, %rbx
  addq %rbx, %rax
  movq %rax, -16(%rbp)
  movq -16(%rbp), %rax
  movq %rax, %rax
  jmp .testo_exit
.testo_exit:
  leave
  ret
main:
  pushq %rbp
  movq %rsp, %rbp
  subq $248, %rsp
  movq %rdi, -8(%rbp)
  movq %rsi, -16(%rbp)
  movq $3, %rdi
  movq $2, %rsi
  call test
  movq %rax, -24(%rbp)
  movq -24(%rbp), %rax
  movq %rax, -8(%rbp)
  pushq %rax
  pushq %rcx
  pushq %rdx
  pushq %rsi
  pushq %rdi
  movq $format_int, %rdi
  movq -8(%rbp), %rax
  movq %rax, %rsi
  movq $0, %rax
  call printf
  popq %rdi
  popq %rsi
  popq %rdx
  popq %rcx
  popq %rax
  movq $2, %rdi
  call testo
  movq %rax, -32(%rbp)
  movq -32(%rbp), %rax
  movq %rax, -16(%rbp)
  pushq %rax
  pushq %rcx
  pushq %rdx
  pushq %rsi
  pushq %rdi
  movq $format_int, %rdi
  movq -16(%rbp), %rax
  movq %rax, %rsi
  movq $0, %rax
  call printf
  popq %rdi
  popq %rsi
  popq %rdx
  popq %rcx
  popq %rax
.main_exit:
  leave
  ret
