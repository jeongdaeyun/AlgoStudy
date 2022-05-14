#include <stdio.h>
#include <stdlib.h>
#define INF 1410065408
int b[100001][100001]={0,};
int floyd(int x) {
    int d[x][x];
    for(int i=0;i<x;++i) {
        for(int j=i;j<x;++j) {
            d[i][j] = b[i][j];
        }
    }
    for(int k=0;k<x;++k) {
        for(int i=0;i<x;++i) {
            for(int j=0;j<x;++j) {
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    return d[x-1][x-1];
}

int min(int num1,int num2,int num3) {
    if(num1 < num2 && num1 < num3) return num1;
    else if(num2 < num1 && num2 < num3) return num2;
    else return num3;
}

int main(void) {
    int N;
    scanf("%d",&N);
    int a[100001][3]={0,};
    for(int i=0;i<N;++i) {
        for(int j=0;j<3;++j) {
            scanf("%d",&a[i][j]);
        }
    }   
    for(int i=0;i<N;++i) {
        for(int j=i;j<N;++j) {
            if(i==j) {
                b[i][j] = INF;
            }
            else {
                b[i][j] = min(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1]),abs(a[i][2]-a[j][2]));
            }
        }
    }
    int value = floyd(N);
    printf("%d\n",value);
    return 0;
}
