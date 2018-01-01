This is the submission for lab3 of OS c-refresher-module.

(1) I studied on the internet that the C calling convention is the following:

- Push parameters of the function to stack in reverse order
- "call" instruction, which:
	stores the address of next instruction to stack
	jumps to called function address

- The callee function pushes rbp to stack and rsp to rbp
	This is done so that in nested calls, each levels stack pointer is preserved
- Pop the parameters from stack as required
	The parameters are starting from 8(%ebp)
	becuase we pushed 2 values to the stack

- before returning, callee restores esp from ebp, and ebo from stack (pop, and not just get)
- callee calls "ret" command which:
	restores the return address from the current top of stack
	jumps to this return address.
- the return value of the callee is in eax register.


(2) On studying the assembly code produced by gcc compiler 
for a simple C code calling a function from main, 
I found that:
- the pushing and popping to stack  is done by the callee function. 
- The caller function was putting the parameters to specific registers
	 - esi and edi for 2 parameters.
- The callee function then pushes these values to stack,
- And then continues as above.

So I implemented a much simpler assembly code using the latter (2).
I just added the esi and edi register values into eax
However the good practice of pushing the esi edi values to stack
then using the stack to get parameters and adding is added in comments.