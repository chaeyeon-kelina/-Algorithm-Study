#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {		//큐 노드 구조체 선언
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front, * rear;
}LinkedQueue;

void name()	//학번, 이름, 전공 출력
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void init_queue(LinkedQueue* q) {	//큐 초기화
	q->front = NULL;
	q->rear = NULL;
}

bool is_full(LinkedQueue* q) {		//큐가 다 찼을 경우
	return 0;
}

bool is_empty(LinkedQueue* q) {			//큐가 비었을 경우
	return (q->front == NULL);
}

void enqueue(LinkedQueue* q, int item) {	//큐에 원소 추가
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));		//temp 노드 동적할당
	temp->data = item;		//데이터 저장
	temp->link = NULL;		//링크는 null
	if (is_empty(q)) {		//큐가 비어 있으면 새로 추가된 노드가 front이자 rear
		q->front = temp;
		q->rear = temp;
	}
	else {		//큐가 비어 있지 않으면
		q->rear->link = temp;	//기존의 rear가 새로 추가된 노드를 가리키게 하고
		q->rear = temp;		//새로 추가된 노드가 rear이 된다
	}
}

int dequeue(LinkedQueue* q) {		//큐에서 원소 빼내기
	if (is_empty(q)) {		//큐가 비었을 경우 에러메세지 출력 후 종료
		printf("queue is empty\n");
		exit(1);
	}
	int data;
	QueueNode* temp = q->front;		//기존의 front가 가리키던 노드 위치를 저장
	data = temp->data;		//기존의 front가 가리키던 값을 반환을 위해 저장
	q->front = q->front->link;		//기존의 front가 가리키던 노드가 새로운 front
	if (q->front == NULL)		//만약 노드가 한개라면 큐를 공백으로 만든다
		q->rear = NULL;
	free(temp);		//메모리 반환
	return data;		//디큐된 값을 반환
}

int peek(LinkedQueue* q) {		//큐에 있는 원소 보기
	return q->front->data;
}


void fibo(int l, LinkedQueue* q) {		//피보나치 수열 계산하는 함수
	int a, b, n;
	for (int i = 0; i <= l; i++) {		//사용자가 입력한 값만큼 반복
		a = dequeue(q);		//F(n-2)
		b = peek(q);		//F(n-1)
		n = a + b;		//F(n)
		enqueue(q, n);		//F(n)값을 큐에 추가
		printf("    %d", a);
	}
	printf("\n");
}

int main() {
	name();	//학번, 이름, 전공 출력

	int location;
	LinkedQueue q;		//구조체 변수
	init_queue(&q);		//큐 초기화
	enqueue(&q, 0);		//피보나치 수열 첫번째 값인 0 추가
	enqueue(&q, 1);		//피보나치 수열 두번째 값인 1 추가
	printf("Input a fibonicci loacation: ");
	scanf("%d", &location);		//사용자로부터 피보나치 수열 위치를 받아 location변수에 저장
	fibo(location, &q);		//피보나치 계산

	return 0;
}