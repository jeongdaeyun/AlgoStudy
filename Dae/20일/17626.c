#include <stdio.h>
#include <math.h>

int dp[100001];

int main(void) {
    int n;
    scanf("%d",&n);
    dp[0]=0;
    dp[1]=1;
    if(dp[n] != 0) return n;
    
    for(int i=2; i <= n; ++i) {
        dp[i] = 4;
        for(int j=1;j<=sqrt(i);++j) {
            dp[i - (j*j)] < dp[i] ? (dp[i] = dp[i - (j*j)]) : (dp[i]);
        }
        dp[i] += 1;
    }
    
    printf("%d\n", dp[n]);
    return 0;
}