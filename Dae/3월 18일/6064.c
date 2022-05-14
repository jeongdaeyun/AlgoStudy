#include <stdio.h>

int main(void) {
    int M,N,x,y,T,count;
    scanf("%d",&T);
    for(int i=0;i<T;++i) {
        scanf("%d %d %d %d",&M,&N,&x,&y);
        count=0;
        int x1=1,y1=1;
        while (1) {
            if(x == x1 && y == y1) {
                printf("%d\n",count+1);
                break;
            }
            else if(x1 == M && y1 == N) {
                printf("-1\n");
                break;
            }
            if(x1 == M) {
                x1 = 1;
                y1++;
                count++;
            }
            if(x == x1 && y == y1) {
                printf("%d\n",count+1);
                break;
            }
            if(y1 == N) {
                y1 = 1;
                x1++;
                count++;
            }
            if(x == x1 && y == y1) {
                printf("%d\n",count+1);
                break;
            }
            x1++;
            y1++;
            count++;
        }
    }
    return 0;
}