
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int total;
int partition(int numbers[],int left,int right)
{
  int pivot,Temp,pivotP=left;

  pivot = numbers[left++];
  while (left <= right)
  {
    while ((numbers[right] <= pivot) && (left <= right))
      right--;
    while ((numbers[left] > pivot) && (left <= right))
      left++;
    if(left<right)
    {
      Temp=numbers[right];
      numbers[right] = numbers[left];
      numbers[left]=Temp;
      left++;right--;
    }
  }
      if(pivotP!=right)
      {
      Temp=numbers[right];
      numbers[right] = numbers[pivotP];
      numbers[pivotP]=Temp;
      }
  pivot = right;
return pivot;
}

void quicksort(int numbers[], int left, int right)
{

  int i,pivot;
  static int Pass=1;
  pivot=partition(numbers,left,right);
  printf("\n Pass %2d: ",Pass++);
   for(i=0;i<total;i++)
    printf("%3d ",numbers[i]);
  if (left < pivot)
    quicksort(numbers, left, pivot-1);
  if (right > pivot)
    quicksort(numbers, pivot+1, right);
}
void partition1(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition1(a,low,mid);
		partition1(a,mid+1,high);
		merge(a,low,high,mid);
	}
}

int merge(int a[],int low,int high,int mid)
{
	int l,r,i,j,k,temp[20];
	l=low;
	i=low;
	r=mid+1;
	while(l<=mid && r<=high)
	{
		if(a[l]<a[r])
		{
			temp[i]=a[r];
			r++;
		}
		else
		{
			temp[i]=a[l];
			l++;
		}
		i++;

	}
	if(l>mid)
	{
		while(r<=high)
		{
			temp[i]=a[r];
			i++;
			r++;
		}
	}
	else
	{
		while(l<=mid)		
		{
			temp[i]=a[l];
			i++;
			l++;	
		}
	}

	for(i=low;i<=high;i++)
		a[i]=temp[i];
		return 0;
}	

int main()
{
 pid_t pid;
 int status;
 int a[10],i;
 printf("\nEnter Total Number of Element:");
 scanf("%d",&total);
 printf("\nEnter %d Element of Array",total);
 for(i=0;i<total;i++)
  scanf("%d",&a[i]);
 
 pid=fork();
 
 if(pid==-1)
 {
  printf("\nError");
 }
 else if(pid>0)
 {
  printf("\nParent Process");
  quicksort(a,0,total-1);
  sleep(2);
  printf("\n Parent Process Id:%d",getppid());
  //pid=wait(&status);
 }
 else
 {
  printf("\nChild Process");
  printf("\nChild Process Id: %d",getpid());
  partition1(a,0,total-1);
  printf("\n Sorted elements in child(mergesort) are:");
	for(i=0;i<total;i++)
		printf("\n%d",a[i]);
}
 return 0;
}