#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>
#include <math.h>
#include <string.h>
int min(int x, int y) {
    if(x > y) return y;
    else return x;
}

int karatsuba(int a,int b) {
    if(a<10 || b<10) 
        return a*b;

    int m;
    m = min((int)(log10(a)+ 1),(int)(log10(b) + 1));
    m /= 2;

    int first1,end1;
    first1 = a / pow(10,m);
    end1 = a % (int)pow(10,m);
    int first2,end2;
    first2 = b / pow(10,m);
    end2 = b % (int)pow(10,m);

    int z0 = karatsuba(end1, end2);
    int z1 = karatsuba((first1 + end1), (first2 + end2));
    int z2 = karatsuba(first1, first2);

    return (z2 * pow(10, (m*2)) + ((z1 - z2 - z0) * pow(10,m)) + z0);
}

int main(void) {
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    printf("%d\n", karatsuba(num1, num2));
    return 0;
}