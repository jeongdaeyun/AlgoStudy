#include <stdio.h>
#include <string.h>
int main(void) {
    char a[100000] = {0,};
    char b[100000] = {0,};
    int c=0;
    while(1) {
        scanf("%s",a);
        if(a[0] == '0')
            break;
        int leng = strlen(a);
        
        for(int i=0;i<leng/2;++i) {
            if(a[i] == a[leng-1-i])
                c++;
        }
        if(c == leng/2)
            printf("yes\n");
        else
            printf("no\n");
        c=0;
    }

    return 0;
}