#include<stdio.h>

int main()
{
  int rotarr[] = {6, 7, 8, 9, 1, 2, 3, 4, 5};
  int len = sizeof(rotarr)/sizeof(rotarr[0]);
  int start = 0;
  int end = len - 1;
  int mid, item;
  printf("Enter the item to be searched (in range [1..9])\n");
  scanf("%d", item);
  
  while(start < end)
  {
    mid = (start+end)/2;
    if (rotarr[mid] == item)
    {
      printf("Item is at index %d\n", mid);
      return;
    }
    if(rotarr[mid] > rotarr[start])
    {
      if(item > rotarr[start] && item < rotarr[mid)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    else
    {
      if(item > rotarr[mid] && item < rotarr[end)
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }//else
  }//while
  printf("Item not found\n");
  return;
}//main
