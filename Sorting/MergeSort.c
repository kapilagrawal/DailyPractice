#include <stdio.h>

void Merge(int L[], int nl, int R[], int nr, int A[])
{
    int i = 0, j = 0, k = 0;
    
    while((i<nl) && (j<nr))
    {
        if(L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        A[k] = L[i];
        k++;
        i++;
    }
    while(j<nr)
    {
        A[k] = R[j];
        k++;
        j++;
    }
}

void MergeSort(int A[], int n)
{
    int mid, i;
    int nl, nr;
    
    if(n < 2) return;
    
    mid = n/2;
    
    nl = mid;
    nr = n - mid;
    
    int Left[mid];
    int Right[n - mid];
    
    for(i=0;i<mid;i++)
        Left[i] = A[i];
        
    for(i = mid;i<n;i++)
        Right[i-mid] = A[i];
    
    MergeSort(Left, nl);
    MergeSort(Right, nr);
    Merge(Left, nl, Right, nr, A);
}

printarray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
}

int main(void) 
{
	int arr[] = {2, 5, 7, 9, 1, 3, 4, 6, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	MergeSort(arr, n);
	printarray(arr, n);
	
	return 0;
}

