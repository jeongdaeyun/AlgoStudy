import sys

n = int(sys.stdin.readline())
dp = [0] * (n + 1)
for i in range(2, n + 1):
    if (i % 6 == 0):
        """6으로 나눌 수 있는 경우 3,2로 나눴을 때 작은 경우"""
        dp[i] = 1 + min(dp[i - 1], dp[i // 3], dp[i // 2])
    elif (i % 2 == 0):
        """2로 나눌 수 있는 경우"""
        dp[i] = 1 + min(dp[i - 1], dp[i // 2])
    elif (i % 3 == 0):
        """3로 나눌 수 있는 경우"""
        dp[i] = 1 + min(dp[i - 1], dp[i // 3])
    elif (i % 3 != 0 and i % 2 != 0):
        """5,11과 같이 무조건 -1을 하고 그 수에 대해 비교할 경우"""
        dp[i] = dp[i - 1] + 1
print(dp[n])