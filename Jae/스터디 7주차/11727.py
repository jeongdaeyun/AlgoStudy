n=int(input())
def method(n):
    dp=[0]*n
    if n==1:
        return 1
    elif n==2:
        return 3
    else:
        dp[0] = 1
        dp[1] = 3
        for i in range(2,n):
            if i%2==0:
                dp[i]=(dp[i-1]*2-1)%10007
            else:
                dp[i]=(dp[i-1]*2+1)%10007
    return dp[i]
print(method(n))