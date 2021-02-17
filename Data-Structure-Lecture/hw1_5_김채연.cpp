#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct QueueType {
	QueueNode* front;		//front 노드 저장
	QueueNode* rear;		//rear 노드 저장
}QueueType;

void name();		//이름, 학번, 전공 출력
void error(const char* message);		//에러 메세지를 출력하는 함수

void init_queue(QueueType* q) {		//큐 초기화
	q->front = NULL;
	q->rear = NULL;
}

bool is_empty(QueueType* q) {		//큐가 비었는지 검사
	return (q->front == NULL);
}

void enqueue(QueueType* q, int item) {		//큐에 data를 집어넣는 함수
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));		//노드 생성

	temp->data = item;		//노드의 data에 값 집어넣기
	temp->link = NULL;
	if (is_empty(q)) {		//큐가 비었을 경우 새로 추가된 노드가 front이자 rear
		q->front = temp;		
		q->rear = temp;
	}
	else {		//기존 노드가 존재했다면
		q->rear->link = temp;		//이전 노드와 새로운 노드 연결
		q->rear = temp;		//rear 위치 조정
	}
}

int dequeue(QueueType* q) {		//큐에서 data를 빼내는 함수
	if (is_empty(q))		//큐기 비었다면 오류 메세지 출력
		error("queue empty");

	QueueNode* temp = q->front;		//기존 front가 가리키던 노드 위치를 저장
	int data;
	
	data = temp->data;
	q->front = q->front->link;		//front 위치 조정

	if (q->front == NULL)		//노드가 한개인 경우라면 큐를 공백으로 만듦
		q->rear = NULL;

	free(temp);		//기존 front 노드 메모리 반환
	
	return data;		//디큐한 data 반환
}

void print_queue(QueueType* q) {		//리스트를 출력하는 함수
	if(is_empty(q))
		error("queue empty");
	for (QueueNode* temp = q->front; temp != NULL; temp = temp->link) {		//큐의 시작부터 끝까지 반복
		printf("%3d |", temp->data);
	}
	printf("\n");
}

void set_card(QueueType* q, int n) {		//맨 처음 카드를 세팅하는 함수
	if (n == 0)
		return;
	for (int i = 1; i <= n; i++)		//1부터 사용자가 입력한 값까지 큐에 추가
		enqueue(q, i);
	print_queue(q);		//추가를 마친 큐 출력
}

int count_node(QueueType* q) {		//노드의 개수를 반환하는 함수
	int count = 0;

	for (QueueNode* temp = q->front; temp != NULL; temp = temp->link) {	//큐의 시작부터 끝까지 반복
		count++;		//노드의 개수 세기
	}
	return count;		//노드의 개수 반환
}

int main() {
	name();

	int n, data;
	int count = 0;
	QueueType q;		//구조체 변수

	init_queue(&q);		//큐 초기화
	printf("Input numbers of cards: ");
	scanf("%d", &n);
	set_card(&q, n);		//카드 세팅
	while (true) {
		dequeue(&q);		//제일 위에 있는 값 빼내기
		print_queue(&q);		//빼내고 남은 큐 출력
		count = count_node(&q);		//노드의 개수를 세서 1개만 남았으면 탈출
		if (count == 1)
			break;
		data = dequeue(&q);		//그 다음으로 제일 위에 있는 값 빼내기
		enqueue(&q, data);		//위에서 빼낸 값을 다시 큐에 추가
		print_queue(&q);		//추가한 큐의 모습 출력
	}
	printf("Final elemnet is %d", dequeue(&q));		//마지막으로 남은 data를 디큐하여 출력

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

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}