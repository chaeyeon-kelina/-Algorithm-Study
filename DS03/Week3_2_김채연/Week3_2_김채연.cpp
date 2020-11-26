#include <stdio.h>
#define ROWS 4
#define COLS 3

void name()
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void matrixInput(int array[][COLS]) {		//�迭�� ���� �޴� �Լ�
	for (int i = 0; i < ROWS; i++) {
		for(int j=0; j<COLS; j++)
			scanf("%d", &array[i][j]);
	}
}

void matrixPrint(int array[][COLS]) {		//�迭�� ���� ����ϴ� �Լ�
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			printf("%3d", array[i][j]);
		printf("\n");
	}
	printf("\n");
}

void matrixAdd(int A[][COLS], int B[][COLS], int C[][COLS]) {	//�迭�� ���� ���ϴ� �Լ�
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			C[i][j] = A[i][j] + B[i][j];		//A�迭�� B�迭�� ���ҵ��� ���� ���ؼ� �ش��ϴ� C�迭 ���Ұ��� ����
		}
	}
}

int main(void) {
	name();		//�й�, �̸�, ���� ���

	int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];	//2���� �迭 ����
	printf("Input values for %dX%d matrix A\n", ROWS, COLS);
	matrixInput(A);		//A�迭 ���� �޴� �Լ� ȣ��
	printf("Input values for %dX%d matrix B\n", ROWS, COLS);
	matrixInput(B);		//B�迭 ���� �޴� �Լ� ȣ��
	puts("<A>");
	matrixPrint(A);		//A�迭 ���� ����ϴ� �Լ� ȣ��
	puts("<B>");
	matrixPrint(B);		//B�迭 ���� ����ϴ� �Լ� ȣ��
	puts("<A+B>");
	matrixAdd(A, B, C);		//�迭�� ���� ���ϴ� �Լ� ȣ��
	matrixPrint(C);		//C�迭 ���� ����ϴ� �Լ� ȣ��
	return 0;
}
