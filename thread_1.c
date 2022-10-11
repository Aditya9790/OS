#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int a = 0;
void *func(void *var)
{
	int *id = (int *)var;
	static int b = 0; // to observe change
	b = 7;
	a = 7;

	printf("the id of thread id :%d\n", *id);
	printf("the value of static static variable is :%d\n", b);
	printf("the value of global variable is :%d\n", a);
}

int main()
{
	pthread_t th_id;
	//	pthread_t tid;
	/*
	printf("Before execution of thread\n");
	pthread_create(&tid, NULL, func, NULL);
	pthread_join(tid, NULL); // equivalent to sleep function

	printf("After execution of thread\n");
	*/

	for (int i = 0; i < 2; i++)
	{
		pthread_create(&th_id, NULL, func, (void *)&th_id);
	}

	pthread_exit(NULL);

	//	exit(0);
	return 0;
}
