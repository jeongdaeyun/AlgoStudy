import sys
import collections

dp = collections.defaultdict(int)
num = 1000000007
n = int(sys.stdin.readline())
dp[1] = 1
dp[2] = 1


def method(n):
    if dp[n] != 0:
        return dp[n]
    if n % 2 == 0:
        a=n//2
        dp[n]=((method(a)**2)+(method(a)*2*method(a-1))%num)
        return dp[n]
    else:
        a=n//2
        dp[n]=((method(a+1)**2)+method(a)**2)%num
        return dp[n]
print(method(n)%num)
