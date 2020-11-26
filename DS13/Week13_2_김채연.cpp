#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_SIZE 10
#define BUCKETS 10
#define DIGITS 4

typedef struct {
	int front;
	int rear;
	int data[MAX_SIZE];
}QueueType;

void name();		//�й�, �̸�, ���� ���

void init_queue(QueueType* q) {	//ť �ʱ�ȭ
	q->front = -1;
	q->rear = -1;
}

bool is_full(QueueType* q) {		//ť�� �� á�� ���
	return (q->rear == MAX_SIZE -1);
}

bool is_empty(QueueType* q) {			//ť�� ����� ���
	return (q->front == q->rear);
}

void enqueue(QueueType* q, int item) {	//ť�� ���� �߰�
	if (is_full(q)) {
		fprintf(stderr, "queue is full");
		return;
	}
	else q->data[++q->rear] = item;
}

int dequeue(QueueType* q) {		//ť���� ���� ������
	if (is_empty(q)) {		//ť�� ����� ��� �����޼��� ��� �� ����
		printf("queue is empty\n");
		exit(1);
	}
	else return q->data[++(q->front)];
}

void print_bucket(QueueType *q, int b, int n) {		//ť ���� ���
	printf("\n[%d] ", b);
	for (int i = 0; i < n; i++) {			
		if (i <= q->front || i > q->rear)		//ť�� ����� ��
			printf("");
		else	
			printf("%3d |", q->data[i]);
	}
}

void radix_sort(int list[], int n, int a) {
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];			//bucket �� ��ŭ�� queue�� �߰��� �ʿ�
	for (b = 0; b < BUCKETS; b++)			//ť���� �ʱ�ȭ
		init_queue(&queues[b]);
	for (d = 0; d < a; d++) {		//�ڸ����� �����ͺ��� ���� ������
		for (i = 0; i < n; i++) {		//�����͵��� �ڸ����� ���� ť�� �Է�
			enqueue(&queues[(list[i] / factor) % 10], list[i]);	//��� ����Ʈ��Ҹ� �ش� ť�� �ֱ�
		}
		for (b = 0; b < BUCKETS; b++)			//ť ���� ���
			print_bucket(&queues[b], b, n);
		printf("\n");

		for (b = i = 0; b < BUCKETS; b++)		//bucket���� ������ ����Ʈ�� ������� insert
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;		//�� ���� ���� �ڸ����� �̵�
	}

}


int main() {
	name();

	int n = MAX_SIZE;
	int i, d;
	printf("�ڸ��� �Է�(1~4) : ");
	scanf("%d", &d);		//�ڸ��� �Է¹޾Ƽ� ���� d�� ����

	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % (int)pow(10,d);		//0~�ش� �ڸ������� ���� �����ؼ� ����Ʈ�� ����

	printf("\n<Before sorting>\n");		//���� �� �迭 ���
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	radix_sort(list, n, d);		//����

	printf("\n<After Quick Sorting>\n");		//���� �� �迭 ���
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

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