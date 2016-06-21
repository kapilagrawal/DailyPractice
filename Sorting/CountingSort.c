#include <stdio.h>

countingsort(int A[], int n)
{
    int i;
    int C[14] = {0};
    int B[24] = {0};
    
    for(i=0;i<n;i++)
        C[A[i]] = C[A[i]] + 1;
    
    for(i=1;i<14;i++)
        C[i] = C[i-1] + C[i];
        
    for(i=0;i<n;i++)
        {
            B[C[A[i]] - 1] = A[i];
            C[A[i]] = C[A[i]] - 1;
        }
        
    for(i=0;i<n;i++)
    printf("%d ", B[i]);
}

int main()
{
  int i;
  int arr[] = {12, 11, 13, 5, 6, 7, 2, 3, 5, 4, 3, 2, 3, 4, 5, 2, 2, 1, 6, 6, 7, 10, 11, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
 
  countingsort(arr, n);
  
  return 0;
}
