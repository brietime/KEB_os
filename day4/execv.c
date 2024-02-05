#include<stdio.h>
#include<unistd.h>

int main()
{
//	int main(int argc, char *argv[])//pointer array, para number to get order para
	char *argv[] = {"ls", "-l", NULL};
	printf("execv start!\n");
	execv("/bin/ls", argv); // execv calls as pointer array, but ecl needs to call each para
//	execl("/bin/ls,"ls","-l",NULL")
	printf("if you read this message, fail creating execv func..\n");
//	if dont use execl, they dont cover present process, printf runs after system.
	return 0;
}

