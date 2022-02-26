#include <stdio.h>
int inorder[100000], postorder[100000];
void preorder(int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
	int i;
	if(postorder_left <= postorder_right) {
		int head = postorder[postorder_right];
		printf("%d ", head);
		for (i=inorder_left;inorder[i] != head;++i);
		int left_num = i - inorder_left;
		int right_num = inorder_right - i;
		preorder(inorder_left, inorder_left + left_num - 1, postorder_left , postorder_left + left_num - 1);
		preorder(inorder_right - right_num + 1, inorder_right, postorder_right - right_num, postorder_right - 1);
	}
}
int main(void) {
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; ++i)
		scanf("%d", &inorder[i]);
	for (i=0; i<n; ++i)
		scanf("%d", &postorder[i]);
	preorder(0, n-1, 0, n-1);
	return 0;
}
