#include <stdio.h>
int main(void)
{
    int T,M,N,x,y;
    scanf("%d",&T);
    for(i=0;i<T;++i) {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        int p = M*N;
        int count=-1;
        if(x<=M && y<=N) {
            for(int j=x; j<=p; j+=M) {
                if((j-1)%N+1 == y) {
                    count = j;
                    break;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}