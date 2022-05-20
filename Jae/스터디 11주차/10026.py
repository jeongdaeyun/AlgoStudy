import sys
from collections import deque
n=int(sys.stdin.readline())
yak=[list(map(str,sys.stdin.readline().rstrip())) for _ in range(n)]
"""적록색약 배열"""
visited=[[False]*n for _ in range(n)]
"""방문확인"""
q=deque([])
dx=[0,0,-1,1]
dy=[-1,1,0,0]
"""상하좌우"""
count=0
"""색맹x 카운트"""
blind_count=0
"""색맹 카운트"""
def bfs(x,y,arr,visited):
    q.append([x,y])
    visited[x][y]=True
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx=dx[i]+x
            ny=dy[i]+y
            if 0<=x<n and 0<=y<n and 0<=nx<n and 0<=ny<n:
                if arr[nx][ny]==arr[x][y] and visited[nx][ny]==False:
                   """nx ny위치와 x y위치의 색이 같고 nx ny를 아직 방문하지 않았다면"""
                   q.append([nx,ny])
                   visited[nx][ny]=True
for i in range(n):
    for j in range(n):
        if visited[i][j]==False:
            """방문하지 않은 부분이면 bfs진행"""
            bfs(i,j,yak,visited)
            count+=1
print(count, end=' ')
visited=[[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if yak[i][j]=="R":
            yak[i][j]="G"
"""색맹배열로 다시 만듦"""
for i in range(n):
    for j in range(n):
        if visited[i][j]==False:
            bfs(i,j,yak,visited)
            blind_count+=1
print(blind_count)
