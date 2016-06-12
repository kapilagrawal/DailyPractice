#include<stdio.h>

void rotateleft(int arr[], int n, int d)
{
	int i = 0;
	for(i=0;i<d;i++)
	{
		tmp = arr[i];
		for(j=0;j<n-1;j++)
		{
			arr[j] = arr[j+1];
		}
		arr[j] = tmp;
	}
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	rotateleft(arr, 9, 2);
	for(i=0;i<9;i++)
		printf("%d ", arr[i]);
	return 0;
}
