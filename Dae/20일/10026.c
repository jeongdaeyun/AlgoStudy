#include <stdio.h>
#include <string.h>
int N;
int a[100][100];
int visited[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int color, int x, int y) {
    visited[x][y] = 1;

    for(int i=0;i<4;++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < N && ny < N && a[nx][ny] == color && !visited[nx][ny]) {
            dfs(color, nx, ny);
        }
    }
    return 0;
}
int rg(int x, int y) {
    visited[x][y] = 1;

    for(int i=0;i<4;++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < N && ny < N && (a[nx][ny] == 1 || a[nx][ny] == 2) && !visited[nx][ny]) {
            rg(nx, ny);
        }
    }
    return 0;
}

int main(void) {
    scanf("%d",&N);
    char str[101];
    for(int i=0;i<N;++i) {
        scanf("%s", str);
        for(int j=0;j<N;++j) {
            if(str[j] == 'R') a[i][j] = 1;
            else if(str[j] == 'G') a[i][j] = 2;
            else a[i][j] = 3;
        }
    }

    int r=0, g=0,b=0, redg = 0;
    for(int i=0;i<N;++i) { //rgb영역의 수
        for(int j=0;j<N;++j) {
            if(a[i][j] == 1 && !visited[i][j]) {
                dfs(1, i, j);
                r++;
            }
            if(a[i][j] == 2 && !visited[i][j]) {
                dfs(2, i, j);
                g++;
            }
            if(a[i][j] == 3 && !visited[i][j]) {
                dfs(3, i, j);
                b++;
            }
        }
    }

    memset(visited, 0, sizeof(visited)); //방문한 메모리 초기회=ㅏ
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            if((a[i][j] == 1 || a[i][j] == 2) && !visited[i][j]) {
                rg(i, j);
                redg++;
            }
        }
    }

    int value1 = r + g + b;
    int value2 = redg + b;
    printf("%d %d\n",value1,value2);

    return 0;
}