#include <stdio.h>
#include <string.h>

void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void func_recursive(char *X) {		//문자열을 거꾸로 출력하는 함수
	if (*X == 0)	//null문자를 만나면
		return;
	else {	
		func_recursive(X + 1);		//다음 문자를 담아 재귀함수 호출
		printf("%c", *X);		//해당 문자 출력
	}
}

int main(void) {
	name();		//학번, 이름, 전공 출력

	char X[100];
	printf("Input string\n");
	gets_s(X);
	puts("변경전:");
	puts(X);
	puts("변경후:");
	func_recursive(X);		//재귀함수호출
	return 0;
}