#include <stdio.h>
#define INF 1234567890

int n = 0;
int buildings[50] = {0};
int max_count = 0;
int count = 0;
double min_val, max_val, left, right;

int main(void)
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&buildings[i]);
    }
    for(int i = 0; i < n; i++)
    {
        count = 0;
        min_val = INF;
        for (int j = i-1; j >= 0; j--)
        {
            left = ((double)(buildings[i] - buildings[j])) / ((double)(i-j));
            if(min_val > left)
            {
                count += 1;
                min_val = left;
            }
        }
        max_val = -INF;
        for (int j = i+1; j < n; j++)
        {
            right = ((double)(buildings[j] - buildings[i])) / ((double)(j-i));
            if(max_val < right)
            {
                count += 1;
                max_val = right;
            }
        }
        if(count > max_count)
        {
            max_count = count;
        }
    }
    printf("%d",max_count);
}