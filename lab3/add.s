# Assmebly code for add function
# eax will have return values
# ecx will have op1
# edx op2
# register is 64 bit, int is 32 bit, so ecx instead of rcx

.section .text
.globl my_add
.type my_add,@function

my_add:
#pushq %rbp
#movq %rsp, %rbp

# movl %edi, -8(%rbp)
# movl %esi, -12(%rbp)
# movl -8(%rsp), %ebx
# movl -12(%rsp), %eax
# addl %ebx, eax
movl $0, %eax
addl %edi, %eax
addl %esi,%eax

# movq %rbp, %rsp
# popq %rbp
ret
