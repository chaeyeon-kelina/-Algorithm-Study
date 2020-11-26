#include <stdio.h>
#define MAX_TERMS 100

void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

void elementPrint(int array[], int* n) {		//배열 출력 함수
	printf("Array:	");
	for (int i = 0; i < *n; i++)
		printf("%d ", array[i]);		//배열의 원소 출력
	printf("\n");
}

void elementGeneration(int array[], int *n) {	//배열의 원소 입력 함수
	printf("Input %d numbers\n", *n);
	for (int i = 0; i < *n; i++)
		scanf("%d", &array[i]);		//입력받은 원소를 배열에 저장
}

void elementInsertion(int array[], int* n) {		//새로운 element 추가 함수
	int l, v;
	printf("Input location and value to insert\n");
	scanf("%d %d", &l, &v);		//위치는 l, 값은 v에 저장
	if (!(l > 0 && l <= *n + 1)) {		//위치가 1 ~ n 사이가 아니라면
		printf("Choose between 1 and %d\n", *n + 1);
		return;
	}
	for (int i = *n-1; i >= l-1; i--)		//
		array[i + 1] = array[i];		//해당 위치부터 배열의 원소 하나씩 뒤로 미루기	
	array[l - 1] = v;		//해당 위치 l에 v 값 추가
	*n += 1;		//배열의 길이 +1
	elementPrint(array, n);		//배열 출력 함수 호출
}

void elementDeletion(int array[], int* n) {			//element 삭제 함수
	int l;
	printf("Input location to delete\n");
	scanf("%d", &l);		//받은 위치를 l에 저장
	if (!(l >= 1 && l <= *n)) {		//위치가 1 ~ n 사이가 아니라면
		printf("No element in location %d\n", l);
		return;
	}
	for (int i = l; i < *n; i++)
		array[i - 1] = array[i];		//해당 위치부터 배열의 원소 하나씩 앞으로 당기기	
	*n -= 1;		//배열의 길이 -1
	elementPrint(array, n);		//배열 출력 함수 호출
}



int main(void) {
	name();		//이름, 학번, 전공 출력

	int array[MAX_TERMS], n;
	int answer = 1;		//operation 값을 저장할 변수
	printf("How many numbers? ");
	scanf("%d", &n);	//원소의 개수 받기
	elementGeneration(array, &n);	//배열의 원소 입력 함수 호출
	elementPrint(array, &n);		//배열 출력 함수 호출
	while (answer != 0) {		//반복문(answer이 0이 아닐경우 반복)
		printf("\nChoose operation:\n");
		printf("1.insertion  2.deletion  3.output  0:program end\n");
		scanf("%d", &answer);
		switch (answer) {
			case 1:		//사용자가 1을 고르면
				elementInsertion(array, &n);		//새로운 element 추가 함수 호출
				break;
			case 2:		//사용자가 2를 고르면
				elementDeletion(array, &n);			//element 삭제 함수 호출
				break;
			case 3:		//사용자가 3을 고르면
				elementPrint(array, &n);		//배열 출력 함수 호출
				break;
			default:
				break;
		}
	}
	return 0;
}
