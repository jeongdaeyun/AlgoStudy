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
    for(int i = 1; i < 9; i++)
    {
        dp[1][i][0] = 1;
    }
    dp[1][9][1<<1] = 1;

    // 각 자리수마다
    for(int i = 2; i <= n; i++)
    {
        // 모든 숫자가 들어올 수 있는 상황에서
        for(int j = 0; j <= 9; j++)
        {
            // 이전의 상황(지금까지 지나온 수)을 기반으로
            for(int k = 0; k < 4; k++)
            {
                //0을 지나는 상황이라면
                if(j == 0)
                {
                    // 현재 상황에 1로 들어온 모든 상황을 확인해준다.
                    // 현재 상황은 0을 지나는 상황이므로 0을 지났다고 0번째 비트에 표기해줘야함.
                    dp[i][0][k | 1] = (dp[i][0][k | 1] + dp[i-1][1][k]) % MOD;
                }
                //9를 지나는 상황이라면
                else if(j == 9)
                {
                    // 현재 상황에 9로 들어온 모든 상황을 확인해준다.
                    // 현재 상황은 항상 9을 지났으므로 9를 지났다고 1번째 비트에 표기해줘야함.
                    dp[i][9][k | 2] = (dp[i][9][k | 2] + dp[i-1][8][k]) % MOD;
                }
                // 0과 9가 아닌 수를 지나는 상황이라면
                else
                {
                    // 양 옆으로 오는 숫자들을 더해준다.(0과 9가 아닌 숫자를 지난건 굳이 기록할 필요 없음)
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k]) % MOD;
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j+1][k]) % MOD;
                }
            }
        }
    }
    int total = 0;
    for(int i = 0; i < 10; i++)
    {
        total = (total + dp[n][i][3]) % MOD;
    }
    cout << total << '\n';

    return 0;
}