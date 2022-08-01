#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
 * @brief 找素数 如果本身不是素数 返回最近的素数 如果两个最近返回两个
 *
 * @param x
 * @return int
 */
int Found_p(int x)
{
    int i;
    for (i = 2; i < x / 2; i++) //判断本身是不是素数
    {
        if (x % i == 0)
        {
            break;
        }
    }
    if (x / 2 <= i)
    {
        printf("%d", x);
        return x;
    }
    int temp1;
    int x1 = x;
    int j;
    for (i = 1; i < 5; i++) //向上去值 判断素数
    {
        x1 = x + i;
        for (j = 2; j < (x1 + i) / 2; j++)
        {
            if (x1 % j == 0)
            {
                break;
            }
        }
        if ((x1 + i) / 2 <= j)
        {
            temp1 = x1;
            break;
        }
    }
    int x2 = x;
    int temp2;
    int n;
    for (i = 1; i < 5; i++) //向下取值  判断素数
    {
        x2 = x - i;
        for (n = 2; n < (x2 - i); n++)
        {
            if (x2 % n == 0)
            {
                break;
            }
        }
        if ((x2 - i) / 2 <= n)
        {
            temp2 = x2;
            break;
        }
    }
    if (temp1 == 0 || (x - temp2) < (temp1 - x))
    {
        printf("%d\n", temp2);
    }
    else if (temp2 == 0 || (x - temp2) > (temp1 - x))
    {
        printf("%d\n", temp1);
    }
    else if ((x - temp2) == (temp1 - x))
    {
        printf("%d\n", temp1);
        printf("%d\n", temp2);
    }
}
/**
 * @brief 把一个有相同字符和空格的字符串变成没有相同字符没有空格的字符串
 *
 * @param p
 */
void str1(const char *p)
{
    char *p1 = malloc(sizeof(char));
    *p1 = *p;
    int x = 0;
    for (int i = 1; *(p + i) != '\0'; i++) //去空格
    {
        if (*(p + i) != ' ')
        {
            p1 = realloc(p1, strlen(p1) + 1); //扩容
            (*(p1 + (++x)) = *(p + i));
        }
    }
    p1 = realloc(p1, strlen(p1) + 1); //扩容
    *(p1 + (++x)) = '\0';             //加结束符
    puts(p1);
    x = 0;
    char *p2 = malloc(sizeof(char));
    *p2 = *p;
    for (int i = 0; *(p1 + i) != '\0'; i++) //去相同的字符串
    {
        if (*(p1 + i) != *(p1 + i + 1))
        {
            p2 = realloc(p2, strlen(p2) + 1); //扩容
            *(p2 + (++x)) = *(p1 + i + 1);
        }
    }
    p2 = realloc(p2, strlen(p2) + 1); //扩容
    *(p2 + (++x)) = '\0';             //加结束符
    free(p1);                         //释放P1的空间
    p1 = NULL;
    puts(p2);
    free(p2); //释放P2的空间
    p2 = NULL;
}
/**
 * @brief 寻找 购买商品和目前的钱最匹配的状态 每种商品只有0/1次
 * 
 * @param Goods 商品样式的钱
 * @param money  身上的钱
 */
void Sta(int Goods[5], int money)
{
    int temp = 0;
    int t = _MAX_ENV;
    int b[5] = {0};
    for (int i = 1; i < 32; i++)//所有的情况
    {
        int a[5] = {0};
        a[0] = !!(i & (1 << 4));
        a[1] = !!(i & (1 << 3));
        a[2] = !!(i & (1 << 2));
        a[3] = !!(i & (1 << 1));
        a[4] = !!(i & (1 << 0));
        int sum = Goods[0] * a[0] + Goods[1] * a[1] + Goods[2] * a[2] + Goods[3] * a[3] + Goods[4] * a[4];
        temp = abs(money - sum);//只考虑最匹配 不考虑商品价格超过钱
        if (temp < t)
        {
            for (int j = 0; j < 5; j++)
            {
                b[j] = a[j];//给商品的情况保存下来
            }
            t = temp;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d", b[i]);//打印情况
    }
    printf("\n");//打印最终花的钱
    int s = Goods[0] * b[0] + Goods[1] * b[1] + Goods[2] * b[2] + Goods[3] * b[3] + Goods[4] * b[4];
    printf("%d\n", s);
}

int main()
{

    int Goods[5] = {12, 13, 15, 16, 17};
    int moeny = 60;
    Sta(Goods, moeny);
    return 0;
}