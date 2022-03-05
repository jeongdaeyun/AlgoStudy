import sys
input = sys.stdin.readline
mod = 1000000007
N = int(input())
dp = [0 for _ in range(1000000001)]
dp[0]=0
dp[1]=1

def fibo(N):
    a,b,c,d=int(a),int(b),int(c),int(d)
    if dp[N] != 0:
        return dp[N]
    if N%2 == 1:
        b = N//2
        a = b+1
        c = fibo(a)
        d = fibo(b)
        dp[N] = (c**2 + d**2)%mod
        return dp[N]
    else:
        a = N//2
        b = a-1
        c = fibo(a)
        d = fibo(b)
        dp[N] = (c**2 + 2*c*d)%mod
        return dp[N]

print(dp[N])
