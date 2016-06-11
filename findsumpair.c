#include<stdio.h>

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int x, i, j, sz = sizeof(arr)/sizeof(arr[0]);
	int found = 0;
	printf("Enter the sum value\n");
	scanf("%d", &x);
	
	for(i=0;i<sz;i++)
	{
		for(j=0;j<sz;j++)
		{
			if(i == j) continue;
			
			if(arr[i] + arr[j] == x)
			{
				found = 1;
				break;
			}
		}
		if(found == 1)
		{
			printf("Found Pair[%d:%d] as Sum %d\n", arr[i], arr[j], x);
			return;
		}
	}
	if (found == 0) printf("None\n");
}
