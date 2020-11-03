
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

void quicksort(int a[20],int lb,int ub, int n)
{
	int down,up,pivot,temp,k;

	pivot=a[lb];
	down=lb; 
	up=ub;

	if(lb<ub)	
	{
		while(down<up)
		{
			while(a[down]<=pivot)	
				down++;
			while(a[up]>pivot)	
				up--;

			if(down<up)
			{
				temp=a[down];
				a[down]=a[up];
				a[up]=temp;
			}
		}//end of outer while

		a[lb]=a[up];
		a[up]=pivot;

		quicksort(a,lb,up-1,n);
		quicksort(a,up+1,ub,n);

	}//end of outer if

}//end of quicksort()


int main(int argc, char *argv[])
{
	pid_t pid;
	int val[50], i, j;
	char *charArr[50];
	char buffer[4];

	printf("\n**START**\nArray: ");

	for(i=1, j=0; i<argc; i++, j++)
	{
		val[j]=atoi(argv[i]);
	}
	
	for(i=0;i<argc-1;i++)
	{
		printf("%d ", val[i]);
	}
	
	printf("\n\n**QUICK SORT**\n");
	quicksort(val,0,argc-2, argc-1);

	printf("\nArray after Quick sorting: ");
	for(i=0;i<argc-1;i++)
		printf(" %d",val[i]);

	for(i=0; i<argc-1; i++)
	{
		sprintf(buffer, "%d", val[i]);
		charArr[i]=(char*)malloc(sizeof(buffer));
		strcpy(charArr[i], buffer);
	}
	charArr[i]=NULL;	

	printf("\nArray after Conversion: ");
	for(i=0; i<argc-1; i++)
		printf("%s ", charArr[i]);
	printf("\n");
	
	pid=fork();
	if(pid<0)
	{
		printf("Error in fork");
	}
	
	else
	{
		if(pid==0)
		{						
			execv("new",charArr);
			perror("execv"); //if this is executed error in program
			printf("\n End Of Program \n");
		}
		else
		{
			sleep(10);
		}
	}		
	return 0;

}
