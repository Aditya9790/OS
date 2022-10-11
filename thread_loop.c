#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

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
    pthread_t th[4];

    int i;
    pthread_mutex_init(&mutex, NULL); // set mutex lock

    for (i = 0; i < 4; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to connect error");
            return 1;
        }

        printf("Thread %d has started execytion.\n", i);
        /*
            At no point we have multithreading implemented
            if we run below code.


            if (pthread_join(th[i], NULL) != 0)
                return 2;
            printf("Thread %d has finished execution\n-", i);
        */
    }

    // First create all threads and then join 'tm individually
    for (i = 0; i < 4; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
            return 2;
          printf("Thread %d has finished execution\n", i);
    }

    pthread_mutex_destroy(&mutex); // destroy or unlocking the locked mutex

    printf("Mails : %d\n", mails);

    return 0;
}