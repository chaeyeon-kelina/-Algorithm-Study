//브루트 포스
//1018. 체스판 다시 칠하기
#include <stdio.h>
#include <stdlib.h>

int MIN(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main() {
	char board[51][51];

	int n, m;
	int min = 100;
	int b = 0, w = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &board[i]);
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			b = 0;
			w = 0;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if ((k + l) % 2 == 0) {
						if (board[k][l] == 'B')
							w++;
						else
							b++;
					}
					else {
						if (board[k][l] == 'B')
							b++;
						else
							w++;
					}
				}
			}
			min = MIN(min, b);
			min = MIN(min, w);
		}
	}
	printf("%d\n", min);

	return 0;
}