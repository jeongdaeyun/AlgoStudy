#include <stdio.h>

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int main(void) {
    int arr[10001]={0,};
    int length[10001]={0,};
    int n,ma=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&arr[i]);
    }

    for(int k=0;k<n;++k) {
        length[k]=1;
        for(int i=0;i<k;++i) {
            if(arr[i] < arr[k]) {
                length[k] = max(length[k], length[i]+1);
            }
        }
    }
    for(int i=0;i<n;++i) {
        if(ma < length[i]) ma = length[i];
    }
    printf("%d\n",ma);
    return 0;
}