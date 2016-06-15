#include <stdio.h>

int main(void) 
{
	int arr[] = {1000, 11, 445, 1, 330, 3000};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i, min = arr[0], max = arr[0];
	
	for(i=0;i<n-1;i++)
	{
	    if(arr[i+1] < min)
	        min = arr[i+1];
	    if(arr[i+1] > max)
	        max = arr[i+1];
	}
	
    printf("min=%d max=%d\n", min, max);
	
	return 0;
}
