#include <stdio.h>
#include <math.h>
#define mod 1000000007

long long fibo(long long x) {
    long long dp[x];
    long long a,b,c,d;
    dp[1] = 1;
    dp[2] = 1;
    if(dp[x] != 0) return dp[x];
    if(x%2 == 1) {
        b = (x/2);
        a = (b + 1);
        c = fibo(a);
        d = fibo(b);
        dp[x] = (int)(pow(c,2) + pow(d,2)) % mod;
        return dp[x];
    }
    else {
        a = (x/2);
        b = (a - 1);
        c = fibo(a);
        d = fibo(b);
        dp[x] = (int)(pow(c,2) + (2*c*d)) % mod;
        return dp[x];
    }
}

int main(void) {
    long long n;
    scanf("%lld",&n);
    printf("%lld\n",fibo(n));
    return 0;
}