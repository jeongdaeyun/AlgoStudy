#include <stdio.h>
#define mod 10007

int main(void) {
    int n;
    int a[1001];
    scanf("%d",&n);
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=n;++i) {
        a[i] = (a[i-2] + a[i-1])%mod;
    }
    printf("%d\n",a[n]);
    return 0;
}