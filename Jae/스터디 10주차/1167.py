"""트리의 지름은 임의의 한 점 x를 선택하고, x에서 가장 먼 정점 y를 찾은 후, 다시 y에서 가장 먼 정점 z를 찾는다. 여기서 y와 z의 거리가 트리의 지름이다."""
import sys
from collections import deque
v=int(sys.stdin.readline())
graph=[[]for _ in range(v+1)]
for _ in range(v):
    path=list(map(int,sys.stdin.readline().split(' ')))
    for i in range(1, len(path)-1, 2):
        """0번은 지정한 노드이고, 1번부터 정점 번호가 나오는데 2칸씩 찾아야지 연결된 정점번호를 알 수 있다. len(path)-1을 해주는 이유는 마지막에 -1이 있기 때문이다."""
        graph[path[0]].append((path[i],path[i+1]))
        """path[i]는 정점, path[i+1]는 그 정점에 해당하는 거리"""
print(graph)
def bfs(start):
    visited=[-1]*(v+1)
    """방문 하지 않은 곳은 -1"""
    q=deque()
    q.append(start)
    visited[start]=0
    max_value=[0,0]
    """거리가 가장 먼 트리의 지름과 정점을 저장"""
    while q:
        a=q.popleft()
        """현재 기준 정점"""
        for new_node,w in graph[a]:
            if(visited[new_node]==-1):
                """연결된 정점을 만나지 않았을 경우"""
                visited[new_node]=visited[a]+w
                """탐색하기까지 걸린 간선의 거리"""
                q.append(new_node)
                if max_value[0]<visited[new_node]:
                    max_value=visited[new_node], new_node
    return max_value
dis, f_node = bfs(1)
"""1을 기준으로 가장 먼 노드 y탐색"""
dis, f_node = bfs(f_node)
"""y를 기준으로 가장 먼 노드 z탐색"""
print(dis)