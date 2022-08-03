#include <stdio.h>
#include <string.h>

void Is(char *p)
{
    char a[100] = {0};//最终保留下来的
    char temp1[100] = {0};//工具人 
    int x = 0;//a的下标
    int y;//temp下标
    for (int i = 0; *(p + i) != '\0'; i++)
    {
        while ((*(p + i) < '0' || *(p + i) > '9') && *(p + i) != '\0')//英语字母直接拿
        {
            a[x++] = *(p + i);
            i++;
            puts(a);
        }
        y = 0;
        memset(temp1, 0, 100);
        while ((*(p + i) >= '0' && *(p + i) <= '9') && *(p + i) != '\0')//数字继续看
        {
            temp1[y++] = *(p + i);
            i++;
            puts(temp1);
        }
        i--;//因为第二个循环多加了一次
        int q;//设置一个标志
        for (int t = 0; t < y; t++)
        {
            if (temp1[t] == '0')
            {
                q = 1;
            }
            else
            {
                q = 0;
                break;
            }
        }
        if (q == 1)
        {
            a[x++] = temp1[0];//都是拿一个0
            puts(a);
        }
        else
        {
            int z = 0;//继续设置一个标志
            for (int t = 0; t < y; t++)
            {
                if (z == 0)
                {
                    if (temp1[i] == '0')//把非数字后面的0拿掉
                    {
                        continue;
                    }
                    else
                    {
                        z = 1;
                        t++;
                        continue;
                    }
                }
                if (z == 1)
                {
                    a[x++] = temp1[t];//把后面数字拿进去 ok!
                }
            }
        }
    }
}

int main()
{
    char a[] = "da0000sd00112as0000";
    Is(a);
    return 0;
}