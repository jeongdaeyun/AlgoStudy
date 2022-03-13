#include <stdio.h>

int min(int a, int b) {
    if(a>b) return b;
    else return a;
}

int value(int K, int N) {
    if(K <= N)
        return N-K;
    else if(K == 1) 
        return 1;
    else if(K%2 == 1)
        return (1 + min(value(K-1,N),value(K+1,N)));
    else
        return min(K-N, 1 + value(K/2,N));
}

int main(void) {
    int N,K;
    scanf("%d %d",&N,&K);
    printf("%d\n",value(K,N));
    return 0;
}