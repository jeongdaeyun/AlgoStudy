import sys
n=int(sys.stdin.readline())
rst=[]
for i in range(n):
    a=int(sys.stdin.readline())
    rst.append(a)
if(n==1):
    print(rst[0])
elif(n==2):
    print(rst[0]+rst[1])
elif(n==3):
    print(rst[0]+rst[-1])
else:
    dp=[0]*n
    dp[0]=rst[0]
    dp[1]=rst[0]+rst[1]
    dp[2]=max(rst[2]+rst[1],rst[2]+rst[0])
    for j in range(3,n):
        dp[j]=max(dp[j-3]+rst[j]+rst[j-1],dp[j-2]+rst[j])
        """마지막은 계단 밟아야 함 경우의 수는 n-2꺼 밟고 마지막꺼 밟기, n-3꺼 밟고 n-1꺼 밟고 마지막꺼 밟기"""
    print(dp[n-1])
#계단오르기 2579