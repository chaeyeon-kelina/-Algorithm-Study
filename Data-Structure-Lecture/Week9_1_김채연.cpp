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

TreeNode n1 = { 1, NULL, NULL };			//test2 트리 상태값
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { 15, &n1, &n2 };
TreeNode n7 = { 30, &n3, NULL };
TreeNode* exp = &n7;

void name();		//내 정보 출력하는 함수

void inorder(TreeNode* root) {		//중위 순회
	if (root) {		//빈 트리가 아니라면 밑의 코드 진행
		inorder(root->left);		//left subtree traverse
		printf(" [%d] ", root->data);
		inorder(root->right);		//left subtree traverse
	}
}

int get_node_count(TreeNode* exp) {		//노드 숫자 세는 함수
	if (exp == NULL)
		return 0;
	else
		return get_node_count(exp->left) + get_node_count(exp->right) + 1;		//왼쪽 자손노드 개수 + 오른쪽 자손노드 개수 + 루트 노드
}

int get_height(TreeNode* exp) {		//트리 높이 세는 함수
	if (exp == NULL)
		return 0;
	else {
		int l_height = get_height(exp->left);		//왼쪽 자손 노드의 높이
		int r_height = get_height(exp->right);		//오른쪽 자손 노드의 높이
		if (l_height >= r_height)		//더 높은 자손 노드의 높이 + 1(루트) 반환
			return l_height + 1;		
		else
			return r_height + 1;
	}
}

int get_leaf_count(TreeNode* exp) {		//단말 노드 개수 세는 함수
	if (exp == NULL)
		return 0;
	else {
		if (exp->left == NULL && exp->right == NULL)		//왼쪽과 오른쪽 모두 자손 노드가 없으면
			return 1;
		else
			return get_leaf_count(exp->left) + get_leaf_count(exp->right);
	}
}

int balanced_tree(TreeNode* exp) {		//트리의 밸런스 검사
	TreeNode* node = exp->left;		
	int l_height = get_height(node);		//왼쪽 노드의 높이 검사
	node = exp->right;
	int r_height = get_height(node);		//오른쪽 노드의 높이 검사

	if (abs(l_height - r_height) > 1)		//왼쪽과 오른쪽의 차이가 1 초과라면
		return 0;		
	else				//왼쪽과 오른쪽의 차이가 1 이하라면
		return 1;
}

void get_greater_number(TreeNode* exp, int num) {		//사용자가 입력한 값보다 더 큰 값 출력하는 함수
	if (exp) {
		get_greater_number(exp->left, num);
		if (exp->data > num)		//중위순회를 따라 검사하다가 노드의 값이 주어진 값보다 크면 출력
			printf(" %d", exp->data);
		get_greater_number(exp->right, num);
	}
}

int main() {
	name();

	int num;

	inorder(exp);		//트리 상태 출력
	
	printf("\nNumber of nodes in tree: %d\n", get_node_count(exp));		//노드 개수
	printf("Height of the tree: %d\n", get_height(exp));		//트리의 높이
	printf("Number of leafs in tree: %d\n", get_leaf_count(exp));		//단말 노드 개수
	printf("Balanced tree? ");		//트리 밸런스 검사
	if (balanced_tree(exp) == 1)			//왼쪽과 오른쪽의 차이가 1 이하라면
		printf("Yes\n");		//"Yes" 출력
	else
		printf("No\n");
	
	printf("Input a number to check: ");
	scanf("%d", &num);
	printf("numbers greater than %d:", num);
	get_greater_number(exp, num);		//주어진 값보다 더 큰 노드의 값 출력

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