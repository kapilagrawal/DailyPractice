#include <stdio.h>
#include <string.h>

int main()
{
  int i;
  char A[] = "geeksforgeeks";
  
  int n = strlen(A);
  int C[256] = {0};
 
  char B[14] = {0};
    
    for(i=0;i<n;i++)
        C[A[i]] = C[A[i]] + 1;
    
    for(i=1;i<256;i++)
        C[i] = C[i-1] + C[i];
        
    for(i=0;i<n;i++)
        {
            B[C[A[i]] - 1] = A[i];
            C[A[i]] = C[A[i]] - 1;
        }
        
    printf("%s", B);
  
 return 0;
}
