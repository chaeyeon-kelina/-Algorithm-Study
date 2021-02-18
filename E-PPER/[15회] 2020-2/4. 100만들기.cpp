#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// ���� �迭 numbers �� ���̴� 9 �Դϴ�.
int* solution(int numbers[]) {
	//�Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
	int* answer = (int*)malloc(sizeof(int) * 7);
	int sum = 0;
	int t = 0;
	for (int k = 0; k < 9; k++) {
		sum += numbers[k];			//�־��� �迭�� �հ�
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (numbers[i]) - (numbers[j]) == 100) {		//�հ� - ���õ� �� �� = 100�̸�
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)
						continue;
					answer[t++] = numbers[k];		//�� ���� ������ ���� �迭�� �߰�
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
