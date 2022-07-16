#include <stdio.h>

int N, c=0, queen[30], check;

int abs(int a) {
    if(a >= 0) return a;
    else return -a;
}

void search(int num) {
    if(num == N+1) c++;
    for(int i=1;i<=N;++i) {
        queen[num] = i;
        check = 1;
        for(int j=1;j<num;++j) {
            if(i == queen[j] || abs(i-queen[j]) == num - j) //처음은 열 뒤에는 대각선
                check = 0;
        }
        if(check) 
            search(num+1);
    }
}

int main(void) {
    scanf("%d",&N);
    search(1);
    printf("%d\n",c);
    return 0;
}