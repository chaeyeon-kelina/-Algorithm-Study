#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {		//ť ��� ����ü ����
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front, * rear;
}LinkedQueue;

void name()	//�й�, �̸�, ���� ���
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void init_queue(LinkedQueue* q) {	//ť �ʱ�ȭ
	q->front = NULL;
	q->rear = NULL;
}

bool is_full(LinkedQueue* q) {		//ť�� �� á�� ���
	return 0;
}

bool is_empty(LinkedQueue* q) {			//ť�� ����� ���
	return (q->front == NULL);
}

void enqueue(LinkedQueue* q, int item) {	//ť�� ���� �߰�
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));		//temp ��� �����Ҵ�
	temp->data = item;		//������ ����
	temp->link = NULL;		//��ũ�� null
	if (is_empty(q)) {		//ť�� ��� ������ ���� �߰��� ��尡 front���� rear
		q->front = temp;
		q->rear = temp;
	}
	else {		//ť�� ��� ���� ������
		q->rear->link = temp;	//������ rear�� ���� �߰��� ��带 ����Ű�� �ϰ�
		q->rear = temp;		//���� �߰��� ��尡 rear�� �ȴ�
	}
}

int dequeue(LinkedQueue* q) {		//ť���� ���� ������
	if (is_empty(q)) {		//ť�� ����� ��� �����޼��� ��� �� ����
		printf("queue is empty\n");
		exit(1);
	}
	int data;
	QueueNode* temp = q->front;		//������ front�� ����Ű�� ��� ��ġ�� ����
	data = temp->data;		//������ front�� ����Ű�� ���� ��ȯ�� ���� ����
	q->front = q->front->link;		//������ front�� ����Ű�� ��尡 ���ο� front
	if (q->front == NULL)		//���� ��尡 �Ѱ���� ť�� �������� �����
		q->rear = NULL;
	free(temp);		//�޸� ��ȯ
	return data;		//��ť�� ���� ��ȯ
}

int peek(LinkedQueue* q) {		//ť�� �ִ� ���� ����
	return q->front->data;
}


void fibo(int l, LinkedQueue* q) {		//�Ǻ���ġ ���� ����ϴ� �Լ�
	int a, b, n;
	for (int i = 0; i <= l; i++) {		//����ڰ� �Է��� ����ŭ �ݺ�
		a = dequeue(q);		//F(n-2)
		b = peek(q);		//F(n-1)
		n = a + b;		//F(n)
		enqueue(q, n);		//F(n)���� ť�� �߰�
		printf("    %d", a);
	}
	printf("\n");
}

int main() {
	name();	//�й�, �̸�, ���� ���

	int location;
	LinkedQueue q;		//����ü ����
	init_queue(&q);		//ť �ʱ�ȭ
	enqueue(&q, 0);		//�Ǻ���ġ ���� ù��° ���� 0 �߰�
	enqueue(&q, 1);		//�Ǻ���ġ ���� �ι�° ���� 1 �߰�
	printf("Input a fibonicci loacation: ");
	scanf("%d", &location);		//����ڷκ��� �Ǻ���ġ ���� ��ġ�� �޾� location������ ����
	fibo(location, &q);		//�Ǻ���ġ ���

	return 0;
}