#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct T
{
    int x1, y1;
    int x2, y2;
    int x3, y3;
} T;

int Max(int x1, int x2, int x3)
{
    if (x1 < x2)
    {
        x1 = x2;
        if (x1 < x3)
        {
            x1 = x3;
        }
    }
    else if (x1 < x3)
    {
        x1 = x3;
    }
    return x1;
}

int Min(int x1, int x2, int x3)
{
    if (x1 > x2)
    {
        x1 = x2;
        if (x1 > x3)
        {
            x1 = x3;
        }
    }
    else if (x1 > x3)
    {
        x1 = x3;
    }
    return x1;
}

void X()
{
    T t;
    printf("请输入第一个点：\n");
    scanf("%d%d", &t.x1, &t.y1);
    printf("请输入第二个点：\n");
    scanf("%d%d", &t.x2, &t.y2);
    printf("请输入第三个点：\n");
    scanf("%d%d", &t.x3, &t.y3);
    int X_Max = Max(t.x1, t.x2, t.x3);
    int X_Min = Min(t.x1, t.x2, t.x3);
    int Y_Max = Max(t.y1, t.y2, t.y3);
    int Y_Min = Min(t.y1, t.y2, t.y3);
    int S = abs(t.x1 * t.y2 + t.x2 * t.y3 + t.x3 * t.y1 - t.x1 * t.y3 - t.x2 * t.y1 - t.x3 * t.y2);
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    int x = 0;
    int j;
    int *array=NULL;
    int c = 0;
    for (int i = X_Min; i <= X_Max; i++)
    {
        j = Y_Min;
        for (; j <= Y_Max; j++)
        {
            temp1 = abs(i * t.y2 + t.x2 * t.y3 + t.x3 * j - i * t.y3 - t.x2 * j - t.x3 * t.y2);
            temp2 = abs(t.x1 * j + i * t.y3 + t.x3 * t.y1 - t.x1 * t.y3 - i * t.y1 - t.x3 * j);
            temp3 = abs(t.x1 * t.y2 + t.x2 * j + i * t.y1 - t.x1 * j - t.x2 * t.y1 - i * t.y2);
            if ((temp1 + temp2 + temp3) == S)
            {
                c += 2;
                array = realloc(array, sizeof(int) * c);
                array[x++] = i;
                array[x++] = j;
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        printf("%d ", array[i]);
        if ((i + 1) % 2 == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
    X();
    return 0;
}