#include <iostream>
#include <cstring>
using namespace std;

int n, input;
int pack[1001];
int dp[1001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> pack[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i],dp[i-j] + pack[j]); 
        }
    }
    cout << dp[n];
    return 0;
}