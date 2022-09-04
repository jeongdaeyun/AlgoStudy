import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    coin=map(int,sys.stdin.readline().split(' '))
    m=int(sys.stdin.readline())
    dp=[0 for _ in range(m+1)]
    dp[0]=1
    """어떤 동전이든 0개의 개수를 통해 0원을 만들 수 있는 가지수는 1이다"""
    for i in coin:
        for j in range(1,m+1):
            if j-i>=0:
                dp[j]+=dp[j-i]
    print(dp[m])
