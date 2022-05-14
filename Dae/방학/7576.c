#include <stdio.h>

struct node {
    int x;
    int y;
}quequ[2000000];
int arr[1001][1001];
int day[1005][1005]={0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int front=0,rear=1;
int cnt=0,N,M;

int deque() {
    int nx,ny;
    while(++front < rear) {
        for(int i=0;i<4;++i) {
            nx = quequ[front].x + dx[i];
            ny = quequ[front].y + dy[i];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= M && arr[ny][nx] == 0) {
                arr[ny][nx] = 1;
                day[ny][nx] = day[quequ[front].y][quequ[front].x] + 1;
                quequ[rear].x = nx;
                quequ[rear].y = ny;
                rear++;
                cnt--;
            }
        }
    }
    if(cnt == 0)
        return day[quequ[rear-1].y][quequ[rear-1].x];
    else
        return -1;
}

int main(void) {
    scanf("%d %d",&N,&M);
    for(int i=1;i<=M;++i) {
        for(int j=1;j<=N;++j) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == 0) cnt++;
            else if(arr[i][j] == 1) {
                quequ[rear].x = j;
                quequ[rear].y = i;
                rear++;
            }
        }
    }
    int result = deque();
    printf("%d\n",result);
    return 0;
}