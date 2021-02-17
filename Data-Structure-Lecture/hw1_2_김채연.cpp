#include <stdio.h>
#include <stdlib.h>

typedef struct dListNode {
	int data;
	struct dListNode* llink;
	struct dListNode* rlink;
}dListNode;


void name();		//�̸�, �й�, ���� ���

void init(dListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(dListNode* dhead) {		//����Ʈ�� ����ϴ� �Լ�
	dListNode* node = NULL;
	for (node = dhead->rlink; node != dhead->llink; node = node->rlink) {		//���������� �ѹ��� �� ������
		printf("  %d  <->", node->data);
	}
	printf("  %d\n", dhead->llink->data);
}

void reverse_dlist(dListNode* dhead) {		//�������� ����ϴ� �Լ�
	dListNode* node = NULL;
	for (node = dhead->llink; node != dhead->rlink; node = node->llink) {		//�������� �ѹ��� ��������
		printf("  %d  <->", node->data);
	}
	printf("  %d\n", dhead->rlink->data);
}

void dinsert(dListNode* dhead, int n) {		//����ڰ� �Է��� ���� ����Ʈ�� ���� �߰��ϴ� �Լ�
	dListNode* newnode = (dListNode*)malloc(sizeof(dListNode*));	//���ο� ��� ����
	newnode->data = n;		//����� data�� �� ����ֱ�
	newnode->rlink = dhead;		//���ο� ��带 ���� ���� ����
	newnode->llink = dhead->llink;
	dhead->llink->rlink = newnode;
	dhead->llink = newnode;
}


void Clear(dListNode* d) //�� ��� free
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
	dListNode* head = (dListNode*)malloc(sizeof(dListNode));		//��� ��� ����
	init(head);		//��� ��� �ʱ�ȭ

	printf("Input data in dual linkedlist(0 to quit)\n");
	while (true) {
		scanf("%d", &n);
		if (n == 0)		//0�� �Է��ϸ� �ݺ��� ����
			break;
		dinsert(head, n);		//����ڰ� �Է��� ���� ����Ʈ�� ���� �߰�
	}
	print_dlist(head);		//����Ʈ�� ����ϴ� �Լ�
	printf("Print the list in reverse order\n");
	reverse_dlist(head);		//����Ʈ�� �������� ����ϴ� �Լ�

//	Clear(head);
	free(head);		//�޸� ��ȯ

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
