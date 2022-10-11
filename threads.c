#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void * myThreadFunc( void* tid)
{
	long *myId = (long *) tid;
	printf("Hello World!! This is thread %ld\n", *myId);
}	

int main()
{
	pthread_t tid0;
	pthread_create(&tid0, NULL, myThreadFunc, (void *)&tid0);

	pthread_exit(NULL); // waits wntil myThreadFunc has finished execution otherwise main quickly ecits and thread execution does not occur
	return 0;			  			
}
