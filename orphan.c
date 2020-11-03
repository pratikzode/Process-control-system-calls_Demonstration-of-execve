#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
pid_t pid,status;
pid=fork();
if(pid==-1)
		printf("error in creating process");
else if(pid!=0)
printf("\n Parent process id=%d",getppid());
else
{
	sleep(2);
	printf("\n Child id=%d",getpid());
}
return 0;
}