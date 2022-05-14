#include <stdio.h>
#include <string.h>
int main(void) {
    char arr[1000001]={0,};
    scanf("%s",arr);
    char temp;
    int x = strlen(arr);
    for(int i=0;i<x;++i) {
        for(int j=0;j<x;++j) {
            if(arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("%s\n",arr);
    return 0;
}