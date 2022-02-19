#include <stdio.h>
#define mod 1000000
typedef struct node {
    int x;
    int y;
    int z;
}q;
q quequ[2000000];
int arr[101][101][101];
int visit[101][101][101]={0,};
int dy[6] = {1,-1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int front,rear,max;
int cnt=0,N,M,H;

void enque(int x, int y, int z) {
    q temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    quequ[rear++%mod] = temp;
}
q deque() {
    return quequ[front++%mod];
}
int isEmpty() {
    if(front == rear) return 0;
    else return 1;
}
int bfs() {
    int nx,ny,nz;
    while(isEmpty()) {
        q pop = deque();
        for(int i=0;i<6;++i) {
            nx = pop.x + dx[i];
            ny = pop.y + dy[i];
            nz = pop.z + dz[i];

            if(nx >=1 && nx<=M && ny>=1 && ny <= N && nz >=1 && nz <= H) {
                if(arr[nx][ny][nz] == 0 && visit[nx][ny][nz]) {
                    visit[nx][ny][nz] = visit[pop.x][pop.y][pop.z] +1;
                    enque(nx,ny,nz);
                    cnt--;
                }
                if(visit[nx][ny][nz] > max) max = visit[nx][ny][nz];
            }
        }
    } 
    if(cnt == 0) return max;
    else return -1;
}
int main(void) {
    scanf("%d %d %d",&N,&M,&H);
    for(int k=1;k<=H;++k) {
        for(int i=1;i<=M;++i) {
            for(int j=1;j<=N;++j) {
                scanf("%d",&arr[i][j][k]);
                if(arr[i][j][k] == 0) cnt++;
                else if(arr[i][j][k] == 1) {
                    enque(i,j,k);
                    visit[i][j][k] = 1;
                }
            }
        }
    }
    if(cnt == 0) printf("0\n");
    else printf("%d\n", bfs());
    return 0;
}