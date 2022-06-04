#include <stdio.h>

int arr[100001]={0,};
int dp[10001]={0,};

int max(int a,int b) {
    if(a>b) return a;
    else return b;
}
int purchase(int N) {
    for(int i=1;i<=N;++i) {
        for(int j=1;j<=i;++j) {
            dp[i] = max(dp[i], arr[j] + dp[i-j]);
        }
    }
    return dp[N];
}

int main(void) {
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;++i) 
        scanf("%d",&arr[i]);
    
    printf("%d\n",purchase(N));
    return 0;
}