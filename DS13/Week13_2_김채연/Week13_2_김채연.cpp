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

void name();		//학번, 이름, 전공 출력

void init_queue(QueueType* q) {	//큐 초기화
	q->front = -1;
	q->rear = -1;
}

bool is_full(QueueType* q) {		//큐가 다 찼을 경우
	return (q->rear == MAX_SIZE -1);
}

bool is_empty(QueueType* q) {			//큐가 비었을 경우
	return (q->front == q->rear);
}

void enqueue(QueueType* q, int item) {	//큐에 원소 추가
	if (is_full(q)) {
		fprintf(stderr, "queue is full");
		return;
	}
	else q->data[++q->rear] = item;
}

int dequeue(QueueType* q) {		//큐에서 원소 빼내기
	if (is_empty(q)) {		//큐가 비었을 경우 에러메세지 출력 후 종료
		printf("queue is empty\n");
		exit(1);
	}
	else return q->data[++(q->front)];
}

void print_bucket(QueueType *q, int b, int n) {		//큐 상태 출력
	printf("\n[%d] ", b);
	for (int i = 0; i < n; i++) {			
		if (i <= q->front || i > q->rear)		//큐가 비었을 때
			printf("");
		else	
			printf("%3d |", q->data[i]);
	}
}

void radix_sort(int list[], int n, int a) {
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];			//bucket 수 만큼의 queue가 추가로 필요
	for (b = 0; b < BUCKETS; b++)			//큐들의 초기화
		init_queue(&queues[b]);
	for (d = 0; d < a; d++) {		//자리수가 낮은것부터 높은 순으로
		for (i = 0; i < n; i++) {		//데이터들을 자리수에 따라 큐에 입력
			enqueue(&queues[(list[i] / factor) % 10], list[i]);	//모든 리스트요소를 해당 큐에 넣기
		}
		for (b = 0; b < BUCKETS; b++)			//큐 상태 출력
			print_bucket(&queues[b], b, n);
		printf("\n");

		for (b = i = 0; b < BUCKETS; b++)		//bucket에서 꺼내어 리스트에 순서대로 insert
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;		//그 다음 높은 자리수로 이동
	}

}


int main() {
	name();

	int n = MAX_SIZE;
	int i, d;
	printf("자리수 입력(1~4) : ");
	scanf("%d", &d);		//자리수 입력받아서 변수 d에 저장

	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % (int)pow(10,d);		//0~해당 자리수까지 난수 생성해서 리스트에 저장

	printf("\n<Before sorting>\n");		//정렬 전 배열 출력
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	radix_sort(list, n, d);		//정렬

	printf("\n<After Quick Sorting>\n");		//정렬 후 배열 출력
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

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