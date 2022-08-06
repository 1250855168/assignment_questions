#include <stdio.h>
#include <math.h>
#define N 9

int flag = 0;
// 1.二维数组保存题目
unsigned char a[N][N] = {
    7, 6, 1, 0, 3, 0, 0, 2, 5,
    3, 5, 0, 0, 0, 8, 1, 0, 7,
    0, 2, 0, 0, 0, 7, 0, 3, 4,

    0, 0, 9, 0, 0, 6, 3, 7, 8,
    0, 0, 3, 2, 7, 9, 5, 0, 0,
    5, 7, 0, 3, 0, 0, 9, 0, 2,

    1, 9, 5, 7, 6, 0, 0, 0, 0,
    8, 3, 2, 4, 0, 0, 7, 6, 0,
    6, 4, 7, 0, 1, 0, 2, 5, 0};
//打印9*9列表
int Printf()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] == 0)
            {
                printf("* ");
                count++;
            }
            else
                printf("%d ", a[i][j]);
            if ((j + 1) % 3 == 0)
                printf(" ");
        }
        printf("\n");
        if (i == 2 || i == 5)
            printf("\n");
    }
    return count;
}

int func(unsigned short *hang, unsigned short *lie, unsigned short *xiaoge, int count)
{

    // printf("\n");
    // printf("%d", count);
    if (count == 0)
    {
        printf("well done!\n");
        Printf();
        return 0;
    }

    int i, j, k;
    int tmp; // 用来备份的
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (a[i][j] == 0)
            {
                // 每一行、每一列、每一个小宫格可选数的交集
                unsigned short kexuan = (~hang[i]) & (~lie[j]) & (~xiaoge[i / 3 * 3 + j / 3]);
                // 如果第N位都是0，说明没有可备选的数，就返回到上一个空格
                if (kexuan & (pow(2, N) - 1) == 0)
                { // pow() 2的N次方
                    return 1;
                }
                // 对每一个备选数进行依次尝试
                for (k = 0; k < N; k++)
                {
                    if (kexuan & (1 << k))
                    {
                        // 备份赋值前的数据
                        tmp = a[i][j];
                        // 给该空格赋值
                        a[i][j] = k + 1;
                        // 同时给行、列、小宫格数组的该bit置1
                        hang[i] |= 1 << k;
                        lie[j] |= 1 << k;
                        xiaoge[i / 3 * 3 + j / 3] |= 1 << k;
                        count--;

                        int ret = func(hang, lie, xiaoge, count);
                        // 下一个空格尝试失败，则还原
                        if (ret)
                        {
                            // 先还原行、列、小宫格数组
                            hang[i] &= ~(1 << k);
                            lie[j] &= ~(1 << k);
                            xiaoge[i / 3 * 3 + j / 3] &= ~(1 << k);
                            count++;
                            // 再还原填的空格
                            a[i][j] = tmp;
                        }
                    }
                }
            }
        }
    }
}

int main()
{

    unsigned short hang[N] = {0};   //用来存储行上存在的数字
    unsigned short lie[N] = {0};    //用来存储列上存在的数字
    unsigned short xiaoge[N] = {0}; //用来存储小哥内存在的数字

    int count = Printf(); //统计9*9列表里的数字0
    // 保存每一行
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            hang[i] |= 1 << (a[i][j] - 1);
        }
    }
    // 保存每一列
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            lie[i] |= 1 << (a[j][i] - 1);
        }
    }
    // 保存每一个小九宫格
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            xiaoge[i / 3 * 3 + j / 3] |= 1 << (a[i][j] - 1);
        }
    }

    func(hang, lie, xiaoge, count);

    return 0;
}