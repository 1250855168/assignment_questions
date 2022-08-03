#include <stdio.h>
/**
 * @brief 判断一组数字是否有序
 * 
 * @param p 
 */
void Is(int p[10])
{
    int flage = 0;
    if (flage == 0)//判断升序
    {
        for (int i = 0; i < 9; i++)
        {
            if (p[i] > p[i + 1])
            {
                flage = 1;
            }
            else
            {
                flage = 0;
            }
        }
    }
    if (flage == 0)//判断相等
    {
        for (int i = 0; i < 9; i++)
        {
            if (p[i] == p[i + 1])
            {
                flage = 1;
            }
            else
            {
                flage = 0;
            }
        }
    }
    if (flage == 0)//判断降序
    {

        for (int i = 0; i < 9; i++)
        {
            if (p[i] < p[i + 1])
            {
                flage = 1;
            }
            else
            {
                flage = 0;
            }
        }
    }
    if (flage == 1)
    {
        printf("有序！\n");
    }
    else
    {
        printf("无序！\n");
    }
}

int main()
{
    int a[10];
    for (int i = 9; i <=0; i--)
    {
        a[i] = i;
    }
    Is(a);

    return 0;
}