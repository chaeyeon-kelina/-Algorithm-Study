#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

void name();

TreeNode* new_node(int item) {		//새로운 노드 생성
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));		//메모리 할당
	node->key = item;		//키 값 집어넣기
	node->left = node->right = NULL;		//자손 노드를 NULL로 초기화
	return node;
}

void inorder(TreeNode* root) {		//중위 순회
	if (root) {		//빈 트리가 아니라면 밑의 코드 진행
		inorder(root->left);		//left subtree traverse
		printf(" [%d] ", root->key);
		inorder(root->right);		//left subtree traverse
	}
}

TreeNode* insert_node(TreeNode* node, int key) {		//노드 삽입하는 함수
	if (node == NULL)		//트리가 공백이면 insert된 새로운 노드 반환
		return new_node(key);
	if (key < node->key)		//삽입할 값이 루트의 키값보다 작으면 left subtree를 root로 insert 재귀호출
		node->left = insert_node(node->left, key);
	else if (key > node->key)		//삽입할 값이 루트의 키값보다 크면 right subtree를 root로 insert 재귀호출
		node->right = insert_node(node->right, key);
	return node;		//바뀐 root 포인터 반환
}

TreeNode* min_value_node(TreeNode* node) {		//가장 왼쪽의 단말노드(최솟값) 찾기
	TreeNode* current = node;
	while (current->left != NULL)		//null이 될때까지 계속 왼쪽 자손으로 내려감
		current = current->left;
	return current;
}

TreeNode* max_value_node(TreeNode* node) {		//가장 오른쪽의 단말노드(최댓값) 찾기
	TreeNode* current = node;
	while (current->right != NULL)		//null이 될때까지 계속 오른쪽 자손으로 내려감
		current = current->right;
	return current;
}

int compare(int num, int min, int max) {		//해당 노드의 값과 최솟값, 최대값의 각각 차이 정도 비교 
	if (abs(num - min) > abs(num - max))		//해당 노드값과의 차의 절댓값이 더 작은 노드값 반환
		return max;
	else
		return min;
}

TreeNode* delete_node(TreeNode* root, int key) {		//key가 저장된 노드를 찾아 삭제하고 새로운 root 반환
	if (root == NULL)
		return root;
	else if (root->key > key)		//왼쪽 subtree에서 key값을 찾아 삭제하도록 재귀 호출
		root->left = delete_node(root->left, key);
	else if (root->key < key)		//오른쪽 subtree에서 key값을 찾아 삭제하도록 재귀 호출
		root->right = delete_node(root->right, key);
	else {				//삭제할 key를 찾았다면
		if (root->left == NULL) {		//left노드거나 자손을 하나 갖는 노드일 경우
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//자손 노드가 둘 다 있는 경우
		TreeNode* min_temp = min_value_node(root->right);	//오른쪽 노드에서 최솟값을 갖는 노드 찾기
		TreeNode* max_temp = max_value_node(root->left);	//왼쪽 노드에서 최대값을 갖는 노드 찾기

		printf("left subtree의 max: %d\n", max_temp->key);
		printf("right subtree의 min: %d\n", min_temp->key);

		int choose = compare(key, min_temp->key, max_temp->key);	//최솟값과 최댓값 중 key값과 가장 가까운 값 반환
		root->key = choose;		//찾은 값을 삭제할 위치에 복사

		printf("original value:%d  new value: %d\n", key, root->key);

		//복사된 값을 갖고 있던 노드 삭제
		if (choose == min_temp->key)
			root->right = delete_node(root->right, min_temp->key);
		else if (choose == max_temp->key)
			root->left = delete_node(root->left, max_temp->key);
	}
	return root;		//새로운 root 반환
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

	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);		//트리 상태 출력

	while (true) {
		printf("\n\n* operation 선택: Insert(I) / Delete(D) / Exit(X) : ");
		scanf(" %c", &ans);
		switch (ans) {
			case 'I':		//사용자가 I를 선택하면
				printf("Insert할 값은? ");
				scanf("%d", &num);
				insert_node(root, num);		//Insert 할 값 받아서 함수 호출
				inorder(root);		//트리 출력
				break;
			case 'D':		//사용자가 D를 선택하면
				printf("Delete할 값은? ");
				scanf("%d", &num);
				delete_node(root, num);		//삭제할 값 받아서 함수 호출
				inorder(root);		//트리 출력
				break;
			case 'X':		//사용자가 X를 선택하면
				printf("프로그램 종료\n");
				exit(1);		//프로그램 종료
			default:
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