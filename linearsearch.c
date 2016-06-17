#include <stdio.h>

int main()
{
    int arr[] = {2, 6, 9, 1, 3, 8, 4, 7, 5};
    int x, i, index, n = sizeof(arr)/sizeof(arr[0]);
    
    print("Enter the num(1-9) to find\n");
    scanf("%d", &x);
    
    for(i=0;i<n;i++)
    {
        if(arr[i] == x)
        {
            index = i;
            break;
        }
    }
    printf("num found at index=%d\n", index);
    return 0;
}
