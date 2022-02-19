#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int x;
    char num[21];
}cord;
cord arr[1000001];
cord list[1000001];
int N,M;

int compare(const void* first, const void* second)
{
    cord *a = (cord*)first;
    cord *b = (cord*)second;
    if (strcmp(a->num, b->num) > 0)
        return 1;
    else
        return -1;
}

int main(void) {
    int start,end,midnum;
    char op[21];

    scanf("%d %d",&N,&M);

    for(int i=0;i<N;++i) {
        scanf("%s", arr[i].num);
        arr[i].x = list[i].x = i+1;
        strcpy(list[i].num,arr[i].num);
    }

    qsort(list, N, sizeof(list[0]), compare);

    for(int i=0;i<M;++i) {
        scanf("%s",op);
        if(op[0] >= '0' && op[0] <= '9') {
            int cnt = atoi(op);
            printf("%s\n", arr[cnt-1].num);
        }
        else {
            start=0;
            end = N-1;
            while(start <= end) {
                midnum = (start + end)/2;
                if(strcmp(list[midnum].num, op) == 0) {
                    printf("%d\n", list[midnum].x);
                    break;
                }
                else if(strcmp(list[midnum].num, op) < 0) {
                    start = midnum + 1;
                }
                else {
                    end = midnum - 1;
                }
            }
        }   
    }
    return 0;
}