import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split(' '))
m = 10 ** 5
graph = [0] * (m + 1)
q = deque()
q.append(n)

def bfs():
    while q:
        x = q.popleft()
        if x == k:
            break
        for i in (x-1, x+1, x+x):
            if 0 <= i < m+1 and graph[i]==0:
                graph[i] = graph[x] + 1
                q.append(i)


bfs()
print(graph[k])
