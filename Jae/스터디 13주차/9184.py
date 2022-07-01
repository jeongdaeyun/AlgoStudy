dp=[[[0 for k in range(21)] for j in range(21)] for i in range(21)]
"""0이상 20이하 이므로"""
def w(a,b,c):
    if a<=0 or b<=0 or c<=0:
        return 1
    elif a>20 or b>20 or c>20:
        return w(20,20,20)
    elif dp[a][b][c]!=0:
        """0이하면 1을 반환하기 때문"""
        return dp[a][b][c]
    elif a<b and b<c:
        dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
        """반환 후 재귀"""
        return dp[a][b][c]
    else:
        dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)
        """반환 후 재귀"""
        return dp[a][b][c]
while True:
    a,b,c=map(int,input().split(' '))
    if a==-1 and b==-1 and c==-1:
        break
    else:
        print("w({0}, {1}, {2})".format(a,b,c)+" = "+str(w(a,b,c)))
        """ex) 1 1 1 -> a=1, b=1, c=1이므로 {0}자리에 1, {1}자리에 1, {2}자리에 1"""