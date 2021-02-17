#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100	//스택의 최대 크기 지정

typedef int element;
typedef struct StackType {	//구조체 선언
	element data[MAX_STACK_SIZE];	//element 타입의 요소를 담을 배열
	int top;	//top의 값을 member로 포함
}StackType;

void name() {
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void init_stack(StackType* s) {		//스택 초기화
	s->top = -1;
}

void push(StackType* s, int num_10) {	//스택에 push하는 함수
	s->data[++(s->top)] = num_10;	//top 위치 조정 후 data배열에 전달받은 나머지값 push
}

int pop(StackType* s) {		//스택에서 pop하는 함수
	return s->data[s->top--];	//data 배열에서 top이 가리키는 값 반환후 top 위치 조정
}

void calculate(StackType* s, int num_10) {		//10진수에서 2진수로 계산 후 출력하는 함수
	while (num_10 != 0) {		//10진수를 2로 나눈 몫이 0이 될때까지 반복
		int r = num_10 % 2;
		push(s, r);		//2로 나눈 나머지 값을 push
		num_10 /= 2;
	}
	printf("이진수 표현:");		//2진수 결과 출력
	while (s->top != -1) {
		printf("%d", pop(s));	//2로 나눈 나머지 값을 나중에 들어간 값부터 pop
	}
}


int main() {
	name();		//이름, 학번, 전공 출력

	StackType s;		//구조체 변수 s
	int num = 1;		//입력받을 10진수
	while (true) {
		init_stack(&s);		//스택 초기화
		printf("십진수 입력(종료: 0 이하 입력)\n");
		scanf("%d", &num);
		if (num > 0)
			calculate(&s, num);		//입력받은 10진수를 calculate함수로 전달
		else
			break;		//0이하를 입력받으면 종료
		printf("\n\n");
	}

	return 0;

}