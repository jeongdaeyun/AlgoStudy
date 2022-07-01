#include <stdio.h>

long ww[102][102][102];

long w(long a, long b, long c) {

    if(a <=0 || b <= 0 || c <= 0) return 1;

    if(ww[a][b][c] == 0) {
        if(a > 20 || b > 20 || c > 20) return ww[a][b][c] = w(20, 20, 20);
        else if(a < b && b < c)
            return ww[a][b][c] = (w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c));
        else
            return ww[a][b][c] = (w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1));
    }
    else
        return ww[a][b][c];
}


int main(void) {
    long a,b,c;
    while(1) {
        scanf("%ld %ld %ld",&a,&b,&c);
        if(a == -1 && b==-1 && c==-1) break;
        printf("w(%ld, %ld, %ld) = %ld\n",a,b,c,w(a,b,c));
    }
    return 0;
}