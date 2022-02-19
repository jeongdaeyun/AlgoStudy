n=int(input())
rst=[]
for i in range(n):
    rst.append(list(map(int, input().split(' '))))
for i in range(1,n):
    for j in range(i+1):
        if j==0:
            """왼쪽으로만 가는 경우"""
            rst[i][j]=rst[i-1][j]+rst[i][j]
        elif j==i:
            """오른쪽으로만 가는 경우"""
            rst[i][j]=rst[i-1][j-1]+rst[i][j]
        else:
            rst[i][j]=max(rst[i-1][j],rst[i-1][j-1])+rst[i][j]
m=max(rst)
print(max(m))