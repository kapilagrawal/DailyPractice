#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int key, n = sizeof(arr)/sizeof(arr[0]);
    int mid, start = 0, end = n - 1;

    printf("Enter the key to be searched\n");
    scanf("%d", &key);


    while(start <= end)
    {
        mid = (start + end)/2;

        if(arr[mid] == key)
        {
            printf("Key is at index = %d\n", mid);
            return;
        }
        else if(arr[mid] > key)
        {
            end = mid - 1;
        }
        else // (arr[mid] < key)
        {
            start = mid + 1;
        }
    }
    return 0;
}
