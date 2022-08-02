


/**
 * @file 2.c
 * @author your name (you@domain.com)
 * @brief   不能是小数 可以改成double 实现小数
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Square
{
    int x1;
    int y1;
    int x2;
    int y2;
} Square;

int height(int y1, int y2, int y3, int y4) // y1,y2是右下 y3，y4是左上
{
    int a = y1 > y2 ? y1 : y2;
    int b = y3 < y4 ? y3 : y4;
    return abs(a - b);
}
int wight(int x1, int x2, int x3, int x4) // x1.x2是右下 x3,x4是左上
{
    int a = x1 < x2 ? x1 : x2;
    int b = x3 > x4 ? x3 : x4;
    return abs(a - b);
}

int CrossLine(Square square1,Square square2)
{
    float w1 = square1.x2 - square1.x1;
    float h1 = square1.y1 - square1.y2;
    float w2 = square2.x2 - square2.x1;
    float h2 = square2.y1 - square2.y2;
    float w = abs((square1.x1+square1.x2)/2-(square2.x1+square2.x2)/2);
    float h = abs((square1.y1+square1.y2)/2-(square2.y1+square2.y2)/2);
 
    if( w < (w1 + w2)/2 && h < (h1 + h2)/2)
        return 1;
    else
        return 0;
}

void F()
{
    printf("please input N number square:");
    int n;
    scanf("%d", &n);
    Square *square = malloc(sizeof(Square) * n);
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        printf("请输入左上角坐标\n");
        scanf("%d", &square[i].x1); //左上角坐标
        scanf("%d", &square[i].y1);
        printf("请输入右下角坐标\n");
        scanf("%d", &square[i].x2); //右下角坐标
        scanf("%d", &square[i].y2);
    }
    for (int j = 0; j < n - 1; j++)
    {

        for (int i = j; i < n - 1; i++)
        {//计算相交的结果
            if (CrossLine(square[j],square[i+1]))
            {
                temp=temp+height(square[j].y2, square[i+1].y2, square[j].y1, square[i+1].y1)*wight(square[j].x2,square[i+1].x2,square[j].x1,square[i+1].x1);

            }
            else
            {//不相交
                continue;
            }
        }
    }
    printf("他们重合的面积%d\n", temp);
}


int main()
{
    F();
    return 0;
}

 