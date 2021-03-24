#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* link;
}ListNode;

typedef struct
{
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	if (L->head == NULL) {
		L->head = node;
		node->link = L->head;
	}
	else {
		node->link = L->head->link;
		L->head->link = node;
	}
}

void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] -> ", p->data);
	printf("NULL\n");
}

void buildList(LinkedListType* L, int n) {
	for (int i = n; i > 0; i--)
		addFirst(L, i);
}

void Remove(LinkedListType* L, int r) {
	int removedata;
	ListNode* before = L->head;
	for (int i = 0; i < r - 2; i++)
		before = before->link;
	removedata = before->link->data;
	before->link = before->link->link;
}

int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}

int runSimulation(LinkedListType* L, int n, int k) {
	int r = 0;	//strat candle
	int N = n;
	while (n > 1) {
		r = (r + k) % N;
		Remove(L, r);
		n--;
	}

	return get(L, r);
}

void candle(LinkedListType* L, int n, int k) {
	buildList(L, n);
	printf("마지막으로 남은 촛불은 몇 번째 촛불인가? : %d번째\n", runSimulation(L, n, k));
}

int main() {
	LinkedListType list;
	init(&list);
	int n = 7;
	int k = 3;
	printf("주어진 촛불의 개수 : %d개\n", n);
	printf("건너 뛰는 촛불의 개수 : %d개\n", k);
	candle(&list, n, k);

	return 0;
}

