#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main(int argc, char const *argv[])
{

	
	char *cwd = NULL;
	int err;
	printf("%s\n", getcwd(cwd,0));


	char * args[10] = {"cd","./abc"};
	char home[] = "/home/cosmopal";
	if (*args[1]=='~'){
				char * orig = args[1];
				orig++;
				args[1] = strcat(home,orig);
				printf("%s\n", args[1]);
			}

	char * abs_path = (char *)malloc(PATH_MAX * sizeof(char));
	realpath(args[1],abs_path);
	err = errno;
	printf("abs path %s\n", abs_path);
	printf("args[1] = %s\n", args[1]);
	printf("Error: %s\n", strerror(err));


	int stat = chdir(args[1]);

	printf("%s %d\n", getcwd(cwd,0), stat);
	return 0;
}