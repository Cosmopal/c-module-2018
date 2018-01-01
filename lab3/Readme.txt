This is the submission for lab3 of OS c-refresher-module.

There seems to be an intelligent decision
in gcc compiler whichoptimizes the arm code,
but makes understanding calling convention 
tricky in gcc complied assembly.

I implemented a much simpler assembly code using this (2).
I just added the esi and edi register values into eax

=> However the good practice of pushing the esi edi values to stack
then using the stack to get parameters and adding is added in comments.



Details below:



(1) I studied on the internet that the C calling convention is the following:

Caller Subroutine:

- Save caller-saved marked registers - EAX, ECX, EDX
- Push parameters of the callee function to stack in reverse order
- "call" instruction, which:
	stores the address of next instruction to stack
	jumps to called function address


Callee Subroutine: 

- The callee function pushes rbp to stack and rsp to rbp
	This is done so that in nested calls, each levels base pointer is preserved
- Save callee-saved marked registers - EBX, ESI, EDI
- Access the parameters from stack as required
	The parameters are starting from 8(%ebp)
	becuase we pushed 2 values to the stack

- before returning, callee restores esp from ebp, and ebp from stack (pop, and not just get)
- callee calls "ret" command which:
	restores the return address from the current top of stack
	jumps to this return address.
- the return value of the callee is in eax register.


(2) On studying the assembly code produced by gcc compiler 
for a simple C code calling a function from main, 
I found that:
- the pushing to stack is done by the callee function. 
- The caller function was putting the parameters to specific registers
	 - esi and edi for 2 parameters.
- The callee function then pushes these values to stack,
- And then continues as above.

The reason seems to be that, the compiler is intelligent enough
to see that "Hey, if the callee is as it is going to push values
to th stack (callee saved registers), which are empty otherwise,
why not put the paramters in these registers, instead of doing extra,
and expensive, memory operations?"

Because of this, the 2 parameters we require are in esi and edi.

So I implemented a much simpler assembly code using the latter (2).
I just added the esi and edi register values into eax

=> However the good practice of pushing the esi edi values to stack
then using the stack to get parameters and adding is added in comments.