#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

// get return vaue from a thread

void *roll_dice()
{
	int value = (rand() % 6) + 1;

	int *result = malloc(sizeof(int)); // create another pointer as
									   // refrencing local variable will not work

	// printf("%d\n", value);

	*result = value;
	// printf("Thread result is :\t%p\n", result);
	return (void *)result;
}

int main()
{
	int *res, i, n = 100;

	srand(time(NULL));
	pthread_t th[n];

	// if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
	// 	return 1;

	// // Arguments of pthread_join are thread and a void pointer
	// if (pthread_join(th, (void **)&res) != 0)
	// 	return 2;

	// printf("Main result is :\t%p\n", res);
	// printf("Result : %d\n", *res);
	// free(res);

	for (i = 0; i < n; i++)
	{
		if (pthread_create(&th[i], NULL, &roll_dice, NULL) != 0)
			return 1;
	}

	for (i = 0; i < n; i++)
	{
		if (pthread_join(th[i], (void **)&res) != 0)
			return 2;

		printf("Result for dice %d is : %d\n", i+1, *res);
		free(res);
	}
	return 0;
}
