#include <stdio.h>

extern int my_add(int a, int b);
// extern int my_add_ptrs(int* a, int* b);

int main(int argc, char const *argv[])
{
	int op1 = 21;
	int op2 = 22;
	// int p3 = 12;
	// int a4 = 1314;

	printf("Sum is = %d\n", my_add(op1,op2));
	// printf("Sum is = %d\n", my_add_ptrs(&op1,&op2));
	return 0;
}