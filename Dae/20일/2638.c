#include <stdio.h>

int N,M;
int a[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int molt() {
    int cnt=0;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(a[i][j] == 1 || a[i][j] == 2) {
                a[i][j] = 1;
                cnt++;
            }
            else 
                a[i][j] = 0;
        }
    }
    return cnt;
}

void dfs(int x, int y) {
    a[x][y] = -1;

    for(int i=0;i<4;++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if(a[nx][ny] > 0) 
                a[nx][ny]++;
            else if(a[nx][ny] == 0) 
                dfs(nx,ny);
        }
    }
}


int main(void) {
    int k;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            scanf("%d",&a[i][j]);
        }
    }
    
    for(k=0;molt();++k) dfs(0,0);
    printf("%d\n",k);
    
    return 0;
}