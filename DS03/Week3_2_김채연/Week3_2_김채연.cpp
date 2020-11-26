#include <stdio.h>
#define ROWS 4
#define COLS 3

void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void matrixInput(int array[][COLS]) {		//배열의 값을 받는 함수
	for (int i = 0; i < ROWS; i++) {
		for(int j=0; j<COLS; j++)
			scanf("%d", &array[i][j]);
	}
}

void matrixPrint(int array[][COLS]) {		//배열의 값을 출력하는 함수
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			printf("%3d", array[i][j]);
		printf("\n");
	}
	printf("\n");
}

void matrixAdd(int A[][COLS], int B[][COLS], int C[][COLS]) {	//배열의 값을 더하는 함수
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			C[i][j] = A[i][j] + B[i][j];		//A배열과 B배열의 원소들을 각각 더해서 해당하는 C배열 원소값에 저장
		}
	}
}

int main(void) {
	name();		//학번, 이름, 전공 출력

	int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];	//2차원 배열 선언
	printf("Input values for %dX%d matrix A\n", ROWS, COLS);
	matrixInput(A);		//A배열 값을 받는 함수 호출
	printf("Input values for %dX%d matrix B\n", ROWS, COLS);
	matrixInput(B);		//B배열 값을 받는 함수 호출
	puts("<A>");
	matrixPrint(A);		//A배열 값을 출력하는 함수 호출
	puts("<B>");
	matrixPrint(B);		//B배열 값을 출력하는 함수 호출
	puts("<A+B>");
	matrixAdd(A, B, C);		//배열의 합을 구하는 함수 호출
	matrixPrint(C);		//C배열 값을 출력하는 함수 호출
	return 0;
}
