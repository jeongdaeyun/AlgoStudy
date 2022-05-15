#include <stdio.h>
int graph[10001][10001];    // 인접행렬로 구현한 그래프 
int visited[100001];        // 방문 여부 체크 
int max = 0;
int node,N;

void clear(int N) {
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j)
            graph[i][j] = 0;
        visited[i] = 0;
    }
}

int dfs(int cur){
    int i,value;
    visited[cur] = 1;    // 현재 노드 방문 체크 
    
    for(i=1; i<=N; i++){    // 모든 인접한 노드 체크 
        if(graph[cur][i] > 0 && visited[i] == 0){    // 인접하고 방문하지 않은 노드라면 
            node = graph[cur][i] + dfs(i);
            if(max < node) {
                max = node;
                value = i;
            }
        }
    }
}


int main(void) {
    int j;
    scanf("%d",&N);
    int dist[100]={0,};
    for (int i=0; i < N; ++i) {
        for (int j=0; j<N; ++j) {
            graph[i][j] = 0;
        }
        
    }
    
    for(int i=0;i<N;++i) {
        int num, n1, n2;
        scanf("%d",&num);
        scanf("%d",&n1);
        while(n1 != -1) {
            scanf("%d",&n2);
            graph[num][n1] = n2;     
            scanf("%d",&n1);
        }
    }  
    int first = dfs(5);
    int seco = dfs(first);
    printf("%d\n", first);
    
    return 0;
}