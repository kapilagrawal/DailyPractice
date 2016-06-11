#include<stdio.h>
#include<string.h>

int main()
{
	//int a[10] = {1,1,2,2,3,3,3,4,5,6};
	int a[10] = {1,1,1,1,1,1,1,1,1,1};
	//int a[10] = {1,2,3,4,5,6,7,8,9,10};
	//int a[10] = {1,2,1,2,3,4,3,4,5,6};
	int i, j, k;
	int n = sizeof(a)/sizeof(int);
	
	for(i=0;i<n;i++)
	{
		printf("a[i]=%d\n", a[i]);
		for(j=i+1;j<n;j++)
		{
		printf("a[j]=%d\n", a[j]);
			if(a[i] == a[j])
			{
		printf("Found Match->a[i]=%d\n", a[i]);
				for(k=j;k<n;k++)
					a[k] = a[k+1];
				j--;
				n--;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ", a[i]);

	return 0;
}

