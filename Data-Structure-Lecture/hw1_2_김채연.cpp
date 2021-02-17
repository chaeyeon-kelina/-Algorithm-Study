#include <stdio.h>
#include <stdlib.h>

typedef struct dListNode {
	int data;
	struct dListNode* llink;
	struct dListNode* rlink;
}dListNode;


void name();		//이름, 학번, 전공 출력

void init(dListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(dListNode* dhead) {		//리스트를 출력하는 함수
	dListNode* node = NULL;
	for (node = dhead->rlink; node != dhead->llink; node = node->rlink) {		//오른쪽으로 한바퀴 돌 때까지
		printf("  %d  <->", node->data);
	}
	printf("  %d\n", dhead->llink->data);
}

void reverse_dlist(dListNode* dhead) {		//역순으로 출력하는 함수
	dListNode* node = NULL;
	for (node = dhead->llink; node != dhead->rlink; node = node->llink) {		//왼쪽으로 한바퀴 돌때까지
		printf("  %d  <->", node->data);
	}
	printf("  %d\n", dhead->rlink->data);
}

void dinsert(dListNode* dhead, int n) {		//사용자가 입력한 값을 리스트의 끝에 추가하는 함수
	dListNode* newnode = (dListNode*)malloc(sizeof(dListNode*));	//새로운 노드 생성
	newnode->data = n;		//노드의 data에 값 집어넣기
	newnode->rlink = dhead;		//새로운 노드를 양측 노드와 연결
	newnode->llink = dhead->llink;
	dhead->llink->rlink = newnode;
	dhead->llink = newnode;
}


void Clear(dListNode* d) //각 노드 free
{
	dListNode* temp = d->rlink;
	dListNode* p = NULL;
	while (temp->rlink != d) {
		p = temp;
		temp = p->rlink;
		free(p);
	}
	free(temp);
}



int main() {
	name();

	int n;
	dListNode* head = (dListNode*)malloc(sizeof(dListNode));		//헤드 노드 생성
	init(head);		//헤드 노드 초기화

	printf("Input data in dual linkedlist(0 to quit)\n");
	while (true) {
		scanf("%d", &n);
		if (n == 0)		//0을 입력하면 반복문 종료
			break;
		dinsert(head, n);		//사용자가 입력한 값을 리스트의 끝에 추가
	}
	print_dlist(head);		//리스트를 출력하는 함수
	printf("Print the list in reverse order\n");
	reverse_dlist(head);		//리스트를 역순으로 출력하는 함수

//	Clear(head);
	free(head);		//메모리 반환

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
