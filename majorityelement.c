#include<stdio.h>

int main()
{
	int arr[] = {1, 2, 2, 3, 4, 2, 4, 3, 2, 1, 2, 5, 2, 6, 2};
	int i, j, sz = sizeof(arr)/sizeof(arr[0]);
	int max = 1, found = 0;

	for(i=0;i<sz;i++)
	{
		for(j=i;j<sz-i;j++)
		{
			if(arr[i] == arr[j])
			max++;
		}
		if(max >= sz/2)
		{
			found = 1;
			printf("Majority Element found is =%d\n", arr[i]);
			break;
		}
		else
			max = 1;
		
	}
	if(found == 0)
		printf("Majority Element not found\n");
	return;
}
