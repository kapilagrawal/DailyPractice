#include <stdio.h>

int main(void) 
{
	int arr[] = {1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i, c=0;
	
	for(i=0;i<n;i++)
	{
	    if(arr[i] == 0) c++;
	}
	
	for(i=0;i<n;i++)
	{
	    if(i < c)
	        arr[i] = 0;
	    else
	        arr[i] = 1;
	}
	for(i=0;i<n;i++)
    printf("%d ", arr[i]);
	
	return 0;
}
