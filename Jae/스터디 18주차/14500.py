import sys
n,m=map(int,sys.stdin.readline().split(' '))
graph=[list(map(int,sys.stdin.readline().split(' '))) for _ in range(n)]
max=0
for x in range(n):
    for y in range(m-3):
        """ㅡ"""
        if max<graph[x][y]+graph[x][y+1]+graph[x][y+2]+graph[x][y+3]:
            max=graph[x][y]+graph[x][y+1]+graph[x][y+2]+graph[x][y+3]
for x in range(n-3):
    for y in range(m):
        """ㅣ"""
        if max<graph[x][y]+graph[x+1][y]+graph[x+2][y]+graph[x+3][y]:
            max=graph[x][y]+graph[x+1][y]+graph[x+2][y]+graph[x+3][y]
for x in range(n-1):
    for y in range(m-1):
        """ㅁ"""
        if max<graph[x][y]+graph[x][y+1]+graph[x+1][y]+graph[x+1][y+1]:
            max=graph[x][y]+graph[x][y+1]+graph[x+1][y]+graph[x+1][y+1]
for x in range(n-2):
    for y in range(m-1):
        if max<graph[x][y]+graph[x+1][y]+graph[x+2][y]+graph[x+2][y+1]:
            """L"""
            max=graph[x][y]+graph[x+1][y]+graph[x+2][y]+graph[x+2][y+1]
        if max<graph[x][y]+graph[x+1][y]+graph[x+2][y]+graph[x][y+1]:
            """L을 밑으로 뒤집기"""
            max=graph[x][y]+graph[x+1][y]+graph[x+2][y]+graph[x][y+1]
        if max<graph[x][y]+graph[x][y+1]+graph[x+1][y+1]+graph[x+2][y+1]:
            """L을 밑으로 뒤집고 우측으로 뒤집기"""
            max=graph[x][y]+graph[x][y+1]+graph[x+1][y+1]+graph[x+2][y+1]
        if max<graph[x][y+1]+graph[x+1][y+1]+graph[x+2][y+1]+graph[x+2][y]:
            """L을 우측으로 뒤집기"""
            max=graph[x][y+1]+graph[x+1][y+1]+graph[x+2][y+1]+graph[x+2][y]
        if max<graph[x][y]+graph[x+1][y]+graph[x+2][y]+graph[x+1][y+1]:
            """ㅏ"""
            max=graph[x][y]+graph[x+1][y]+graph[x+2][y]+graph[x+1][y+1]
        if max<graph[x][y+1]+graph[x+1][y+1]+graph[x+2][y+1]+graph[x+1][y]:
            """ㅓ"""
            max=graph[x][y+1]+graph[x+1][y+1]+graph[x+2][y+1]+graph[x+1][y]
        if max<graph[x][y]+graph[x+1][y]+graph[x+1][y+1]+graph[x+2][y+1]:
            """초록색 도형 원본"""
            max=graph[x][y]+graph[x+1][y]+graph[x+1][y+1]+graph[x+2][y+1]
        if max<graph[x][y+1]+graph[x+1][y]+graph[x+1][y+1]+graph[x+2][y]:
            """초록색 도형을 우측으로 뒤집기"""
            max=graph[x][y+1]+graph[x+1][y]+graph[x+1][y+1]+graph[x+2][y]
for x in range(n-1):
    for y in range(m-2):
        if max<graph[x][y]+graph[x+1][y]+graph[x+1][y+1]+graph[x+1][y+2]:
            """ㄴ"""
            max=graph[x][y]+graph[x+1][y]+graph[x+1][y+1]+graph[x+1][y+2]
        if max<graph[x][y+2]+graph[x+1][y]+graph[x+1][y+1]+graph[x+1][y+2]:
            """ㄴ을 우측으로 뒤집기"""
            max=graph[x][y+2]+graph[x+1][y]+graph[x+1][y+1]+graph[x+1][y+2]
        if max<graph[x][y]+graph[x][y+1]+graph[x][y+2]+graph[x+1][y+2]:
            """ㄱ"""
            max=graph[x][y]+graph[x][y+1]+graph[x][y+2]+graph[x+1][y+2]
        if max<graph[x][y]+graph[x][y+1]+graph[x][y+2]+graph[x+1][y]:
            """ㄱ을 우측으로 뒤집기"""
            max=graph[x][y]+graph[x][y+1]+graph[x][y+2]+graph[x+1][y]
        if max<graph[x][y+1]+graph[x+1][y]+graph[x+1][y+1]+graph[x+1][y+2]:
            """ㅗ"""
            max=graph[x][y+1]+graph[x+1][y]+graph[x+1][y+1]+graph[x+1][y+2]
        if max<graph[x][y]+graph[x][y+1]+graph[x+1][y+1]+graph[x][y+2]:
            """ㅜ"""
            max=graph[x][y]+graph[x][y+1]+graph[x+1][y+1]+graph[x][y+2]
        if max<graph[x][y]+graph[x][y+1]+graph[x+1][y+1]+graph[x+1][y+2]:
            """초록색 도형을 우측으로 뒤집고 우측으로 90도 회전"""
            max=graph[x][y]+graph[x][y+1]+graph[x+1][y+1]+graph[x+1][y+2]
        if max<graph[x][y+1]+graph[x][y+2]+graph[x+1][y]+graph[x+1][y+1]:
            """초록색 도형을 우측으로 뒤집고 우측으로 90도 회전하고 우측으로 뒤집기"""
            max=graph[x][y+1]+graph[x][y+2]+graph[x+1][y]+graph[x+1][y+1]
print(max)