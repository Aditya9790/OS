#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


/*
 * race condition occurs when two or more threads try to access a 
 * single memory location

 * Here after 1000000 iterations we face this issue
 *
 */
int mails = 0;
void *routine()
{
	for(int i = 0;i<10000000;i++) mails++;
}

int main()
{
	pthread_t p1, p2;
	
//	int a;
//	scanf("%d", &a);
	if(pthread_create(&p1, NULL, &routine, NULL) != 0) return 1;

	if(pthread_create(&p2, NULL, &routine, NULL) != 0) return 2;

	if(pthread_join(p1, NULL) != 0) return 3;

	if(pthread_join(p2, NULL) != 0) return 4;

	printf("Mails : %d\n", mails);

	return 0;
}
