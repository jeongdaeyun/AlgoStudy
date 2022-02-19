#include <stdio.h>

int main(void){
    int N, VISIT = 1 << 10, ret = 0;
    int dp[101][10][VISIT];
    
    scanf("%d", &N);

    for(int i = 1; i < 10; i++) dp[1][i][1<<i] = 1;

    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < VISIT; k++){
                int bit = k | (1 << j);
                dp[i][j][bit] = (dp[i][j][bit] + 
                                ((0<j ? dp[i-1][j-1][k] : 0) + 
                                (j<9 ? dp[i-1][j+1][k] : 0))%1000000000)%1000000000;
            }
        }
    }

    for(int i = 0; i < 10; i++) ret = (ret + dp[N][i][VISIT-1])%1000000000;
    printf("%d\n", ret);
}