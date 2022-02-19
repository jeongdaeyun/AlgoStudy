import sys
su=int(sys.stdin.readline())
"""노드 개수"""
network=int(sys.stdin.readline())
"""간선 개수"""
graph=[]
def bfs(graph):
    """최상위 노드부터 시작해서 다음노드를 모두 탐색, 그 다음 노드를 모두 탐색"""
    visit=list()
    queue=list()
    """visit와 queue 초기화"""

    queue.append(1)
    """탐색하는 수가 1이기 때문에 1부터 q에 삽입"""
    while queue:
        """방문할 노드가 없을 때 까지 반복"""
        node=queue.pop(0)
        """맨 앞 노드 pop"""
        if node not in visit:
            """해당 노드가 visit에 없다면"""
            visit.append(node)
            """visit에 node를 append"""
            queue.extend(graph[node])
            """queue에 해당 노드의 자식 노드 추가"""
    return visit
graph=[[]for _ in range(su+1)]
"""노드+1개의 []로 된 리스트 생성"""
visited=[False]*(su+1)
"""일단 만나지 않았으니까 false로 둔다"""
for i in range(network):
    a,b=map(int,sys.stdin.readline().split(' '))
    graph[a].append(b)
    graph[b].append(a)
rst=bfs(graph)
for k in rst:
    """rst에 1이 있으면 안되므로 제거"""
    if k==1:
        rst.remove(1)
    else:
        continue
print(len(rst))
"""dfs는 깊이우선 -> 한 쪽 방향만, 재귀와 반복 방식: 반복은 스택 사용"""