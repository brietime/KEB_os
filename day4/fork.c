#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main()
{
	int pid;
	int counter =1;
	pid = fork();
	if(pid < 0)
	{
		fprintf(stderr, "Fork Failed.");
		exit(-1);
	}
	else if (pid ==0)
	{
		printf("child here!");
		while(counter <6)
		{	
			printf("child num: %d\n", counter);
			counter++;
			sleep(1);
		}
	}
	else
	{
		printf("i'm parent!");
		while(counter <6)
		{
			printf("parent num: %d\n", counter);
			counter++;
			sleep(1);
		}
		wait(NULL);
		printf("procerss complete!\n");
	}
	return 0;
}
