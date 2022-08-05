#include <stdio.h>

int main()
{
    int a[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        a[i] = 1;
    }
    unsigned short b = 0;
    for (int i = 0; i < 9; i++)
    {
        b |= 1 << (a[i] - 1);
    }
    printf("%d\n", b);
    int c[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        if (1 << (a[i] - 1) != b)
        {
            c[i] = i;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        /* code */
    }
    
    for (int i = 0; i < 9; i++)
    {
        if (c[i] == 0)
        {
            printf("可选%d\n",i);
        }
    }

    return 0;
}