#include<stdio.h>

int main()
{
	int m[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	int n = 4; 
	int i, j, tmp;

	for(i=0;i<n/2;i++)
	{
		for(j=i;j<n-i-1;j++)
		{
			tmp =m[i][j];
			m[i][j] = m[n-j-1][i];
			m[n-j-1][i] = m[n-i-1][n-j-1];
			m[n-i-1][n-j-1] = m[j][n-i-1];
			m[j][n-i-1] = tmp;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	return 0;
}
