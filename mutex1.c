#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*

Race condition occurs when two or more threads try to access a
single memory location

 Here after 1000000 iterations we face this issue
 
*/

int mails = 0;
// int lock = 0;

pthread_mutex_t mutex;

void *routine()
{
	for (int i = 0; i < 900000; i++)
	{

		/*
		 Below code blovk is executed by pthread_mutex_lock
		if(lock == 1){
			// wait until the lock is 0
		}
		lock = 1;
		*/
		pthread_mutex_lock(&mutex); // set lock
		mails++;
		//	lock = 0;
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t p1, p2;

	pthread_mutex_init(&mutex, NULL); // set mutex lock

	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return 1;

	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return 2;

	if (pthread_join(p1, NULL) != 0)
		return 3;

	if (pthread_join(p2, NULL) != 0)
		return 4;

	pthread_mutex_destroy(&mutex); // drdtroyer or unlocking tje locked mutex

	printf("Mails : %d\n", mails);

	return 0;
}
