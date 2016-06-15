#include <stdio.h>

int main(void) 
{
	int arr[] = {1, 2, 3, 4, 4, 4, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i, count = 0;
	int x = 4;
	
	for(i=0;i<n;i++)
	{
	    if(arr[i] == x)
	        count++;
	}
	
	if(count >= n/2)
	    printf("%d is present more that n/2 times\n", x);
	
	return 0;
}
