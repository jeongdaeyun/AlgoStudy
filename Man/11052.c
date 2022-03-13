#include <stdio.h>
#define max(a, b) (a > b) ? a : b
 
int main(void){
    int N;
    scanf("%d", &N);
    int pack[N+1];
    int dp[N+2];
    dp[0] = 0;
    for (int i = 1; i <= N; i++){
        scanf("%d", &pack[i]);
        dp[i] = 0;
    }
    
    dp[1] = pack[1];
 
    for (int i = 2; i <= N; i++){
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + pack[i - j]);
        }
    }
 
    printf("%d\n", dp[N]);
    return 0;
}
