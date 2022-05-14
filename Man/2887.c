#include <stdio.h>
#define limit 1234567890

typedef struct {
    int planet1;
    int planet2;
    int x;
}xyz;

void merge(xyz *arr, int lo, int hi, int mid, int size){
    int i, j, tmp = 0;
    xyz tmparr[size];
    i = lo;
    j = mid+1;

    while(i <= mid && j <= hi){
        if(arr[i].x < arr[j].x) tmparr[tmp++] = arr[i++];
        else tmparr[tmp++] = arr[j++];
        
    }
    for(;i <= mid;) tmparr[tmp++] = arr[i++];
    for(;j <= hi;) tmparr[tmp++] = arr[j++];

    for(int k = 0; k < size; k++) arr[lo+k] = tmparr[k];
}

void mergeSort(xyz *arr, int lo, int hi){
    if(lo < hi){
        int mid = (lo+hi)/2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid+1, hi);
        merge(arr, lo, hi, mid, hi-lo+1);
    }
}

int abs(int a){
    if(a < 0)a = -a;
    return a;
}

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

int parents(int *node, int i){
    printf("cccc\n");
    if(node[i] != i) return parents(node, node[i]);
    return node[i];
}

int main(void){
    int size;
    scanf("%d", &size);
    int ret = 0, node[size];

    for(int i = 0; i < size; i++) node[i] = i;

    xyz xarray[size], yarray[size], zarray[size], karray[3*(size-1)];
    for(int i = 0; i < size; i++){
        scanf("%d%d%d", &xarray[i].x, &yarray[i].x, &zarray[i].x);
        xarray[i].planet1 = yarray[i].planet1 = zarray[i].planet1 = i;
    }

    mergeSort(xarray, 0, size-1);
    mergeSort(yarray, 0, size-1);
    mergeSort(zarray, 0, size-1);

    for(int i = 0; i < size-1; i++){
        karray[i].x = abs(xarray[i].x - xarray[i+1].x);
        karray[i].planet1 = i;
        karray[i].planet2 = i+1;
    }
    for(int i = 0; i < size-1; i++){
        karray[i+size-1].x = abs(yarray[i].x - yarray[i+1].x);
        karray[i].planet1 = i;
        karray[i].planet2 = i+1;
    }
    for(int i = 0; i < size-1; i++){
        karray[i+2*size-2].x = abs(zarray[i].x - zarray[i+1].x);
        karray[i].planet1 = i;
        karray[i].planet2 = i+1;
    }
    
    mergeSort(karray, 0, 3*(size-1)-1);
 
    for(int i = 0; i < 3*(size-1); i++){
        printf("c\n");
        if(parents(node, karray[i].planet1) != parents(node, karray[i].planet2)){
            printf("k\n");
            ret += karray[i].x;
            node[karray[i].planet2] = karray[i].planet1;
        }
        printf("e\n");
    }
    printf("%d\n", ret);
    return 0;
}