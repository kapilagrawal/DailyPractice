#include <stdio.h>
#include <string.h>

int main()
{
  int i, j, sum, Maxsum = 0, index_start, index_end;
  int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n = sizeof(A)/sizeof(A[0]);
  
  for(i=0;i<n;i++)
  {
      sum = 0;
      for(j=i;j<n;j++)
      {
          sum = sum + A[j];
          if(Maxsum < sum)
          {
            Maxsum = sum;
            index_start = i;
            index_end = j;
          }
      }
  }
  printf("%d\n", Maxsum);
  for(i=index_start;i<=index_end;i++)
  {
      printf("%d, ", A[i]);
  }
  printf("\n");
  
 return 0;
}
