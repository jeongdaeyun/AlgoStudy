import sys
n,m=map(int,sys.stdin.readline().split(' '))
INF=int(1e9)
graph=[[INF]*(n+1) for _ in range(n+1)]
for _ in range(m):
    a,b=list(map(int,sys.stdin.readline().split(' ')))
    graph[a][b]=1
    graph[b][a]=1
for k in range(1,n+1):
    graph[k][k]=0
    for i in range(1,n+1):
        for j in range(1,n+1):
            graph[i][j]=min(graph[i][k]+graph[k][j],graph[i][j])
rst=[]
for i in range(1,n+1):
    rst.append(sum(graph[i][1:]))
print(rst.index(min(rst))+1)