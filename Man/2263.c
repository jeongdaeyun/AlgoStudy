#include <stdio.h>

void DFS(int *iorder, int *porder, int s1, int e1, int s2, int e2) { 

	if (s1 > e1 || s2 > e2) return;
	int root = porder[e2];

	int idx = -1;
	for (int i = s1; i <= e1; i++){
		if (iorder[i] == root) {
			idx = i;
			break;
		}
	}
	int L_cnt = idx - s1;

	printf("%d ", root);
	DFS(iorder, porder, s1, idx - 1, s2, s2 + L_cnt - 1);
	DFS(iorder, porder, idx + 1, e1, s2 + L_cnt, e2 - 1);
}

int main() {
    int size;
    scanf("%d", &size);

    int iorder[size];
    int porder[size];
	for (int i = 0; i < size; i++) {
		scanf("%d", &iorder[i]);
	}
	for (int i = 0; i < size; i++) {
		scanf("%d", &porder[i]);
	}

	DFS(iorder, porder, 0, size-1, 0, size-1);
}