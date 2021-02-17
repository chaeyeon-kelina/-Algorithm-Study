#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct QueueType {
	QueueNode* front;		//front ��� ����
	QueueNode* rear;		//rear ��� ����
}QueueType;

void name();		//�̸�, �й�, ���� ���
void error(const char* message);		//���� �޼����� ����ϴ� �Լ�

void init_queue(QueueType* q) {		//ť �ʱ�ȭ
	q->front = NULL;
	q->rear = NULL;
}

bool is_empty(QueueType* q) {		//ť�� ������� �˻�
	return (q->front == NULL);
}

void enqueue(QueueType* q, int item) {		//ť�� data�� ����ִ� �Լ�
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));		//��� ����

	temp->data = item;		//����� data�� �� ����ֱ�
	temp->link = NULL;
	if (is_empty(q)) {		//ť�� ����� ��� ���� �߰��� ��尡 front���� rear
		q->front = temp;		
		q->rear = temp;
	}
	else {		//���� ��尡 �����ߴٸ�
		q->rear->link = temp;		//���� ���� ���ο� ��� ����
		q->rear = temp;		//rear ��ġ ����
	}
}

int dequeue(QueueType* q) {		//ť���� data�� ������ �Լ�
	if (is_empty(q))		//ť�� ����ٸ� ���� �޼��� ���
		error("queue empty");

	QueueNode* temp = q->front;		//���� front�� ����Ű�� ��� ��ġ�� ����
	int data;
	
	data = temp->data;
	q->front = q->front->link;		//front ��ġ ����

	if (q->front == NULL)		//��尡 �Ѱ��� ����� ť�� �������� ����
		q->rear = NULL;

	free(temp);		//���� front ��� �޸� ��ȯ
	
	return data;		//��ť�� data ��ȯ
}

void print_queue(QueueType* q) {		//����Ʈ�� ����ϴ� �Լ�
	if(is_empty(q))
		error("queue empty");
	for (QueueNode* temp = q->front; temp != NULL; temp = temp->link) {		//ť�� ���ۺ��� ������ �ݺ�
		printf("%3d |", temp->data);
	}
	printf("\n");
}

void set_card(QueueType* q, int n) {		//�� ó�� ī�带 �����ϴ� �Լ�
	if (n == 0)
		return;
	for (int i = 1; i <= n; i++)		//1���� ����ڰ� �Է��� ������ ť�� �߰�
		enqueue(q, i);
	print_queue(q);		//�߰��� ��ģ ť ���
}

int count_node(QueueType* q) {		//����� ������ ��ȯ�ϴ� �Լ�
	int count = 0;

	for (QueueNode* temp = q->front; temp != NULL; temp = temp->link) {	//ť�� ���ۺ��� ������ �ݺ�
		count++;		//����� ���� ����
	}
	return count;		//����� ���� ��ȯ
}

int main() {
	name();

	int n, data;
	int count = 0;
	QueueType q;		//����ü ����

	init_queue(&q);		//ť �ʱ�ȭ
	printf("Input numbers of cards: ");
	scanf("%d", &n);
	set_card(&q, n);		//ī�� ����
	while (true) {
		dequeue(&q);		//���� ���� �ִ� �� ������
		print_queue(&q);		//������ ���� ť ���
		count = count_node(&q);		//����� ������ ���� 1���� �������� Ż��
		if (count == 1)
			break;
		data = dequeue(&q);		//�� �������� ���� ���� �ִ� �� ������
		enqueue(&q, data);		//������ ���� ���� �ٽ� ť�� �߰�
		print_queue(&q);		//�߰��� ť�� ��� ���
	}
	printf("Final elemnet is %d", dequeue(&q));		//���������� ���� data�� ��ť�Ͽ� ���

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