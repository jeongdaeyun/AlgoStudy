#include <stdio.h>
int T;
long long p[101] = {0,};

long long pado(int a) {
    for(int i=6;i<=a;++i) {
        p[i] = p[i-1] + p[i-5];
    }
    return p[a];
}

int main(void) {
    int a;
    p[3] = p[1] = p[2] = 1;
    p[5] = p[4] = 2;
    scanf("%d",&T);
    for(int i=0;i<T;++i) {
        scanf("%d",&a);
        printf("%lld\n", pado(a));
    }
    return 0;
}