#include <stdio.h>
long long a[100001]={0,};
int fibo(int n) {
    if(n <= 1) return n;
    else if(a[n] != 0) return a[n];
    else return a[n] = fibo(n-1) + fibo(n-2);
}

int main(void) {
    int N;
    scanf("%d",&N);
    printf("%d\n",fibo(N));
    return 0;
}