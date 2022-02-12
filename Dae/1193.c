#include <stdio.h>
int main(void) {
    int a,n,x,i;
    scanf("%d",&x);
    if(x == 1)
        printf("1/1\n");
    else  {
        for(i=3;i<=x+1;++i) {
            if(x <= i*(i-1)/2){
                n = i;
                a = i*(i-1)/2 - x;
                break;
            }
        }
        if(n%2 == 0)
            printf("%d/%d\n",1+a,(n-a-1));
        else    
            printf("%d/%d\n",(n-a-1),1+a);
    }
    
    return 0;
}