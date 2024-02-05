#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main()
{
	int pid;
	int counter =1;
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr, "Fork Failed");//select file and printf, but now its default error out
		exit(-1);//exit cuz error occur
	}
	else if(pid == 0)
	{//if child =0 , parrent = child pid
		printf("child here!\n");
		printf("execl start!\n");//child  call exec before exit
		//it means child call exec and cover itself
		execl("/bin/ls","ls", "-l", NULL);
		printf("if you read this message, fail creating execl func.\n");
	}
	else
	{
		printf("i'm parent!\n");
		wait(NULL);//parent waits for child exec exits
		printf("process Complete!\n");
	}
	return 0;
}

