import sys
from collections import deque
m,n,h=map(int,sys.stdin.readline().split(' '))
tomato=[[list(map(int,sys.stdin.readline().split(' '))) for _ in range(n)] for _ in range(h)]
q=deque([])
dx=[-1,1,0,0,0,0]
dy=[0,0,-1,1,0,0]
dz=[0,0,0,0,1,-1]
day=0
for k in range(h):
    for i in range(n):
        for j in range(m):
            if tomato[k][i][j]==1:
                q.append([k,i,j])
            """탐색 전 모든 칸을 돌면서 익어있는 토마토의 위치를 큐에 집어 넣음"""
def bfs():
    while q:
        x,y,z=q.popleft()
        for i in range(6):
            nx=x+dx[i]
            ny=y+dy[i]
            nz=z+dz[i]
            if 0<=nx<h and 0<=ny<n and 0<=nz<m:
                if tomato[nx][ny][nz]==0:
                    tomato[nx][ny][nz]=tomato[x][y][z]+1
                    q.append([nx,ny,nz])
bfs()
for k in tomato:
    for i in k:
        for j in i:
            if j==0:
                print(-1)
                exit()
        day=max(day,max(i))
print(day-1)