#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*print_numbers(void *arg)
{
	for (int i = 1; i <= 10; i++)
	{
		printf("Number: %d\n", i);
	}
	return (NULL);
}

void	*print_letters(void *arg)
{
	for (char c = 'A'; c <= 'C'; c++)
	{
		printf("Letter: %c\n", c);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t thread1, thread2;
	// Create two threads
	pthread_create(&thread1, NULL, print_numbers, NULL);
	pthread_create(&thread2, NULL, print_letters, NULL);
	// Wait for both threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Both threads finished!\n");
	return (0);
}
