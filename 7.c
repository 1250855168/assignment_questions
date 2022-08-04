#include <stdio.h>

int f(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    return f(n - 1) + f(n - 2);
}

void output(char *ch)
{
    if (*ch == '\0')
    {
        return;
    }
    output(ch + 1);
    putchar(*ch);
}

int main()
{
    output("sdfasdfs");
    return 0;
}