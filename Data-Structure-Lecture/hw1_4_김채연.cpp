#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100		//문자열의 길이

typedef struct Stack {		//스택에 사용할 구조체 선언
	char data[MAX_STACK_SIZE];
	int top;
}Stack;

void name()			//학번, 이름, 전공 출력
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void init_stack(Stack* s) {		//스택 초기화
	s->top = -1;
}

bool is_full(Stack* s) {		//스택이 가득 찼을 경우
	return (s->top == MAX_STACK_SIZE - 1);
}

bool is_empty(Stack* s) {		//스택이 비었을 경우
	return (s->top == -1);
}

void push(Stack* s, char c) {		//스택에 값을 넣는 함수
	if (is_full(s)) {		//스택이 가득 찼으면 에러 메세지 출력 후 종료
		printf("stack is full\n");
		exit(1);
	}
	else
		s->data[++(s->top)] = c;		//스택 top증가 후 값을 넣기 
}

char pop(Stack* s) {		//스택에서 값을 빼내는 함수
	if (is_empty(s)) {		//스택이 비었을 경우 에러 메세지 출력 후 종료
		printf("stack is empty\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];		//스택에서 가장 마지막에 넣은 값을 반환하고 top 감소
}

void check_array(char *str, int n) {		//배열을 이용해 문자열 대칭 체크하는 함수
	for (int i = 0; i < n/2; i++) {
		if (str[i] != str[n-1- i]) {		//차례대로 배열의 맨 앞과 맨 뒤를 비교
			printf("비대칭(배열)\n");		//하나라도 일치하지 않으면 즉시 함수 종료
			return;
		}
	}
	printf("대칭(배열)\n");	
}

void check_stack(char *str, int n) {		//스택을 이용해 문자열 대칭 체크하는 함수
	Stack s;		//구조체 변수
	init_stack(&s);		//스택 초기화
	for (int i = 0; i < n; i++) {		//문자열의 길이만큼 반복
		if (i < n / 2)
			push(&s, str[i]);		//문자열의 절반은 스택에 넣기
		else {
			if (i==n/2 && n % 2 == 1)		//문자열의 길이가 홀수일 경우 가장 가운데에 있는 문자는 아무것도 하지 않고 패스
				continue;
			if (pop(&s) != str[i]) {		//스택에서 빼낸 문자가 다음 문자와 일치하지 않을 경우 즉시 함수 종료
				printf("비대칭(스택)\n");
				return;
			}
		}
	}
	printf("대칭(스택)\n");
}

int main() {
	name();		//전공, 이름, 학번 출력

	char str[MAX_STACK_SIZE];		//문자열을 저장할 배열

	while (true) {
		printf("알파벳으로 구성된 문자열 입력\n");
		scanf("%s", &str);		//사용자로부터 문자열 입력받기
		if (strcmp(str, "0") == 0)		//0을 입력받을 경우 반복문 탈출
			break;
		int n = strlen(str);		//n은 문자열의 길이
		check_array(str, n);		//배열을 이용해 문자열 대칭 체크
		check_stack(str, n);		//스택을 이용해 문자열 대칭 체크
		printf("\n");
	}

	return 0;
}