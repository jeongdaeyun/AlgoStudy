#include <stdio.h>

int a[501][501]={0,};
int n,i,j,k;

void input() {
    scanf("%d",&n);
    for(i=0;i<n;++i) {
        for(j=0;j<=i;++j) {
            scanf("%d",&a[i][j]);
        }
    }
}

int max(int a,int b) {
    if(a>b)
        return a;
    else
        return b;
}

int main(void) {
    int m=0;
    input();
    int num[501][501]={0,};
    
    num[0][0] = a[0][0];
    for(i=1;i<n;++i) {
        for(j=0;j<=i;++j) {
            if(j==0)
                num[i][j] = num[i-1][j] + a[i][j];
            else if(j == i)
                num[i][j] = num[i-1][j-1] + a[i][j];
            else
                num[i][j] = max(num[i-1][j-1],num[i-1][j]) + a[i][j];
        }
    }
    
    
    for(i=0;i<n;++i) {
        if(m < num[n-1][i])
            m = num[n-1][i];
    }
    printf("%d\n",m);
    return 0;
}