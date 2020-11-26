#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5	//����ť ũ��

typedef struct QueueType {		//����ť�� ����� ����ü ����
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}QueueType;

void name()		//�й�, �̸�, ���� ���
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void init_queue(QueueType* q) {		//ť �ʱ�ȭ
	q->front = 0;
	q->rear = 0;
}

bool is_full(QueueType* q) {		//ť�� �� á�� ���
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

bool is_empty(QueueType* q) {		//ť�� ����� ���
	return(q->front == q->rear);
}

void enqueue(QueueType* q, int n) {		//ť�� ���� �߰�
	if (is_full(q))		//ť�� �� á�� ���
		printf("queue is full\n");		//���� �޼��� ���
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;		//rear�� ������Ŵ
		q->data[q->rear] = n;		//������ rear ��ġ�� �� ����
	}
}

int dequeue(QueueType* q) {		//ť���� ���Ҹ� ������
	if (is_empty(q))	//ť�� ����� ���
		printf("queue is empty\n");		//���� �޼��� ���
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;		//front�� ������Ŵ
		return q->data[q->front];		//������ front ��ġ�� �ִ� �� ��ȯ
	}
}

void print_queue(QueueType* q) {		//ť ����ϴ� �Լ�
	printf("Queue(front:%d, rear: %d) = ", q->front, q->rear);	//ť�� front�� rear ���� ��ġ ���
	if (!is_empty(q)) {		//ť�� ���Ұ� ������ ���
		int i = q->front;		//i�� ���� front���� ����
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;		//front+1���� ���
			printf("%3d |", q->data[i]);
			if (i == q->rear)	//������Ų ��ġ�� rear�� �����ϸ�(�� ��µƴٸ�)
				break;
		} while (i != q->front);	//�ִ� �� ���� ���Ƽ� front ��ġ���� ���� ����
	}
	printf("\n");
}

void print_count(QueueType* q) {		//ť�� �����ϴ� ������ ���� ���� �Լ�
	printf("���� ���� ������: %d", (MAX_QUEUE_SIZE - q->front + q->rear) % MAX_QUEUE_SIZE);
	printf("\n");
}

int main() {
	name();		//�̸�, �й�, ���� ���

	char ans;
	int n;
	QueueType q;		//����ü ����

	init_queue(&q);		//ť �ʱ�ȭ
	while (true) {
		printf("���ϴ� �۾�(E/e:enqueue, D/d:dequeue, P/p:output, 0:quit): ");
		scanf("%c", &ans);		//����ڰ� ���ϴ� �۾��� �޾Ƽ� ans������ ����
		switch (ans) {
		case 'E':	//ans�� e, E�̸�
		case 'e':
			printf("�����Է�: ");	
			scanf("%d", &n);	
			enqueue(&q, n);		//�Է¹��� ������ ��ť
			break;
		case 'D':	//ans�� d, D�̸�
		case 'd':
			printf("  %d\n", dequeue(&q));		//��ť�� ���� ���
			break;
		case 'P':	//ans�� p, P�̸�
		case 'p':
			print_queue(&q);		//���� ť�� ����ִ� �� ���
			break;
		case '0':	//ans�� 0�̸�
			print_count(&q);		//���� ť�� ����ִ� ������ ���� ���
			print_queue(&q);
			exit(0);
		default:	//ans�� �������� ���� ���� ���´ٸ�
			printf("Wrong input\n");
			break;
		}
		printf("\n");
		getchar();		//���� ����
	}
	return 0;
}