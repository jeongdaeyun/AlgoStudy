#include <iostream>
#include <cstring>
using namespace std;

int n;
int max_value;
int num_list[1000];
int dp[1000];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num_list[i];
        dp[i] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if (num_list[j] < num_list[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        max_value = max(max_value,dp[i]);
    }
    cout << max_value << '\n';
}