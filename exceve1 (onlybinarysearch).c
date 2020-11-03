#include<stdio.h>
#include<math.h>
#include<sys/types.h>

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
   // We reach here when element is not present in array
   return -1;
}

int main(int argc, char *argv[])
{
	int n, result;
	int val[50], i, j;
	for(i=0, j=0; i<argc; i++, j++)
	{
		val[j]=atoi(argv[i]);
	}
		
	printf("\n**BINARY SEARCH**\n\nEnter The Number to be Searched: ");
	scanf("%d", &n);
	result = binarySearch(val, 0, argc-1, n);
	
(result == -1)? printf("Oops!! Element is not present..\n\n")
                 : printf("Element Present!!\nIndex: %d\n\n", result);
	return 0;	
}