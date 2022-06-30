#include <stdio.h>
#include <stdlib.h>

char numString[11];

int compare(const void *a, const void *b)
{
    char num1 = *(char *)a;
    char num2 = *(char *)b;

    if(num1 < num2) return 1;
    if(num1 > num2) return -1;
    return 0;
}

int main(void)
{
    scanf("%s",numString);

    qsort(numString, sizeof(numString) / sizeof(char), sizeof(char), compare);
    printf("%s\n", numString);
    return 0;
}