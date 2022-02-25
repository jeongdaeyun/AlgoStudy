#include <stdio.h>
#define mod 1000000000

int main(void) {
    int N,visit=1 << 10,ret=0;
    scanf("%d",&N);
    int dp[101][10][visit];
    for(int i=1;i<10;++i) dp[1][i][1<<i] = 1;

    for(int i=2;i<=N;++i) {
        for(int j=0;j<10;++j) {
            for(int k=0;k<visit;++k) {
                int bit = k | (1<<j);
                dp[i][j][bit] = (dp[i][j][bit] + 
                ((0<j ? dp[i-1][j-1][k] : 0) + 
                (j<9 ? dp[i-1][j+1][k] : 0))%mod)%mod;
            }
        }
    }

    for(int i=0;i<10;++i) ret = (ret + dp[N][i][visit-1])%mod;
    printf("%d\n",ret);
    return 0;
}