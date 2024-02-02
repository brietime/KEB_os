#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


void *join_thread(void *arg)
{
	printf("%d thread\n", arg);
	pthread_exit(arg); //print numberand exit
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	int arg, status;
	void *result;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: join thread<number>\n");
		exit(1);
	}
	arg = atoi(argv[1]);
	printf("%d\n", arg);
//waiting for threads exit
	status = pthread_create(&tid, NULL, join_thread, (void *) arg);
	if(status != 0)
	{
		fprintf(stderr, "Join thread: %d", status);
		exit(1); //thread fail =exit
	}

	printf("join\n");
	
	return (int)result;
}
