#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
int main(int argc, char const *argv[])
{

	// char * inbuilt_funs[2] = {"cd","exit"};

	char *cwd = NULL;
	char *line = NULL;
	int err;
	char home[] = "/home/cosmopal";
	int stat= 0;


	while (1){

		// line = (char* )malloc (50 * sizeof(char));
		// cwd = (char *)malloc(50*sizeof(char));

	printf("%s>> ", getcwd(cwd,0));

	//Read input
	// *line = NULL;
	size_t size = 0;
	getline(&line, &size, stdin);

	//Parse input
	int pos = 0;
	int NUM_ARGS = 10;
	char * args[NUM_ARGS];
	char *arg;

	// printf("got input %s\n", line);

	char delimiter[] = " \n";
	arg = strtok(line,delimiter);
		// printf("arg is %s\n", arg);
	while (arg!=NULL){
		// printf("arg is %s\n", arg);
		args[pos++] = arg;
		arg = strtok(NULL,delimiter);
	}
	args[pos] = NULL;

	int inbuilt = 0;
	
	
	
	
	// printf("%s\n", args[0]);
	//Check for inbuilt functions:
	if (strcmp(args[0],"cd") == 0){

		//cd:

		inbuilt = 1;
		char * temp;
		if (args[1] == NULL)
			args[1] = home;
		if (*args[1]=='~'){
			temp = args[1];
			temp++;
			args[1] = strcat(home,temp);
		}
		temp = (char * )malloc(PATH_MAX* sizeof(char));
		// realpath(args[1],temp);
		// printf("path is %s\n", args[1]);

		stat = chdir((char *)args[1]);
		err = errno;
		if (stat != 0){
			printf("Error: %s\n", strerror(err));
		}
	// printf("%s %d\n", getcwd(cwd,0), stat);

	}

	else if (strcmp(args[0],"exit") == 0){
		// printf("exiting\n");
		exit(EXIT_SUCCESS);
	}

	if (inbuilt){
		continue;
	}
	else{
		// printf("Not inbuilt\n");
	}


	//Fork and execute inside child
	int pid = fork();

	if (pid ==0){
		//Child process
		if (execvp(args[0],args) <0){
			printf("Error executing function %s\n", args[0]);
		}
		exit(-1);
	}
		else if (pid < 0){
			//Failure in forking
			printf("Error Forking\n");
		}
		else{
			//Parent process waits till its child pid terminates
			//Can use wait(&stat) also, but that would include any and all children of the current process.
			waitpid(pid,&stat, 0);
		}


		free (line);
		free (cwd);

	}



	// printf("%s\n", line );
	// return 0;
}
