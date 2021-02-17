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

void inorder(TreeNode* root) {		//���� ��ȸ
	if (root) {		//�� Ʈ���� �ƴ϶�� ���� �ڵ� ����
		inorder(root->left);		//left subtree traverse
		inorder(root->right);		//right subtree traverse
	}
}

void sum_keys(TreeNode* root, int* sum) {
	if (root) {	//�� Ʈ���� �ƴ϶�� ���� �ڵ� ����
		sum_keys(root->left, sum);	    //left subtree traverse
		*sum += root->data;
//		printf("Sum of keys in binary tree: %d\n", *sum);
		sum_keys(root->right, sum);		//left subtree traverse
	}
}

void count_one_child_node(TreeNode* root, int* count) {
	if (root) {		//�� Ʈ���� �ƴ϶�� ���� �ڵ� ����
		count_one_child_node(root->left, count);
		if (root->left == NULL) {			//���� child���� ���� ������
			if (root->right != NULL)
				*count += 1;
		}
		else {			//������ child���� ���� ������
			if (root->right == NULL)
				*count += 1;
		}
		count_one_child_node(root->right, count);
	}
}

void max_value(TreeNode* root, int* max) {
	if (root) {		//�� Ʈ���� �ƴ϶�� ���� �ڵ� ����
		max_value(root->left, max);
		if (root->data > * max)				//�ش� ����� ���� max���� ũ�� max�� ��ü
			*max = root->data;
		max_value(root->right, max);
	}
}

void min_value(TreeNode* root, int* min) {
	if (root) {		//�� Ʈ���� �ƴ϶�� ���� �ڵ� ����
		min_value(root->left, min);
		if (root->data < *min) 			//�ش� ����� ���� min���� ������ min�� ��ü
			*min = root->data;
		min_value(root->right, min);
	}
}

int main() {
	name();			//����, �̸�, �й� ���

	int sum = 0, count = 0;
	int max = INT_MIN, min = INT_MAX;
	sum_keys(exp, &sum);		//Ű ���� �հ�
	printf("Sum of keys in binary tree: %d\n", sum);
	count_one_child_node(exp, &count);		//�ڽĳ�带 �� �� ���� ����� ��
	printf("Num of one child nodes: %d\n", count);
	max_value(exp, &max);		//�ִ� Ű ��
	printf("Max value: %d\n", max);
	min_value(exp, &min);		//�ּ� Ű ��
	printf("Min value: %d\n", min);
	return 0;
}

void name()
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}