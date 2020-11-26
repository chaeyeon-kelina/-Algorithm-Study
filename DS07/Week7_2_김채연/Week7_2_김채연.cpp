#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5	//원형큐 크기

typedef struct QueueType {		//원형큐에 사용할 구조체 선언
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}QueueType;

void name()		//학번, 이름, 전공 출력
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void init_queue(QueueType* q) {		//큐 초기화
	q->front = 0;
	q->rear = 0;
}

bool is_full(QueueType* q) {		//큐가 다 찼을 경우
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

bool is_empty(QueueType* q) {		//큐가 비었을 경우
	return(q->front == q->rear);
}

void enqueue(QueueType* q, int n) {		//큐에 원소 추가
	if (is_full(q))		//큐가 다 찼을 경우
		printf("queue is full\n");		//에러 메세지 출력
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;		//rear을 증가시킴
		q->data[q->rear] = n;		//증가된 rear 위치에 값 대입
	}
}

int dequeue(QueueType* q) {		//큐에서 원소를 빼내기
	if (is_empty(q))	//큐가 비었을 경우
		printf("queue is empty\n");		//에러 메세지 출력
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;		//front를 증가시킴
		return q->data[q->front];		//증가된 front 위치에 있는 값 반환
	}
}

void print_queue(QueueType* q) {		//큐 출력하는 함수
	printf("Queue(front:%d, rear: %d) = ", q->front, q->rear);	//큐의 front와 rear 현재 위치 출력
	if (!is_empty(q)) {		//큐에 원소가 존재할 경우
		int i = q->front;		//i는 현재 front부터 시작
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;		//front+1부터 출력
			printf("%3d |", q->data[i]);
			if (i == q->rear)	//증가시킨 위치가 rear과 동일하면(다 출력됐다면)
				break;
		} while (i != q->front);	//최대 한 바퀴 돌아서 front 위치까지 오면 종료
	}
	printf("\n");
}

void print_count(QueueType* q) {		//큐에 존재하는 원소의 개수 세는 함수
	printf("현재 원소 갯수는: %d", (MAX_QUEUE_SIZE - q->front + q->rear) % MAX_QUEUE_SIZE);
	printf("\n");
}

int main() {
	name();		//이름, 학번, 전공 출력

	char ans;
	int n;
	QueueType q;		//구조체 변수

	init_queue(&q);		//큐 초기화
	while (true) {
		printf("원하는 작업(E/e:enqueue, D/d:dequeue, P/p:output, 0:quit): ");
		scanf("%c", &ans);		//사용자가 원하는 작업을 받아서 ans변수에 저장
		switch (ans) {
		case 'E':	//ans가 e, E이면
		case 'e':
			printf("정수입력: ");	
			scanf("%d", &n);	
			enqueue(&q, n);		//입력받은 정수를 인큐
			break;
		case 'D':	//ans가 d, D이면
		case 'd':
			printf("  %d\n", dequeue(&q));		//디큐한 값을 출력
			break;
		case 'P':	//ans가 p, P이면
		case 'p':
			print_queue(&q);		//현재 큐에 들어있는 값 출력
			break;
		case '0':	//ans가 0이면
			print_count(&q);		//현재 큐에 들어있는 원소의 개수 출력
			print_queue(&q);
			exit(0);
		default:	//ans에 선택지에 없는 값이 들어온다면
			printf("Wrong input\n");
			break;
		}
		printf("\n");
		getchar();		//버퍼 비우기
	}
	return 0;
}