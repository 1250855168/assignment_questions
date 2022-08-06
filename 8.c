#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 9 //表格的大下 中的长宽

unsigned char array[N][N] = {
    7, 6, 1, 0, 3, 0, 0, 2, 5,
    3, 5, 0, 0, 0, 8, 1, 0, 7,
    0, 2, 0, 0, 0, 7, 0, 3, 4,

    0, 0, 9, 0, 0, 6, 3, 7, 8,
    0, 0, 3, 2, 7, 9, 5, 0, 0,
    5, 7, 0, 3, 0, 0, 9, 0, 2,

    1, 9, 5, 7, 6, 0, 0, 0, 0,
    8, 3, 2, 4, 0, 0, 7, 6, 0,
    6, 4, 7, 0, 1, 0, 2, 5, 0};
static int count = 0; //计算有多少个0
static int flag = 0;
;            // 1标志解密成功
void Print() //打印表格
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (array[i][j] == 0)
            {
                printf("* "); //如果是0打印*
                count++;
            }
            else
            {
                printf("%d ", array[i][j]); //打印元素
            }
            if ((j + 1) % 3 == 0) // 3列打印一个空格
            {
                printf(" ");
            }
        }
        printf("\n");         // 9列打印一个回车
        if (i == 2 || i == 5) // 3行打印一个回车
        {
            printf("\n");
        }
    }
}

int Decrypt(unsigned short *cow, unsigned short *col, unsigned short *pane)
{
    if (count == 0) //如果0全被填完 //打印解密的结果
    {
        Print();
        return 0;
    }
    int i, j, x,ret;
    int temp; //用来备份
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (array[i][j] == 0)
            {                                       //可以使用的数字
                unsigned short Ava_number = (~cow[i]) & (~col[j]) & (~pane[i / 3 * 3 + j / 3]); //得到这个点可用的数字

                if (Ava_number & (pow(2, N) - 1) == 0) //如果还有0 但是没有可以选的数字跳到上一次 重新选数字
                {
                    return -1;
                }
                for (x = 0; x < N; x++)
                {
                    if (Ava_number & (1 << x)) //把可用的数字给附上去
                    {
                        temp = array[i][j]; //给这次的数字保存 给返回上次用
                        array[i][j] = x + 1;
                        cow[i] |= (1 << x);
                        col[j] |= (1 << x);
                        pane[i / 3 * 3 + j / 3] |= (1 << x);
                        count--;
                        ret = Decrypt(cow, col, pane); //对下一次进行解密
                        if (ret)
                        {

                            //如果还有0 但是没有可以选的数字跳到上一次 重新选数字
                            //先对 行列 小方格 还原
                            cow[i] &= ~(1 << x);
                            col[j] &= ~(1 << x);
                            pane[i / 3 * 3 + j / 3] &= ~(1 << x);
                            count++;
                            //最后对数值还原
                            array[i][j] = temp;
                        }
                    }
                }
                if (ret == -1 && x == N)
                {
                    return -1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}

int main()
{
    Print();
    unsigned short cow[N] = {0};  //行
    unsigned short col[N] = {0};  //列
    unsigned short pane[N] = {0}; //小方格

    for (int i = 0; i < N; i++) //把行中非0的数字给保存
    {
        for (int j = 0; j < N; j++)
        {

            cow[i] |= 1 << (array[i][j] - 1);
        }
    }
    for (int i = 0; i < N; i++) //把列中非0的数字给保存
    {
        for (int j = 0; j < N; j++)
        {

            col[i] |= 1 << (array[j][i] - 1);
        }
    }
    for (int i = 0; i < N; i++) //把小方格中非0的数字给保存
    {
        for (int j = 0; j < N; j++)
        {

            pane[i / 3 * 3 + j / 3] |= 1 << (array[i][j] - 1);
        }
    }
    Decrypt(cow, col, pane);
    return 0;
}