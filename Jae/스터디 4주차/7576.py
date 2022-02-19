import sys
from collections import deque
m,n=map(int,sys.stdin.readline().split(' '))
tomato=[list(map(int,sys.stdin.readline().split(' '))) for _ in range(n)]
q=deque([])
dx=[-1,1,0,0]
dy=[0,0,-1,1]
day=0
for i in range(n):
    for j in range(m):
        if tomato[i][j]==1:
            q.append([i,j])
            """탐색 전 모든 칸을 돌면서 익어있는 토마토의 위치를 큐에 집어 넣음"""
def bfs():
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<m:
                if tomato[nx][ny]==0:
                    tomato[nx][ny]=tomato[x][y]+1
                    q.append([nx,ny])
bfs()
for i in tomato:
    for j in i:
        if j==0:
            print(-1)
            exit(0)
    day=max(day,max(i))
print(day-1)