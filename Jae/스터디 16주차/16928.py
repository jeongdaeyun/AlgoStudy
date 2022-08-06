import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split(' '))
"""뱀 개수:n, 사다리 개수:m"""
graph=[i for i in range(101)]
visited=[0]*101
for _ in range(n):
    x,y=map(int,sys.stdin.readline().split(' '))
    """x번에 도착하면 y번으로 이동"""
    graph[x]=y
for _ in range(m):
    u,v=map(int,sys.stdin.readline().split(' '))
    """u번에 도착하면 v번으로 이동"""
    graph[u]=v
def bfs(start):
    q=deque([start])
    visited[start]=1
    while q:
        target=q.popleft()
        for i in range(1,7):
            """주사위는 1~6"""
            dice=target+i
            """지정한 것(target)에 주사위의 수만큼 더함"""
            if dice>100:
                """100을 넘어가면 무시"""
                continue
            gd=graph[dice]
            """이동한 칸"""
            if visited[gd]==0:
                """이동했는데 탐색이 안되었다면"""
                q.append(gd)
                """q에넣고 """
                visited[gd]=visited[target]+1
                """이동한 횟수를 1증가"""
                if gd==100:
                    """100에 이동하면 return"""
                    return
bfs(1)
"""1번부터 시작"""
print(visited[100]-1)
"""1빼는 이유는 처음에 위치한 1때 주사위를 한 번 쓰기 때문"""