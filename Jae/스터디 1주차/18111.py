import sys
n,m,b=list(map(int,sys.stdin.readline().split(' ')))
graph=[[int(x) for x in input().split()] for y in range(n)]
"""2차원 배열 선언 및 삽입"""
time=1e9
h=0
for i in range(257):
    """땅의 높이는 256보다 작거나 같고 0일 수도 있기 때문"""
    top=0
    bot=0
    for x in range(n):
        for y in range(m):
            if(graph[x][y]<i):
                """현재 높이인 i보다 graph[x][y]가 낮으면"""
                bot+=i-graph[x][y]
                """인벤토리에서 써야 할 블록 수"""
            else:
                top+=graph[x][y]-i
                """인벤토리를 채우는 블록 수, graph[x][y]-i만큼 인벤토리에 채운다"""
    if(b+top<bot):
        """인벤토리에 있는 블록 수+인벤토리에 채우게 될 블록 수가 인벤토리에서 꺼내 써야 할 블록 수 보다 적으면"""
        continue
    else:
        worktime=2*top+bot
        if(worktime<=time):
            time=worktime
            h=i
print(time,h)