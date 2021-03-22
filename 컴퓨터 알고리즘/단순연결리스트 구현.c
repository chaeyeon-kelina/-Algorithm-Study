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
	node->link = L->head;
	L->head = node;
}

void addLast(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p = L->head;
	while (p->link != NULL)
		p = p->link;
	node->data = item;
	p->link = node;
	node->link = NULL;
}

void add(LinkedListType* L, int pos, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link = node;
}


int RemoveFirst(LinkedListType* L) {
	if (L->head == NULL) {
		printf("삭제할 노드가 없습니다.");
	}
	else {
		int removedata = L->head->data;
		L->head = L->head->link;
		return removedata;
	}
}

int RemoveLast(LinkedListType* L) {
	ListNode* p = L->head;
	while (p->link->link != NULL)
		p = p->link;
	int removedata = p->link->data;
	p->link = NULL;
	return removedata;
}

int Remove(LinkedListType* L, int pos) {
	int removedata;
	if (pos == 1) {
		removedata = RemoveFirst(L);
		return removedata;
	}
	else {
		ListNode* before = L->head;
		for (int i = 0; i < pos - 2; i++)
			before = before->link;
		removedata = before->link->data;
		before->link = before->link->link;
		return removedata;
	}
}

int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}

void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}

void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] -> ", p->data);
	printf("NULL\n");
}

void main() {
	LinkedListType list;
	init(&list);

	addFirst(&list, 10);	printList(&list);
	addFirst(&list, 20);	printList(&list);
	addFirst(&list, 30);	printList(&list);
	printf("삭제 된 맨 앞 노드의 값 : %d\n", RemoveFirst(&list));	printList(&list);
	printf("삭제 된 맨 뒤 노드의 값 : %d\n", RemoveLast(&list));		printList(&list);
	printf("\n");
	printf("Add Last 구현\n");
	addLast(&list, 50);		printList(&list);
	addLast(&list, 60);		printList(&list);
	getchar();
	add(&list, 1, 40);	printList(&list);
	add(&list, 1, 50);	printList(&list);
	add(&list, 3, 60);	printList(&list);
	int pos;
	printf("\n몇 번 노드의 값을 반환할까요? ");
	scanf("%d", &pos);
	printf("%d번 노드의 값은 %d\n", pos, get(&list, pos));
	printf("\n몇 번 노드의 값을 삭제할까요? ");
	scanf("%d", &pos);
	printf("삭제된 %d번 노드의 값은 %d\n", pos, Remove(&list, pos));
	printList(&list);

}
