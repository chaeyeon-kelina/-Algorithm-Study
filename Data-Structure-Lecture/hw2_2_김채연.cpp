#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct TreeNode {
	char key[SIZE];
	struct TreeNode* left, * right;
};

void name();

void print_inorder(TreeNode* root) {			//inorder로 정렬된 트리 출력
	if (root) {	//빈 트리가 아니라면 밑의 코드 진행
		print_inorder(root->left);		//left subtree traverse
		printf("%s\n", root->key);
		print_inorder(root->right);	   //right subtree traverse
	}
}

TreeNode* insert_node(TreeNode* node, const char* item) {
	int i = 1;
	if (node == NULL){ 	//트리가 공백이면 insert된 새로운 노드 반환
		TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));		//메모리 할당
		strcpy(p->key, item);
		p->left = p->right = NULL;
		return p;
	}
	if (strncmp(node->key, item, strlen(item)) > 0)		//(아스키코드 비교) 노드의 값 > item 이면 left subtree를 root로 insert 재귀호출
		node->left = insert_node(node->left, item);
	else if (strncmp(node->key, item, strlen(item)) < 0)			//(아스키코드 비교) 노드의 값 < item 이면 right subtree를 root로 insert 재귀호출
		node->right = insert_node(node->right, item);
	return node;
}

TreeNode* min_value_node(TreeNode* node) {		//가장 왼쪽의 단말노드(최솟값) 찾기
	TreeNode* current = node;
	while (current->left != NULL)		//null이 될때까지 계속 왼쪽 자손으로 내려감
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* node, char *item) {
	if (node == NULL)
		return node;
	else if (strncmp(node->key, item, strlen(item)) > 0)		//(아스키코드 비교) 노드의 값 > item 이면 left subtree를 root로 delete 재귀호출
		node->left = delete_node(node->left, item);
	else if (strncmp(node->key, item, strlen(item)) < 0)			//(아스키코드 비교) 노드의 값 < item 이면 right subtree를 root로 delete 재귀호출
		node->right = delete_node(node->right, item);
	else {			//찾았을 경우
		if (node->left == NULL) {		//left노드거나 자손을 하나 갖는 노드일 경우
			TreeNode* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			TreeNode* temp = node->left;
			free(node);
			return temp;
		}
		//자손 노드가 둘 다 있는 경우
		TreeNode* temp = min_value_node(node->right);	//오른쪽 노드에서 최솟값을 갖는 노드 찾기
		strcpy(node->key, temp->key);	//찾은 값을 삭제할 위치에 복사
		node->right = delete_node(node->right, temp->key);
	}
	return node;		//새로운 root 반환
}

TreeNode* search(TreeNode* node, char* item) {
	if (node == NULL)
		return NULL;
	if (strcmp(node->key, item))		//찾고자 하는 노드면 반환
		return node;
	else if (strncmp(node->key, item, strlen(item)) > 0)		
		return search(node->left, item);		//left subtree 다시 search
	else
		return search(node->right, item);		//right subtree 다시 search
}

int main() {
	name();			//전공, 이름, 학번 출력
	
	int ans;
	char word[SIZE];
	TreeNode* root = NULL;
	//초기 값 집어 넣기
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
				insert_node(root, word);		//insert 함수 호출
				break;
			case 2:
				printf("Enter a word to delete:");
				scanf("%s", &word);
				delete_node(root, word);		//delete 함수 호출
				break;
			case 3:
				printf("Enter a word:");
				scanf("%s", &word);
				if(search(root, word) != NULL)			//찾았다면
					printf("%s is found\n", word);
				else
					printf("%s is not found\n", word);		//찾지 못했다면
				break;
			case 4:
				print_inorder(root);
				break;
			case 5:
				printf("Program finished\n");
				exit(1);			//프로그램 종료
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
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}