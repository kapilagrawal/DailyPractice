#include <stdio.h>

void swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int i, j;
    int n = sizeof(arr)/sizeof(arr[0]);

    for(i=0;i<n-1;i++)
    {
        j = i+1;
        while((arr[j] < arr[j-1])&&(j > 0))
        {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }

    for(i=0;i<n;i++)
        printf("%d, ", arr[i]);
    printf("\n");
    return 0;
}
