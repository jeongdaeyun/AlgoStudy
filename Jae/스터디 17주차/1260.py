import sys
from collections import deque
N,M,V=map(int,sys.stdin.readline().split(' '))
graph=[[] for _ in range(N+1)]
visited=[False]*(N+1)
for i in range(M):
    start,end=list(map(int,sys.stdin.readline().split(' ')))
    graph[start].append(end)
    graph[end].append(start)
for i in range(1,N+1):
    graph[i].sort()
def dfs(n):
    print(n, end=' ')
    visited[n]=True
    for i in graph[n]:
        if not visited[i]:
            dfs(i)
def bfs(n):
    visited[n]=True
    queue=deque([n])
    while queue:
        v=queue.popleft()
        print(v,end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True
DFSR=[]
DFSR.append(dfs(V))
for i in DFSR:
    if i==None:
        continue
    else:
        print(i,end=" ")
visited=[False]*(N+1)
print()
BFSR=[]
BFSR.append(bfs(V))
for i in BFSR:
    if i==None:
        continue
    else:
        print(i,end=' ')
