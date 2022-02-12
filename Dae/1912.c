#include <stdio.h>
int max(int a, int b) {
    if(a>b) return a;
    else return b;
}
int main(void) {
    int N,a[100001]={0,};
    int m=-1001;
    scanf("%d",&N);
    for (int i=0;i<N;++i) {
        scanf("%d",&a[i]);
    }
    a[1] = max(a[1],a[1]+a[0]);
    for(int i=2;i<N;++i) {
        a[i] = max(a[i], a[i]+a[i-1]);
        if(a[i] > m) m = a[i];
    }
    if(m < a[0]) m=a[0];
    if(m < a[1] && N>1) m=a[1];
    printf("%d\n",m);
    return 0;
}