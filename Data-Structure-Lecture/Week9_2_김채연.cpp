#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

void name();

TreeNode* new_node(int item) {		//���ο� ��� ����
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));		//�޸� �Ҵ�
	node->key = item;		//Ű �� ����ֱ�
	node->left = node->right = NULL;		//�ڼ� ��带 NULL�� �ʱ�ȭ
	return node;
}

void inorder(TreeNode* root) {		//���� ��ȸ
	if (root) {		//�� Ʈ���� �ƴ϶�� ���� �ڵ� ����
		inorder(root->left);		//left subtree traverse
		printf(" [%d] ", root->key);
		inorder(root->right);		//left subtree traverse
	}
}

TreeNode* insert_node(TreeNode* node, int key) {		//��� �����ϴ� �Լ�
	if (node == NULL)		//Ʈ���� �����̸� insert�� ���ο� ��� ��ȯ
		return new_node(key);
	if (key < node->key)		//������ ���� ��Ʈ�� Ű������ ������ left subtree�� root�� insert ���ȣ��
		node->left = insert_node(node->left, key);
	else if (key > node->key)		//������ ���� ��Ʈ�� Ű������ ũ�� right subtree�� root�� insert ���ȣ��
		node->right = insert_node(node->right, key);
	return node;		//�ٲ� root ������ ��ȯ
}

TreeNode* min_value_node(TreeNode* node) {		//���� ������ �ܸ����(�ּڰ�) ã��
	TreeNode* current = node;
	while (current->left != NULL)		//null�� �ɶ����� ��� ���� �ڼ����� ������
		current = current->left;
	return current;
}

TreeNode* max_value_node(TreeNode* node) {		//���� �������� �ܸ����(�ִ�) ã��
	TreeNode* current = node;
	while (current->right != NULL)		//null�� �ɶ����� ��� ������ �ڼ����� ������
		current = current->right;
	return current;
}

int compare(int num, int min, int max) {		//�ش� ����� ���� �ּڰ�, �ִ밪�� ���� ���� ���� �� 
	if (abs(num - min) > abs(num - max))		//�ش� ��尪���� ���� ������ �� ���� ��尪 ��ȯ
		return max;
	else
		return min;
}

TreeNode* delete_node(TreeNode* root, int key) {		//key�� ����� ��带 ã�� �����ϰ� ���ο� root ��ȯ
	if (root == NULL)
		return root;
	else if (root->key > key)		//���� subtree���� key���� ã�� �����ϵ��� ��� ȣ��
		root->left = delete_node(root->left, key);
	else if (root->key < key)		//������ subtree���� key���� ã�� �����ϵ��� ��� ȣ��
		root->right = delete_node(root->right, key);
	else {				//������ key�� ã�Ҵٸ�
		if (root->left == NULL) {		//left���ų� �ڼ��� �ϳ� ���� ����� ���
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//�ڼ� ��尡 �� �� �ִ� ���
		TreeNode* min_temp = min_value_node(root->right);	//������ ��忡�� �ּڰ��� ���� ��� ã��
		TreeNode* max_temp = max_value_node(root->left);	//���� ��忡�� �ִ밪�� ���� ��� ã��

		printf("left subtree�� max: %d\n", max_temp->key);
		printf("right subtree�� min: %d\n", min_temp->key);

		int choose = compare(key, min_temp->key, max_temp->key);	//�ּڰ��� �ִ� �� key���� ���� ����� �� ��ȯ
		root->key = choose;		//ã�� ���� ������ ��ġ�� ����

		printf("original value:%d  new value: %d\n", key, root->key);

		//����� ���� ���� �ִ� ��� ����
		if (choose == min_temp->key)
			root->right = delete_node(root->right, min_temp->key);
		else if (choose == max_temp->key)
			root->left = delete_node(root->left, max_temp->key);
	}
	return root;		//���ο� root ��ȯ
}


int main() {
	name();

	TreeNode* root = NULL;
	char ans;
	int num;

	root = insert_node(root, 30);		//30 insert
	root = insert_node(root, 20);		//20 insert
	root = insert_node(root, 10);		//10 insert
	root = insert_node(root, 45);		//45 insert
	root = insert_node(root, 50);		//50 insert
	root = insert_node(root, 60);		//60 insert

	printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	inorder(root);		//Ʈ�� ���� ���

	while (true) {
		printf("\n\n* operation ����: Insert(I) / Delete(D) / Exit(X) : ");
		scanf(" %c", &ans);
		switch (ans) {
			case 'I':		//����ڰ� I�� �����ϸ�
				printf("Insert�� ����? ");
				scanf("%d", &num);
				insert_node(root, num);		//Insert �� �� �޾Ƽ� �Լ� ȣ��
				inorder(root);		//Ʈ�� ���
				break;
			case 'D':		//����ڰ� D�� �����ϸ�
				printf("Delete�� ����? ");
				scanf("%d", &num);
				delete_node(root, num);		//������ �� �޾Ƽ� �Լ� ȣ��
				inorder(root);		//Ʈ�� ���
				break;
			case 'X':		//����ڰ� X�� �����ϸ�
				printf("���α׷� ����\n");
				exit(1);		//���α׷� ����
			default:
				break;
		}
	}

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