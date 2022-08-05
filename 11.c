#include <stdio.h>
#define N 9

int flag = 0;
// 1.二维数组保存题目
unsigned char a[N][N] = {
    7,6,1,0,3,0,0,2,5,
    3,5,0,0,0,8,1,0,7,
    0,2,0,0,0,7,0,3,4,

    0,0,9,0,0,6,3,7,8,
    0,0,3,2,7,9,5,0,0,
    5,7,0,3,0,0,9,0,2,

    1,9,5,7,6,0,0,0,0,
    8,3,2,4,0,0,7,6,0,
    6,4,7,0,1,0,2,5,0
};

int Printf() {
    int count=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(a[i][j] == 0) {
                printf("* ");
                count++;
            } 
            else printf("%d ", a[i][j]);
            if(j == 2 || j == 5) printf(" ");
        }
        printf("\n");
        if(i == 2 || i == 5) printf("\n");
    }
    return count;
}

int func(unsigned short *hang, unsigned short *lie, unsigned short *xiaoge, int count) {


    if(count == 0) {
        flag = 1;
        return 0;
    }

    int i, j, k;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(a[i][j]=0) {
                unsigned short kexuan = (~hang[i]) & (~lie[j]) & (~xiaoge[i/3*3+j/3]);
                if(kexuan==0) {
                    return -1;
                }
                for(k=0; k<N; k++) {
                    if(kexuan & (1<<k)) {
                        // 把该空格填上
                        // 同时去掉行、列、小宫格数组中的那个bit
                        // 备份赋值前的数据
                        count--;

                        int ret = func(hang, lie, xiaoge, count);
                        // 下一个空格尝试失败，则还原
                        if(ret) {
                            // 
                        }
                    }
                }
                if(如果游戏还没结束) {
                    return
                }
            }
        }
    }
}

int main() {

    unsigned short hang[N] = {0};
    unsigned short lie[N] = {0};
    unsigned short xiaoge[N] = {0};

    int count = Printf();
    // 保存每一行
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            hang[i] |= 1<<(a[i][j]-1);
        }
    }
    // 保存每一列
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            lie[i] |= 1<<(a[j][i]-1);
        }
    }
    // 保存每一个小九宫格
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            xiaoge[i/3*3+j/3] |= 1<<(a[j][i]-1);
        }
    }

    func(hang, lie, xiaoge, count);

    if(flag == 1) {
        printf("成功解开！！！");
        Printf();
    }

    return 0;
}