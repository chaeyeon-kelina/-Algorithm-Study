#include <stdio.h>

void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void bin(int n) {
	int i = 0;
	int result[100];	//2진수로 변환한 수를 저장할 변수

	while (n != 0) {		//2진수로 변환하는 반복문
		result[i] = n % 2;
		n /= 2;
		i++;
	}
	while (i != 0) {	//저장한 변수를 거꾸로 출력
		i--;
		printf("%d", result[i]);	//2진수 출력
	}
}

int main() {
	name();		//학과, 학번, 성명 출력

	int n;		//받아올 양의 정수

	printf("양의정수 입력:");
	scanf("%d", &n);	//양의 정수 입력받기
	printf("십진수 %d의 이진표현: ", n);
	bin(n);		//2진수로 변환하는 함수

	return 0;
}