#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char x[51];
}cord;

cord arr[1000001];

int compare(const void*a, const void*b) {
    
    if(strlen((char*)a) > strlen((char*)b))
        return 1;
    else if(strlen((char*)a) < strlen((char*)b))
        return -1;
    return 0;
}

int com(const void *a,const void *b) {
    return strcmp((char*)a,(char*)b);
}

int main(void) {
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i) {
        scanf("%s",arr[i].x);
    }
    qsort(arr,N,sizeof(arr[0]),com);
    qsort(arr,N,sizeof(arr[0]),compare);

    for(int i=0;i<N;++i) {
        if(strcmp(arr[i].x,arr[i+1].x) == 0) {
            continue;
        }
        printf("%s\n",arr[i].x);
    }
    return 0;
}