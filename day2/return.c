#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


void *threadRoutine(void* arg)
{
	long argument;
	argument = *((long *)arg);
	return (void*)(argument +100); //enter value from parent thread

}

int main()
{
	pthread_t threadID;
	printf("Create thread!\n");
	long argument = -1;
	int status;
	void *value;

	status = pthread_create(&threadID, NULL, threadRoutine, (void*)&argument);

	printf("MainThread is now waiting for Thread!\n");

	pthread_join(threadID, &value);

	printf("Return value (0; success) :: %d\n", status);
	printf("receive value :: %ld\n", (long)value);

	return 0;
}
