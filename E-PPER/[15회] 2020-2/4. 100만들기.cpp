#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 정수 배열 numbers 의 길이는 9 입니다.
int* solution(int numbers[]) {
	//할당 길이는 상황에 맞게 변경해주세요.
	int* answer = (int*)malloc(sizeof(int) * 7);
	int sum = 0;
	int t = 0;
	for (int k = 0; k < 9; k++) {
		sum += numbers[k];			//주어진 배열의 합계
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (numbers[i]) - (numbers[j]) == 100) {		//합계 - 선택된 두 수 = 100이면
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)
						continue;
					answer[t++] = numbers[k];		//두 수를 제외한 수를 배열에 추가
				}
				break;
			}
		}
	}
	return answer;
}

int main(void) {
	int numbers[9];
	int i;
	int* r = NULL;

	for (i = 0; i < 9; i++) {
		scanf("%d", &numbers[i]);
	}

	r = solution(numbers);
	for (i = 0; i < 7; i++) {
		printf("%d ", r[i]);
	}
}
