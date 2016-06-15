#include <stdio.h>

int main(void) 
{
	int arr[] = {1, 60, -10, 70, -80, 85};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i, j, min = arr[0] + arr[1];
	int x, y;
	
	for(i=0;i<n-1;i++)
	{
	    for(j=i+1;j<n;j++)
	    {
	        if(abs(min) > abs(arr[i]+arr[j]))
	        {
	            min = arr[i]+arr[j];
	            x = i;
	            y = j;
	        }
	    }
	}
	
	printf("%d %d\n", arr[x], arr[y]);
	return 0;
}
