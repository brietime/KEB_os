#include<pthread.h>
#include<stdio.h>

void *threadRoutine(void *arg)
{
	int count = 0;
	pthread_t tid = pthread_self();
	// return TID and print
	printf("thread ID :: %lu\n", tid);
	while(count < 10000)
	{
		printf("a\n");
		count++;
	}
	return NULL;
}

int main()
{
	pthread_t threadID;
	char tmp[10];

	scanf("%s", tmp);
	pthread_create(&threadID,NULL, threadRoutine, NULL);

	scanf("%s", tmp);
		pthread_detach(threadID);
	
	while(1)
	{
		printf("b\n");
	}
}
