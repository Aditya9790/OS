#include<stdio.h> 
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t locked;

int a;

void *procfunc()
{
	pthread_mutex_lock(&locked);

	int i = 0;
	a++;
	printf("Started...\n");
 	while(i < 6)
	{
		printf("%d\n", a);
		sleep(3);
		i++;
	}
	printf("Finished...\n");

	pthread_mutex_unlock(&locked);
}

int main()
{
	int error;
	pthread_t th1;
	pthread_t th2;

	if(pthread_mutex_init(&locked, NULL) != 0)
	{
		printf("Mutex creation was unsuccessful!!");
		exit(1);
	}
	a = 0;
	pthread_create(&th1, NULL, procfunc, NULL);
	pthread_create(&th1, NULL, procfunc, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	return 0;
}
