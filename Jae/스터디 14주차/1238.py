import sys
import heapq
INF=int(1e9)
n,m,x=list(map(int,sys.stdin.readline().split(' ')))
graph=[[] for _ in range(m)]
for i in range(m):
    start,end,time=list(map(int,sys.stdin.readline().split(' ')))
    graph[start].append((end,time))
def dijkstra(start):
    q=[]
    heapq.heappush(q,(0,start))
    distance[start]=0
    while q:
        dist,now=heapq.heappop(q)
        if distance[now]<dist:
            continue
        for i in graph[now]:
            cost=dist+i[1]
            if cost<distance[i[0]]:
                distance[i[0]]=cost
                heapq.heappush(q,(cost,i[0]))
    return distance
rst=[[]]
time_list=[]
for i in range(1,n+1):
    distance=[INF]*(n+1)
    rst.append(dijkstra(i))
for i in range(1,n+1):
    time_list.append(rst[i][x]+rst[x][i])
print(max(time_list))