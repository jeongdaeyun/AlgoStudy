#include <stdio.h>

void merge(int *arr, int lo, int hi, int mid, int size){
    int i, j, tmp = 0;
    int tmparr[size];
    i = lo;
    j = mid+1;

    while(i <= mid && j <= hi){
        if(arr[i] < arr[j]) tmparr[tmp++] = arr[i++];
        else tmparr[tmp++] = arr[j++];
    }
    for(;i <= mid;) tmparr[tmp++] = arr[i++];
    for(;j <= hi;) tmparr[tmp++] = arr[j++];

    for(int k = 0; k < size; k++) arr[lo+k] = tmparr[k];
}

void mergeSort(int *arr, int lo, int hi){
    if(lo < hi){
        int mid = (lo+hi)/2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid+1, hi);
        merge(arr, lo, hi, mid, hi-lo+1);
    }
}

int main(void){
    int arrSize, temp, modeArr[2], modeCnt = 0;
    scanf("%d", &arrSize);

    int arr[arrSize], ret[4] = {0,};
    for(int i = 0; i < arrSize; i++){
        scanf("%d", &arr[i]);
        ret[0] += arr[i];
    }
    temp = (ret[0] * 10 / arrSize)%10;

    if(temp >= 5){
        ret[0] /= arrSize;
        ret[0]++;
    }
    else if(temp <= -5){
        ret[0] /= arrSize;
        ret[0]--;
    }
    else ret[0] /= arrSize;

    mergeSort(arr, 0, arrSize-1);

    ret[1] = arr[(arrSize)/2];
    modeArr[0] = -4001;
    modeArr[1] = 4001;

    for(int i = arrSize-1; i >= 0;){
        if(modeArr[1] != arr[i]){
            int tempCnt = 1;
            for(int j = i-1; j >= 0; j--){
                if(arr[i] == arr[j]) tempCnt++;
                else {
                    break;
                }
            }
            if(tempCnt > modeCnt){
                modeCnt = tempCnt;
                modeArr[0] = -4001;
                modeArr[1] = arr[i];
            }
            else if(tempCnt == modeCnt){
                modeArr[0] = modeArr[1];
                modeArr[1] = arr[i];
            }
            i -= tempCnt;
        }
    }
    
    if(modeArr[0] == -4001) ret[2] = modeArr[1];
    else ret[2] = modeArr[0];
    
    ret[3] = arr[arrSize-1] - arr[0];

    for(int i = 0; i < 4; i++){
        printf("%d\n", ret[i]);
    }
}