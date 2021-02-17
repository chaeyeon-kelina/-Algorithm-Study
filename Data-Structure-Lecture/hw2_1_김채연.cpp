#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
};

/*
TreeNode n0 = { 11, NULL, NULL };
TreeNode n1 = { 2, &n0, NULL };
TreeNode n2 = { 5, &n1, NULL };
TreeNode n3 = { 13, &n2, NULL };
TreeNode n4 = { 25, &n3, NULL };
TreeNode n5 = { 8, NULL, NULL };
TreeNode n6 = { 3, NULL, &n5 };
TreeNode n7 = { 21, &n4, &n6 };
TreeNode* exp = &n7;
*/

TreeNode n0 = { 10, NULL, NULL };
TreeNode n1 = { 27, &n0, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { 15, &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { 7, &n4, &n5 };
TreeNode n7 = { 55, &n3, &n6 };
TreeNode n8 = { 40, NULL, NULL };
TreeNode n9 = { 36, NULL, &n8 };
TreeNode n10 = { 20, &n7, &n9 };
TreeNode* exp = &n10;

void name();

void inorder(TreeNode* root) {		//중위 순회
	if (root) {		//빈 트리가 아니라면 밑의 코드 진행
		inorder(root->left);		//left subtree traverse
		inorder(root->right);		//right subtree traverse
	}
}

void sum_keys(TreeNode* root, int* sum) {
	if (root) {	//빈 트리가 아니라면 밑의 코드 진행
		sum_keys(root->left, sum);	    //left subtree traverse
		*sum += root->data;
//		printf("Sum of keys in binary tree: %d\n", *sum);
		sum_keys(root->right, sum);		//left subtree traverse
	}
}

void count_one_child_node(TreeNode* root, int* count) {
	if (root) {		//빈 트리가 아니라면 밑의 코드 진행
		count_one_child_node(root->left, count);
		if (root->left == NULL) {			//왼쪽 child에만 값이 있으면
			if (root->right != NULL)
				*count += 1;
		}
		else {			//오른쪽 child에만 값이 있으면
			if (root->right == NULL)
				*count += 1;
		}
		count_one_child_node(root->right, count);
	}
}

void max_value(TreeNode* root, int* max) {
	if (root) {		//빈 트리가 아니라면 밑의 코드 진행
		max_value(root->left, max);
		if (root->data > * max)				//해당 노드의 값이 max보다 크면 max값 교체
			*max = root->data;
		max_value(root->right, max);
	}
}

void min_value(TreeNode* root, int* min) {
	if (root) {		//빈 트리가 아니라면 밑의 코드 진행
		min_value(root->left, min);
		if (root->data < *min) 			//해당 노드의 값이 min보다 작으면 min값 교체
			*min = root->data;
		min_value(root->right, min);
	}
}

int main() {
	name();			//전공, 이름, 학번 출력

	int sum = 0, count = 0;
	int max = INT_MIN, min = INT_MAX;
	sum_keys(exp, &sum);		//키 값의 합계
	printf("Sum of keys in binary tree: %d\n", sum);
	count_one_child_node(exp, &count);		//자식노드를 한 개 값는 노드의 수
	printf("Num of one child nodes: %d\n", count);
	max_value(exp, &max);		//최대 키 값
	printf("Max value: %d\n", max);
	min_value(exp, &min);		//최소 키 값
	printf("Min value: %d\n", min);
	return 0;
}

void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}