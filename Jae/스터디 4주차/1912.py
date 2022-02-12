a=int(input())
b=list(map(int,input().split(' ')))
dp=[0]*a
for i in range(a):
    dp[i]=max(b[i],dp[i-1]+b[i])
    """dp=10,6,9,10,15,21,-14,12,33,32"""
    """즉, dp[i-1]+b[i]가 b[i]보다 작으면 dp[i]의 값은 b[i]의 값으로 초기화 되어야 함"""
print(max(dp))