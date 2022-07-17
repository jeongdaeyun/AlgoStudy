import sys
n=int(sys.stdin.readline())
rst=[]
dp=[[0 for _ in range(n)] for __ in range(n)]
INF=float(1e9)
for _ in range(n):
    matrix=list(map(int,sys.stdin.readline().split(' ')))
    rst.append(matrix)
for cnt in range(1,n):
    for i in range(n-cnt):
        j=cnt+i
        dp[i][j]=INF
        for k in range(i,j):
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+(rst[i][0]*rst[k][1]*rst[j][1]))
print(dp[0][n-1])