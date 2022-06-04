import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split(' '))
graph=[list(map(int,sys.stdin.readline().split(' '))) for _ in range(n)]
def bfs():
    q = deque([])
    visited = [[False] * m for _ in range(n)]
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    count=0
    q.append([0,0])
    visited[0][0]=True
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx=dx[i]+x
            ny=dy[i]+y
            if 0<=nx<n and 0<=ny<m:
                if graph[nx][ny]==0 and visited[nx][ny]==False:
                    """치즈가 아닌 부분만 q에 넣어서 계속 탐색"""
                    q.append([nx,ny])
                    visited[nx][ny]=True
                elif graph[nx][ny]==1:
                    """치즈인 부분은 0으로 바꾸고 방문 표시(가장 자리 표시)"""
                    graph[nx][ny]=0
                    count+=1
                    visited[nx][ny]=True
    return count
time=0
cheese=[]
while True:
    """다 녹을 때까지 반복"""
    cheese.append(bfs())
    if cheese[time]==0:
        break
    time+=1
print(time)
print(cheese[-2])
"""한 시간 전"""