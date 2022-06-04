#include <stdio.h>
#include <string.h>

int N,M;
int a[101][101];
int visited[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt=0;

int dfs(int x, int y) {
    visited[x][y] = 1;

    for(int i=0;i<4;++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < N && ny < M && a[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx,ny);
        }
    }
    return 0;
}

int main(void) {
    scanf("%d %d",&M,&N);
    for(int i=0;i<M;++i) {
        for(int j=0;j<N;++j) {
            scanf("%d",&a[i][j]);
        }
    }

    int c=0;
    for(int i=0; i<M;++i) {
        for(int j=0;j<N;++j) {
            if(a[i][j] == 1 && !visited[i][j]) {
                dfs(i,j);
                c++;
            }
        }
    }
    printf("%d\n",c);
    return 0;
}