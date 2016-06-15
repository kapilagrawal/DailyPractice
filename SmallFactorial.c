#include<stdio.h>

int fact(int x)
{
    int y, i, carry = 0, tmp, m = 0;
    int a[200] = {0};

    if(x > 100) return;

    if(x == 100)
    {
        a[0] = 0;
        a[1] = 0;
        a[2] = 1;
        m = 3;
    }
    else if(x > 9)
    {

        a[0] = x % 10;
        a[1] = x / 10;
        m = 2;
        printf("Num in array--%d %d %d\n", a[0], a[1], m);
    }
    else
    {
        a[0] = x;
        m = 1;
    }

    while(x > 1)
    {
        printf("Num=%d cnt in array=%d carry = %d\n", x, m, carry);
        for(i = 0; i < m; i++)
        {
            y = a[i];
            a[i] = (y * (x - 1) + carry) % 10;
            carry = (y * (x - 1) + carry) / 10;
            printf("Pass->%d -- a[%d]=%d, carry=%d\n", m, i, a[i], carry);
        }
        if(carry)
        {
            while(carry != 0)
             {
                tmp = carry % 10;
                carry = carry / 10;
                a[i] = tmp;
                //carry = 0;
                m++;
                printf("In Carry->%d -- a[%d]=%d\n", m, i, a[i]);
                i++;
            }
        }
        x--;
    }

    for(i=m-1;i>=0;i--)
        printf("%d", a[i]);
    printf("\n");
}

int main()
{
    int t, i;
//  scanf("%d", &t);
//  int n[t], z[t];
scanf("%d", &i);
fact(i);
/*  for(i=0;i<t;i++)
    {
        scanf("%d", &n[i]);
    }

    for(i=0;i<t;i++)
    {
        z[i] = fact(n[i]);
    }
    for(i=0;i<t;i++)
    {
        printf("%d\n", z[i]);
    }
*/  return 0;
}
