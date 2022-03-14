#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}cord;


int compare(const void* first,const void* second) {
    cord* a = (cord*)first;
    cord* b = (cord*)second;

    if(a->y < b->y)
        return -1;
    else if(a->y > b->y)
        return 1;
    else {
        if(a->x < b->x)
            return -1;
        else
            return 1;
    }
    return 0;
}

int main(void) {
    int n;
    cord* arr;
    scanf("%d",&n);
    arr =(cord*)malloc(n*sizeof(cord));
    for(int i=0;i<n;++i) {
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }

    qsort(arr,n,sizeof(arr[0]),compare);

    for(int i=0;i<n;++i) {
        printf("%d %d\n",arr[i].x,arr[i].y);
    }
    return 0;
}