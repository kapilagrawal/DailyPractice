#include <stdio.h>

void swap(int *x, int *y)
{
    int tmp;
    
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int A[], int start, int end)
{
    int i;
    int pivot = A[end];
    int pIndex = start;
    
    for(i=start;i<end;i++)
    {
        if(A[i] < pivot)
        {
            swap(&A[i], &A[pIndex]);
            pIndex++;
        }
    }
    swap(&A[pIndex], &A[end]);
    return pIndex;
}

void QuickSort(int A[], int start, int end)
{
    int pIndex;
    if(start < end)
    {
        pIndex = partition(A, start, end);
        QuickSort(A, start, pIndex-1);
        QuickSort(A, pIndex+1, end);
    }
}

int main()
{
    int arr[] = {2, 6, 9, 1, 3, 8, 4, 7, 5};
    int i, n = sizeof(arr)/sizeof(arr[0]);
    int start = 0, end = n-1;
    
    QuickSort(arr, start, end);
    
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    return 0;
}
