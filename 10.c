#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    char str[50] = {"abc001020df01200v000"};
    int flag = 0;
    int k = 0;
    for(int i=0; i<=strlen(str); i++) {
         //拿到1-9的数字
        if(str[i] >='1' && str[i] <= '9') {
            flag = 1;
        }
        //不是数字
        if(!(str[i] >='0' && str[i] <= '9')) {
            flag = 0;
        }
        //该字符是0 且前面一个是非数字 且后面一个是数字时把0跳过！！！
        if(str[i] == '0' && flag == 0 && (str[i+1] >='0' && str[i+1] <= '9')) {
            continue;
        }

        str[k++] = str[i];
    }

    printf("%s\n", str);

    return 0;
}