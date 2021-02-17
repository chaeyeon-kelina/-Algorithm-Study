#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

/*  test 1
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { 15, &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { 7, &n4, &n5 };
TreeNode n7 = { 30, &n3, &n6 };
TreeNode* exp = &n7;
*/

TreeNode n1 = { 1, NULL, NULL };			//test2 Ʈ�� ���°�
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { 15, &n1, &n2 };
TreeNode n7 = { 30, &n3, NULL };
TreeNode* exp = &n7;

void name();		//�� ���� ����ϴ� �Լ�

void inorder(TreeNode* root) {		//���� ��ȸ
	if (root) {		//�� Ʈ���� �ƴ϶�� ���� �ڵ� ����
		inorder(root->left);		//left subtree traverse
		printf(" [%d] ", root->data);
		inorder(root->right);		//left subtree traverse
	}
}

int get_node_count(TreeNode* exp) {		//��� ���� ���� �Լ�
	if (exp == NULL)
		return 0;
	else
		return get_node_count(exp->left) + get_node_count(exp->right) + 1;		//���� �ڼճ�� ���� + ������ �ڼճ�� ���� + ��Ʈ ���
}

int get_height(TreeNode* exp) {		//Ʈ�� ���� ���� �Լ�
	if (exp == NULL)
		return 0;
	else {
		int l_height = get_height(exp->left);		//���� �ڼ� ����� ����
		int r_height = get_height(exp->right);		//������ �ڼ� ����� ����
		if (l_height >= r_height)		//�� ���� �ڼ� ����� ���� + 1(��Ʈ) ��ȯ
			return l_height + 1;		
		else
			return r_height + 1;
	}
}

int get_leaf_count(TreeNode* exp) {		//�ܸ� ��� ���� ���� �Լ�
	if (exp == NULL)
		return 0;
	else {
		if (exp->left == NULL && exp->right == NULL)		//���ʰ� ������ ��� �ڼ� ��尡 ������
			return 1;
		else
			return get_leaf_count(exp->left) + get_leaf_count(exp->right);
	}
}

int balanced_tree(TreeNode* exp) {		//Ʈ���� �뷱�� �˻�
	TreeNode* node = exp->left;		
	int l_height = get_height(node);		//���� ����� ���� �˻�
	node = exp->right;
	int r_height = get_height(node);		//������ ����� ���� �˻�

	if (abs(l_height - r_height) > 1)		//���ʰ� �������� ���̰� 1 �ʰ����
		return 0;		
	else				//���ʰ� �������� ���̰� 1 ���϶��
		return 1;
}

void get_greater_number(TreeNode* exp, int num) {		//����ڰ� �Է��� ������ �� ū �� ����ϴ� �Լ�
	if (exp) {
		get_greater_number(exp->left, num);
		if (exp->data > num)		//������ȸ�� ���� �˻��ϴٰ� ����� ���� �־��� ������ ũ�� ���
			printf(" %d", exp->data);
		get_greater_number(exp->right, num);
	}
}

int main() {
	name();

	int num;

	inorder(exp);		//Ʈ�� ���� ���
	
	printf("\nNumber of nodes in tree: %d\n", get_node_count(exp));		//��� ����
	printf("Height of the tree: %d\n", get_height(exp));		//Ʈ���� ����
	printf("Number of leafs in tree: %d\n", get_leaf_count(exp));		//�ܸ� ��� ����
	printf("Balanced tree? ");		//Ʈ�� �뷱�� �˻�
	if (balanced_tree(exp) == 1)			//���ʰ� �������� ���̰� 1 ���϶��
		printf("Yes\n");		//"Yes" ���
	else
		printf("No\n");
	
	printf("Input a number to check: ");
	scanf("%d", &num);
	printf("numbers greater than %d:", num);
	get_greater_number(exp, num);		//�־��� ������ �� ū ����� �� ���

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