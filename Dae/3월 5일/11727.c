#include <stdio.h>
#define mod 10007

int main(void) {
    int n;
    scanf("%d",&n);
    int dp[10001]={0,};
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=n;++i) dp[i] = (dp[i-1] + 2*dp[i-2])%mod;
    printf("%d\n",dp[n]);
    return 0;
} 