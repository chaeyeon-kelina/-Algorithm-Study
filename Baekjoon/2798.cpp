#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, sum;
	int card[101] = { 0, };

	scanf("%d %d", &n, &m);

	int answer = m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum <= m) {
					if (sum > answer)
						answer = sum;
				}
			}
		}
	}

	printf("%d", answer);
}
