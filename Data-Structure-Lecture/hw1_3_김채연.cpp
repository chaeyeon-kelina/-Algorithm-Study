#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}dListNode;

void name();		//이름, 학번, 전공 출력

ListNode* insert(ListNode* phead, ListNode* pos, int n) {		//원하는 위치에 노드 끼워넣는 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));		//새로운 노드 생성
	p->data = n;
	p->link = pos->link;		//새로운 노드가 기존의 pos가 가리키던 노드를 가리킴
	pos->link = p;		//기존의 노드는 새로운 노드를 가리킴

	return phead;
}

ListNode* insert_first(ListNode* phead, int n) {		//맨 앞에 새로운 노드 끼워넣는 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));		//새로운 노드 생성
	p->data = n;
	p->link = phead;		//새로운 노드를 헤드가 가리키던 노드에 연결
	phead = p;		//헤드의 주소를 새로운 노드 것으로 바꾸기

	return phead;
}

ListNode* insert_sort(ListNode* phead, int n) {		//리스트가 오름차순을 유지할 수 있도록 돕는 함수
	if (phead == NULL)
		phead = insert_first(phead, n);		//첫번째 노드 생성
	else {
		ListNode* p = NULL;

		for (p = phead; p != NULL; p = p->link) {		//리스트가 끝날 때까지 반복
			if (p->link == NULL && n <= p->data) {		//n <=  마지막 값 일때
				phead = insert_first(phead, n);		//마지막 값의 앞에 끼워넣기
				break;
			}
			else if (p->link == NULL && n >= p->data) {		//n >=  마지막 값 일때
				phead = insert(phead, p, n);
				break;
			}
			else if (p->data <= n && n <= p->link->data) {		//n의 값이 중간에 끼워질때
				phead = insert(phead, p, n);
				break;
			}
		}
	}
	return phead;
}

void print_list(ListNode* phead) {		//리스트를 출력하는 함수
	ListNode* p = NULL;
	for (p = phead; p != NULL; p = p->link)		//리스트가 끝날 때까지 반복
			printf("%3d ->", p->data);
	printf("  NULL\n");
}



int main() {
	name();

	int n;
	ListNode* head = NULL;		//헤드 포인터 선언

	printf("Input data to insert to linkedlist(0 to quit)\n");
	while (true) {
		scanf("%d", &n);
		if (n == 0)			//0을 입력받으면 종료
			break;
		head = insert_sort(head, n);		//받은 값으로 오름차순 리스트 생성
		print_list(head);		//리스트 출력
	}
	print_list(head);
	printf("Program finished.\n");


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

