#include<stdio.h>

int main()
{
    int i, j;
    int arr[] = {16, 17, 2, 4, 6, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(arr[j] >= arr[i])
                break;
        }
        if(j == n)
            printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
