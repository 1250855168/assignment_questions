#include <stdio.h>

int Is(int x)
{
    if (x == 1 || x == 2)
    {
        return 1;
    }
    return Is(x - 1) + Is(x - 2);
}

int main()
{

    printf("%d\n", Is(5));
    return 0;
}