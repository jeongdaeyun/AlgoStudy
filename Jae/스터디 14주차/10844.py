"""0번째와 9번째는 따로 처리"""
import sys
n=int(sys.stdin.readline())
INF=1000000000
dp=[[0 for _ in range(10)] for __ in range(n)]
for i in range(1,10):
    """처음에 전부 1로 초기화"""
    dp[0][i]=1
for i in range(1,n):
    """0번째의 값은 이전꺼의 1번째의 값을 그대로 가져오고 0뒤에는 한 개밖에 못온다"""
    """9번째의 값은 이전꺼의 8번째의 값을 그대로 가져옴 9뒤에는 한 개밖에 못온다"""
    dp[i][0]=dp[i-1][1]
    dp[i][9]=dp[i-1][8]
    for j in range(1,9):
        """나머지는 1부터 8까지는 이전꺼의 위 아래값을 더해줌"""
        dp[i][j]=dp[i-1][j+1]+dp[i-1][j-1]
print(sum(dp[n-1]) % INF)
