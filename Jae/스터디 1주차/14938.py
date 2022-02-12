INF=1e9
"""무한=10억"""
n,m,r=list(map(int,input().split(' ')))
"""지역의 개수 n, 수색범위 m, 길의 개수 r"""
t=list(map(int,input().split(' ')))
"""각 구역의 아이템 개수 t"""
adj_mat=[[INF]*(n) for _ in range(n)]
for _ in range(r):
    start,end,length=list(map(int,input().split(' ')))
    adj_mat[start-1][end-1]=min(adj_mat[start-1][end-1],length)
    adj_mat[end-1][start-1]=min(adj_mat[end-1][start-1],length)
    """이동 최소비용을 저장할 2차원 배열"""
rst=[]
"""max값을 뽑기 위한 리스트 하나 생성"""
for k in range(n):
    for i in range(n):
        for j in range(n):
            if(i==j):
                adj_mat[i][j]=0
            else:
                adj_mat[i][j]=min(adj_mat[i][j],adj_mat[i][k]+adj_mat[k][j])
                """플로이드 와샬"""
for row in adj_mat:
    mv=0
    for _ in range(n):
        if(row[_]<=m):
            if(row[_] in row):
                mv+=t[_]
                rst.append(mv)
print(max(rst))