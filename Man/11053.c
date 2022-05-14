#include <stdio.h>
#define max(a , b) (a > b) ? a : b

int main(void){
	int N, ret;
    scanf("%d", &N);
    
    int arr[N];
    int dp[N];
	
    for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}
	for (int i = 1; i < N; i++){
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	ret = dp[0];
	for (int i = 0; i < N-1; i++) if (ret < dp[i + 1]) ret = dp[i + 1];
	printf("%d\n", ret);
	return 0;
}