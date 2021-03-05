//정렬
//2750. 수 정렬하기

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int num[10001];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (num[i] > num[j]) {
				int t = num[i];
				num[i] = num[j];
				num[j] = t;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", num[i]);

	return 0;
}