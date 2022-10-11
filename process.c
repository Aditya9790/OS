#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>

/*
void forkexample()
{
	if(fork()==0)
		printf("Hello from child.\n");
	else
		printf("Hello from parent.\n");
}
*/

int main()
{

	int x = 2;
	int pid = fork();
	if (pid == -1)
		return 1;
	if (pid == 0) // for child process
	{
		x++; // if in child process then increment
	}

	sleep(2);

	printf("value of x :%d\n", x);
	printf("Process id: %d\n", getpid());
	
	if (pid != 0)
		wait(NULL);

	return 0;
}
