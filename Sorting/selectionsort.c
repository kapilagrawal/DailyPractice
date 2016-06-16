#include<stdio.h>

void swap(int *p, int *q)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}
int main()
{
    int i, j, min, index;
    int arr[] = {19, 7, 14, 67, 8, 93, 69, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sort\n");

    for(i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    for(i = 0; i < n-1; i++)
    {
        min = arr[i];
        index = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        printf("\nswaping=%d & %d\n", arr[index], arr[i]);
        swap(&arr[index], &arr[i]);
    }
    printf("After sort\n");
    for(i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}
