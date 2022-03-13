import sys
n=int(sys.stdin.readline())
card=[0]+list(map(int,sys.stdin.readline().split(' ')))
dp=[0 for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,i+1):
        dp[i]=max(dp[i-j]+card[j],dp[i])
print(dp[n])