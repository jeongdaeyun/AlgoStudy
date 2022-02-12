import sys
n=int(sys.stdin.readline())
adj_mat=[]
for i in range(n):
    a=list(map(int,sys.stdin.readline().split(' ')))
    adj_mat.append(a)
for k in range(n):
    for i in range(n):
        for j in range(n):
            if(adj_mat[i][j]==1 or (adj_mat[i][k]==1 and adj_mat[k][j]==1)):
                """경로가 있는 경우는 1이기 때문"""
                adj_mat[i][j]=1
for col in adj_mat:
    for m in col:
        print(m,end=" ")
    print()