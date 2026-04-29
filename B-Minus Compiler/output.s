.section .data
  format_int: .string "%d\n"
  format_str: .string "%s\n"
  format_float: .string "%f\n"
  format_char: .string "%c\n"
  x: .quad 0

.section .text
.globl main
main:
  pushq %rbp
  movq %rsp, %rbp
  subq $80, %rsp
  movq $10, %rax
  movq %rax, x(%rip)
L0:
  movq x(%rip), %rax
  movq $0, %rbx
  cmpq %rbx, %rax
  setg %al
  movzbq %al, %rax
  movq %rax, -8(%rbp)
  movq -8(%rbp), %rax
  cmpq $0, %rax
  je L1
  pushq %rax
  pushq %rcx
  pushq %rdx
  pushq %rsi
  pushq %rdi
  movq $format_int, %rdi
  movq x(%rip), %rax
  movq %rax, %rsi
  movq $0, %rax
  call printf
  popq %rdi
  popq %rsi
  popq %rdx
  popq %rcx
  popq %rax
  pushq %rax
  pushq %rcx
  pushq %rdx
  pushq %rsi
  pushq %rdi
  .section .data
  L2: .string "decrement"
  .section .text
  movq $format_str, %rdi
  movq $L2, %rsi
  movq $0, %rax
  call printf
  popq %rdi
  popq %rsi
  popq %rdx
  popq %rcx
  popq %rax
  movq x(%rip), %rax
  subq $1, %rax
  movq %rax, -16(%rbp)
  movq -16(%rbp), %rax
  movq %rax, x(%rip)
  jmp L0
L1:
  leave
  ret
