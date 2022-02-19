#include <iostream>
#include <cstring>
#define MOD 1000000000
using namespace std;

int dp[101][10][1<<2];
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < 9; i++) dp[1][i][0] = 1;
    dp[1][9][1<<1] = 1;

    for(int i = 2; i <= n; i++)
        for(int j = 0; j <= 9; j++)
            for(int k = 0; k < 4; k++)
                if(j == 0)
                    dp[i][0][k | 1] = (dp[i][0][k | 1] + dp[i-1][1][k]) % MOD;
                else if(j == 9)
                    dp[i][9][k | 2] = (dp[i][9][k | 2] + dp[i-1][8][k]) % MOD;
                else{
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k]) % MOD;
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j+1][k]) % MOD;
                }
    
    int total = 0;
    for(int i = 0; i < 10; i++)
        total = (total + dp[n][i][3]) % MOD;
    cout << total << '\n';
}