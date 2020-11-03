#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
   pid_t pid,status;
   pid=fork();
   
if(pid==-1)
		printf("error in creating process");
	
   else if(pid==0)
    printf("\nI am child with id=%d",getpid());
 else
{
       sleep(5);
       printf("\nparent process Id=%d",getppid());
       printf("\nchild terminated Id=%d",pid);
       system("ps");
       pid=wait(&status);
       system("ps");
}
return(0);
}