#include <stdio.h>

int main(void) 
{
	int arr[] = {12, 13, 1, 10, 34, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i, min1 = arr[0], min2 = arr[0];
	
	for(i=0;i<n-1;i++)
	{
	    if(arr[i+1] < min1)
	        min1 = arr[i+1];
	}
	
	for(i=0;i<n-1;i++)
	{
	    if((arr[i+1] > min1) && (arr[i+1] < min2))
	    {
	        min2 = arr[i+1];
	    }
	}
	printf("%d %d\n", min1, min2);
	return 0;
}
