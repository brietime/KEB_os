#include<pthread.h>
#include<stdio.h>

void *threadRoutine(void *arg)
{
	int count = 0;
	pthread_t tid = pthread_self();
	// return TID and print
	printf("thread ID :: %lu\n", tid);
	while(count < 100)
	{
		printf("a\n");
		count++;
	}
	pthread_exit(arg);
}

int main()
{
	pthread_t threadID;
	int status;
	void *result;
	char tmp[10];

	scanf("%s", tmp); //stop process to see pstree
	pthread_create(&threadID,NULL, threadRoutine, NULL);
	//defach thread i made
	scanf("%s", tmp); //also stop~

	status = pthread_join(threadID, &result);
	if(status != 0)
	{
		exit(1);
	} 

	while(1)
	{
		printf("b\n");
	}
}
