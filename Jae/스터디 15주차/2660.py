import sys
INF=int(1e9)
number=int(sys.stdin.readline())
graph=[[INF]*(number+1) for _ in range(number+1)]
"""최단경로를 담는 배열"""
while(True):
    n1,n2=list(map(int,sys.stdin.readline().split(' ')))
    if(n1==-1 and n2==-1):
        break
    graph[n1][n2]=1
    graph[n2][n1]=1
for k in range(1,number+1):
    """거치는 점"""
    graph[k][k]=0
    for i in range(1,number+1):
        """시작 점"""
        for j in range(1,number+1):
            """끝 점"""
            graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j])
            """k를 거쳤을 때의 경로가 더 적은 경로"""
min_score=INF
rst=[]
r=[]
for i in range(1,number+1):
    rst.append(max(graph[i][1:]))
    min_score=min(min_score, max(graph[i][1:]))
print(min_score, rst.count(min_score))
"""min_score=회장 후보의 점수, rst.count(min_score)=후보의 수"""
for i in range(len(rst)):
    if(rst[i]==min_score):
        r.append(i)
for i in r:
    i+=1
    print(i,end=" ")