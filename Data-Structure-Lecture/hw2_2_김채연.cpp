#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct TreeNode {
	char key[SIZE];
	struct TreeNode* left, * right;
};

void name();

void print_inorder(TreeNode* root) {			//inorder�� ���ĵ� Ʈ�� ���
	if (root) {	//�� Ʈ���� �ƴ϶�� ���� �ڵ� ����
		print_inorder(root->left);		//left subtree traverse
		printf("%s\n", root->key);
		print_inorder(root->right);	   //right subtree traverse
	}
}

TreeNode* insert_node(TreeNode* node, const char* item) {
	int i = 1;
	if (node == NULL){ 	//Ʈ���� �����̸� insert�� ���ο� ��� ��ȯ
		TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));		//�޸� �Ҵ�
		strcpy(p->key, item);
		p->left = p->right = NULL;
		return p;
	}
	if (strncmp(node->key, item, strlen(item)) > 0)		//(�ƽ�Ű�ڵ� ��) ����� �� > item �̸� left subtree�� root�� insert ���ȣ��
		node->left = insert_node(node->left, item);
	else if (strncmp(node->key, item, strlen(item)) < 0)			//(�ƽ�Ű�ڵ� ��) ����� �� < item �̸� right subtree�� root�� insert ���ȣ��
		node->right = insert_node(node->right, item);
	return node;
}

TreeNode* min_value_node(TreeNode* node) {		//���� ������ �ܸ����(�ּڰ�) ã��
	TreeNode* current = node;
	while (current->left != NULL)		//null�� �ɶ����� ��� ���� �ڼ����� ������
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* node, char *item) {
	if (node == NULL)
		return node;
	else if (strncmp(node->key, item, strlen(item)) > 0)		//(�ƽ�Ű�ڵ� ��) ����� �� > item �̸� left subtree�� root�� delete ���ȣ��
		node->left = delete_node(node->left, item);
	else if (strncmp(node->key, item, strlen(item)) < 0)			//(�ƽ�Ű�ڵ� ��) ����� �� < item �̸� right subtree�� root�� delete ���ȣ��
		node->right = delete_node(node->right, item);
	else {			//ã���� ���
		if (node->left == NULL) {		//left���ų� �ڼ��� �ϳ� ���� ����� ���
			TreeNode* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			TreeNode* temp = node->left;
			free(node);
			return temp;
		}
		//�ڼ� ��尡 �� �� �ִ� ���
		TreeNode* temp = min_value_node(node->right);	//������ ��忡�� �ּڰ��� ���� ��� ã��
		strcpy(node->key, temp->key);	//ã�� ���� ������ ��ġ�� ����
		node->right = delete_node(node->right, temp->key);
	}
	return node;		//���ο� root ��ȯ
}

TreeNode* search(TreeNode* node, char* item) {
	if (node == NULL)
		return NULL;
	if (strcmp(node->key, item))		//ã���� �ϴ� ���� ��ȯ
		return node;
	else if (strncmp(node->key, item, strlen(item)) > 0)		
		return search(node->left, item);		//left subtree �ٽ� search
	else
		return search(node->right, item);		//right subtree �ٽ� search
}

int main() {
	name();			//����, �̸�, �й� ���
	
	int ans;
	char word[SIZE];
	TreeNode* root = NULL;
	//�ʱ� �� ���� �ֱ�
	root = insert_node(root, "blueberry");
	root = insert_node(root, "apple");
	root = insert_node(root, "banana");
	root = insert_node(root, "kiwi");
	root = insert_node(root, "orange");
	root = insert_node(root, "pear");

	while (true) {
		printf("\n* Choose operation(1.insert 2.delete 3.search 4.print 5.exit):");
		scanf("%d", &ans);

		switch (ans) {
			case 1:
				printf("Enter a word:");
				scanf("%s", &word);
				insert_node(root, word);		//insert �Լ� ȣ��
				break;
			case 2:
				printf("Enter a word to delete:");
				scanf("%s", &word);
				delete_node(root, word);		//delete �Լ� ȣ��
				break;
			case 3:
				printf("Enter a word:");
				scanf("%s", &word);
				if(search(root, word) != NULL)			//ã�Ҵٸ�
					printf("%s is found\n", word);
				else
					printf("%s is not found\n", word);		//ã�� ���ߴٸ�
				break;
			case 4:
				print_inorder(root);
				break;
			case 5:
				printf("Program finished\n");
				exit(1);			//���α׷� ����
				break;
			default:
				printf("Wrong input\n");
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