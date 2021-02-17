#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}dListNode;

void name();		//�̸�, �й�, ���� ���

ListNode* insert(ListNode* phead, ListNode* pos, int n) {		//���ϴ� ��ġ�� ��� �����ִ� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));		//���ο� ��� ����
	p->data = n;
	p->link = pos->link;		//���ο� ��尡 ������ pos�� ����Ű�� ��带 ����Ŵ
	pos->link = p;		//������ ���� ���ο� ��带 ����Ŵ

	return phead;
}

ListNode* insert_first(ListNode* phead, int n) {		//�� �տ� ���ο� ��� �����ִ� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));		//���ο� ��� ����
	p->data = n;
	p->link = phead;		//���ο� ��带 ��尡 ����Ű�� ��忡 ����
	phead = p;		//����� �ּҸ� ���ο� ��� ������ �ٲٱ�

	return phead;
}

ListNode* insert_sort(ListNode* phead, int n) {		//����Ʈ�� ���������� ������ �� �ֵ��� ���� �Լ�
	if (phead == NULL)
		phead = insert_first(phead, n);		//ù��° ��� ����
	else {
		ListNode* p = NULL;

		for (p = phead; p != NULL; p = p->link) {		//����Ʈ�� ���� ������ �ݺ�
			if (p->link == NULL && n <= p->data) {		//n <=  ������ �� �϶�
				phead = insert_first(phead, n);		//������ ���� �տ� �����ֱ�
				break;
			}
			else if (p->link == NULL && n >= p->data) {		//n >=  ������ �� �϶�
				phead = insert(phead, p, n);
				break;
			}
			else if (p->data <= n && n <= p->link->data) {		//n�� ���� �߰��� ��������
				phead = insert(phead, p, n);
				break;
			}
		}
	}
	return phead;
}

void print_list(ListNode* phead) {		//����Ʈ�� ����ϴ� �Լ�
	ListNode* p = NULL;
	for (p = phead; p != NULL; p = p->link)		//����Ʈ�� ���� ������ �ݺ�
			printf("%3d ->", p->data);
	printf("  NULL\n");
}



int main() {
	name();

	int n;
	ListNode* head = NULL;		//��� ������ ����

	printf("Input data to insert to linkedlist(0 to quit)\n");
	while (true) {
		scanf("%d", &n);
		if (n == 0)			//0�� �Է¹����� ����
			break;
		head = insert_sort(head, n);		//���� ������ �������� ����Ʈ ����
		print_list(head);		//����Ʈ ���
	}
	print_list(head);
	printf("Program finished.\n");


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

