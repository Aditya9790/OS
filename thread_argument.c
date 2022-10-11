#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{
    sleep(1);
    int index = *(int *)arg; // first cast the arg to int pointer and then dereference it
    printf("%d ", primes[index]);
    free(arg); // free the allocated memort in main 
}

int main()
{
    pthread_t th[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        /* due to multithreading unque values cannot be passed
                to tackle this we synamically allocate i every time
        */
        int *a = malloc(sizeof(int));
        *a = i; // at every iteration we allocate separate momory for a
        if (pthread_create(&th[i], NULL, &routine, a) != 0)
            perror("Failed to create thread.");
    }

    for (i = 0; i < 10; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
            perror("Failed to join");
    }
}