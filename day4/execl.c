#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
//	int main(int argc, char *argv[])//pointer array, para number to get order para
	printf("execl start!\n");
	execl("/bin/ls", "ls", "-l", NULL);
//	system("/bin/ls -1");
//	func system get name of process and call process
//	int system(const char *argv); //if fail 0, success plus num return
	printf("if you read this message, fail creating execl func..\n");
//	if dont use execl, they dont cover present process, printf runs after system.
	return 0;
}
