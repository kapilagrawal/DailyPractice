#include<stdio.h>

int main()
{
    int i;
    int arr[] = {16, 17, 2, 3, 4, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(i = n-1; i > 0; i--)
    {
        if(arr[i] < arr[i-1])
        {
            printf("%d ", arr[i-1]);
        }
    }
    printf("\n");
    return 0;
}
