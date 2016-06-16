#include<stdio.h>

void swap(int *x, int *y)
{
  int tmp;
  
  tmp = *x;
  *x = *y;
  *y = tmp
}

int main()
{
  int arr[] = {12, 43, 54, 76, 9, 50, 70, 10, 89, 5, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int i, j;
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(arr[j] > arr[j+1])
        swap(&arr[j], &arr[j+1]);
    }
  }
  
  for(i=0;i<n;i++)
    printf("%d, ", arr[i]);
  return 0;
}
