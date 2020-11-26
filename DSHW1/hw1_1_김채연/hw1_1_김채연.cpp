#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode {		//���׽��� �׸��� �����Ǵ� ���
	int coef;		//���
	int exponent;		//����
	struct ListNode *link;
}ListNode;

typedef struct ListType {		//���׽��� ������ �����ϴ� ���
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void name();		//�̸�, �й�, ���� ���
void error(const char* message);		//���� �޼����� ����ϴ� �Լ�

ListType* create() {		//���׽��� ������ �����ϴ� ��� �����ϴ� �Լ�
	ListType*pinfo = (ListType*)malloc(sizeof(ListType));
	pinfo->head = NULL;
	pinfo->tail = NULL;
	pinfo->size = 0;
	return pinfo;
}

void insert_poly(ListType* pinfo, int coef, int exponent) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//���� ������ ��� ����
	if (p == NULL)		//�޸� �Ҵ� ����
		error("memory allocation error\n");
	p->coef = coef;				//���ο� ��� ����
	p->exponent = exponent;
	p->link = NULL;
	if (pinfo->tail == NULL)		//ù��° ��� ������ ��
		pinfo->head = pinfo->tail = p;
	else {		//������ ��尡 �ִٸ�
		pinfo->tail->link = p;		//���׽� ����Ʈ�� ��� �߰�
		pinfo->tail = p;		//���׽� ������ ���� ������ �� ��� �ּҷ� ����
	}
	pinfo->size++;		//���׽��� ���� ����
}

void poly_print(ListType* pinfo) {		//���׽��� ����ϴ� �Լ�
	ListNode *node = pinfo->head;
	for (int i = 0; i < pinfo->size - 1; i++) {
		printf("%dx^%d + ", node->coef, node->exponent);
		node = node->link;
	}
	printf("%dx^%d \n\n", node->coef, node->exponent);
}

int calculate(ListType *pinfo, int x) {		//���׽��� ����ϴ� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p = pinfo->head;

	int result = 0;
	for (int i = 0; i < pinfo->size; i++) {
		result += (p->coef) * (int)(pow(x, p->exponent));		//��� * x^����
		p = p->link;	//���� ���� �̵�
	}
	return result;		//����� ��ȯ
}

void Clear(ListType* d) //�� ��� free
{
	ListNode* temp = d->head;
	ListNode* p = NULL;
	while (temp->link != NULL) {		//��� ������ �ݺ�
		p = temp;
		temp = p->link;
		free(p);		//�޸� ��ȯ
	}
	free(temp);
}


int main() {
	name();

	int coef, exponent, x;
	ListType* polyinfo = create();		//���׽��� ������ ������ ��� ����
//	ListNode* p = NULL;

	printf("Input coef and exponent of polynomial(��������: exponent�� 0���� �Է�)\n");
	while (true) {
		scanf("%d %d", &coef, &exponent);
		insert_poly(polyinfo, coef, exponent);		//���׽� ����
		if (exponent == 0)		//������ 0�� �Է��ϸ� �ݺ��� ����
			break;
	}
	printf("<Polynominal>\n");
	poly_print(polyinfo);		//���׽� ���

	printf("Input the value x: ");
	scanf("%d", &x);
	printf("Result of polynomal with x: %d", calculate(polyinfo, x));		//���׽� ����� ���� ���

	
	Clear(polyinfo);		//���׽� �� ��� �޸� ��ȯ
	free(polyinfo);		//�޸� ��ȯ

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

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
