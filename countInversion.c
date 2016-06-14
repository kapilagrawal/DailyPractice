#include<stdio.h>

int main()
{
    int a[] = {1, 20, 6, 4, 5};
    int i, j, n = sizeof(a)/sizeof(a[0]);
    int count = 0;

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
                count++;
        }
    }
    printf("Inversion count is = %d\n", count);
    return 0;
}
