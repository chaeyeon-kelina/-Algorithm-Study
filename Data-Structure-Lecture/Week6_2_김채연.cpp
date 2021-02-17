#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100	//스택의 최대 크기 지정

typedef struct StackType {	//구조체 선언
	int data[MAX_STACK_SIZE];	//element 타입의 요소를 담을 배열
	int top;	//top의 값을 member로 포함
}stack;


void name(){
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void init_stack(stack *s) {		//스택 초기화
	s->top = -1;
}

int peek(stack *s) {			//스택의 맨 위 원소를 제거하지 않고 반환
	return s->data[s->top];
}

void push(stack *s, int x) {	//스택에 push하는 함수
	s->data[++(s->top)] = x;	//top 위치 조정 후 data배열에 전달받은 나머지값 push
}

int pop(stack* s) {		//스택에서 pop하는 함수
	return s->data[(s->top)--];		//data 배열에서 top이 가리키는 값 반환후 top 위치 조정
}

void count_alp(char *str) {		//이어진 원소의 개수를 세는 함수
	stack s;		//구조체 변수
	int x, count;	
	init_stack(&s);		//스택 초기화
	push(&s, str[0]);		//문자열의 첫 원소를 push
	for (int i = 1; i <= strlen(str); i++) {		//null이 나올 때까지 반복문
		x = str[i];
		if (peek(&s) == x)		//만약 이전 문자와 현재 문자가 같을 경우
			push(&s, x);		//현재 문자를 스택에 넣는다
		else {
			count = s.top + 1;		//현재 스택에 들어있는 문자 개수
			printf("%d%c", count, pop(&s));		//이어진 문자+개수 출력
			init_stack(&s);		//스택 초기화
			push(&s, x);	//다음 비교를 위한 첫글자 스택에 push
		}
	}

}

int main() {
	name();		//이름, 학번, 전공 출력
	char str[100];
	while (true) {
		printf("반복되는 알파벳으로 구성된 문자열 입력(종료시 '0' 입력)\n");
		scanf("%s", str);
		if (strcmp(str,"0") != 0)		//입력된 문자가 0이 아니면
			count_alp(str);
		else        //입력된 문자가 0이면 종료
			break;
		printf("\n\n");
	}

	return 0;

}