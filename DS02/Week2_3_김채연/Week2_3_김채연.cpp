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
	double sum = 0;		//합을 저장하는 변수
	while (n != 0) {
		sum += (double)1 / n;
		n--;
	}
	printf("%.2f\n", sum);		//합 출력
}

double recursive(int n) {		//재귀함수
	if (n == 1)		//n이 1이면 1 반환
		return 1;
	else    //1이 아니면
		return (double)1 / n + recursive(n - 1);	//계산식과 n-1을 넣은 재귀 호출
}

int main() {
	name();		//학번, 이름, 전공

	int n;		//입력받을 양의 정수
	double sum = 0;		//합을 저장할 변수

	while (true) {		//반복
		printf("양의 정수 입력:");
		scanf("%d", &n);	//양의 정수 입력받기
		if (n == 0)		//0을 입력받으면 종료
			break;
		printf("Result from iterative: ");
		iterative(n);	//반복함수 호출
		printf("Result from recursive: %.2f\n", recursive(n));		//재귀함수 호출 및 출력
	}

	return 0;
}