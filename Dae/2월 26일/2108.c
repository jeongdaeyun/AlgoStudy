#include <stdio.h>
#include <stdlib.h>
int compare(const void* first, const void* second) {
    int num1 = *(int *)first;
    int num2 = *(int *)second;
    if (num1 > num2) return 1;
    else return -1;
}

int maxf(int *arr, int data) {
    int maxx = arr[0];
    for(int i=0;i<data;++i) {
        if(maxx < arr[i]) 
            maxx = arr[i];
    }
    return maxx;
}

int main(void) {
    int N,sum=0,value=0,c=0;
    int a[500001]={0,};
    int b[8001]={0,};
    scanf("%d",&N);
    for(int i=0;i<N;++i)  {
        scanf("%d",&a[i]);
        sum += a[i];
        b[a[i] + 4000]++;
    }

    for(int i=0;i<8001;++i) {
        if(maxf(b, 8001) == b[i]) 
            c++;
    }

    for(int i=0;i<8001;++i) {
        if(c == 1) {
            if(maxf(b,8001) == b[i]) {
                value = i - 4000;
                break;
            }
        }
        else {
            if(maxf(b,8001) == b[i]) {
                if(c == 0) {
                    value = i - 4000;
                    break;
                }
                else
                    c=0;
            }
        }
    }
    qsort(a ,N, sizeof(a[0]), compare);
    if((double)sum/N < 0 && (double)sum/N > -1)
        printf("0\n");
    else printf("%.f\n",(double)sum/N);
    printf("%d\n",a[N/2]);
    printf("%d\n",value);
    printf("%d\n",a[N-1]-a[0]);
    return 0;
}