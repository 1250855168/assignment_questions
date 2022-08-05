#include <stdio.h>
#include <stdlib.h>

int *fillnumber(int a[9][9][10],int number,int i,int j){
    for (int k=0;k<9;k++){
        a[i][k][number]++;
        a[k][j][number]++;
    }
    for (int n=0;n<3;n++){
        for (int m=0;m<3;m++){
            a[i/3*3+n][j/3*3+m][number]++;
        }
    }
    return a;
}
int *resetnumber(int a[9][9][10],int number,int i,int j){
    for (int k=0;k<9;k++){
        a[i][k][number]--;
        a[k][j][number]--;
    }
    for (int n=0;n<3;n++){
        for (int m=0;m<3;m++){
            a[i/3*3+n][j/3*3+m][number]--;
        }
    }
    return a;
}

void search(int step, int a[9][9],int g[9][9][10]){
    if (step==0) {
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (a[i][j]==0) {
                for (int number=1;number<10;number++){
                    if (g[i][j][number]==0){
                        fillnumber(g,number,i,j);
                        a[i][j]=number;
                        search(step-1,a,g);
                        a[i][j]=0;
                        resetnumber(g,number,i,j);
                    }
                }
                return;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    int a[9][9];
    int abool[9][9][10];
    int step=0;
    for (int i =0;i<9;i++){
        for (int j=0;j<9;j++){
            for (int k=1;k<10;k++) {
                abool[i][j][k]=0;
            }
        }
    }
    for (int i =0;i<9;i++){
        for (int j=0;j<9;j++){
            scanf("%d",&a[i][j]);
            if (a[i][j]==0) {
                step++;
            }
            else{
                fillnumber(abool,a[i][j],i,j);

            }
        }
    }
    search(step,a,abool);
    return 0;
}