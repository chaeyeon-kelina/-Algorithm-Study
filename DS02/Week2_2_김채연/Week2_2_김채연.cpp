#include <stdio.h>

void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void iterative(int n) {		//반복함수
	while (n >= 0) {		
		printf("%d ", n);	//출력
		n--;
	}
}

int recursive(int n) {		//재귀함수
	if (n == -1)
		return 0;		//종료
	else {
		printf("%d ", n);	//출력
		return recursive(n - 1);	//재귀 호출
	}
	
}

int main() {
	name();		//학번, 이름, 전공

	int n;		//입력받을 양의 정수

	printf("양의 정수 입력:");
	scanf("%d", &n);	//양의 정수 입력받기
	printf("반복함수호출:");
	iterative(n);	//반복함수 호출
	printf("\n재귀함수호출:");
	recursive(n);	//재귀함수 호출
}