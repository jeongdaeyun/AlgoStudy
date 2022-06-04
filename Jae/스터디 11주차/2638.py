import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split(' '))
graph = [list(map(int, sys.stdin.readline().split(' '))) for _ in range(n)]
count = 0


def bfs():
    q = deque([])
    first = [[-1] * m for _ in range(n)]
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    q.append([0, 0])
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y
            if 0 <= nx < n and 0 <= ny < m:
                if first[nx][ny] == -1:
                    if graph[nx][ny] >= 1:
                        graph[nx][ny] += 1
                    else:
                        first[nx][ny] = 0
                        q.append([nx, ny])


while True:
    """다 녹을 때까지 반복"""
    bfs()
    time = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] >= 3:
                graph[i][j] = 0
                time = 1
            elif graph[i][j] == 2:
                graph[i][j] = 1
    if time == 1:
        count += 1
    else:
        break
print(count)
