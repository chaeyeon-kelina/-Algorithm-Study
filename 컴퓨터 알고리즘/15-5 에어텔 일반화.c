//분할통치법
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(x,y) ((x)>(y) ? (x):(y))
#define min(x,y) ((x)<(y) ? (x):(y))

int n = 20;
int A[20];
int H[20];
int s;

int rAirtelForward(int d) {
	if (d == 0)
		return 0;

	int minCost = 100000;
	int cost;

	for (int k = 0; k < d; k++) {
		cost = rAirtelForward(k) + H[k] + A[d - k];
		minCost = min(minCost, cost);
	}

	return minCost;
}

int main() {
	int d;
	for (int i = 0; i < 20; i++)
		A[i] = ++i;
	srand((int)time(NULL));
	for (int i = 0; i < 20; i++)
		H[i] = rand() % 99 + 1;
	scanf("%d %d", &s, &d);
	printf("%d\n", rAirtelForward(d));

	return 0;
}


//동적프로그래밍
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(x,y) ((x)>(y) ? (x):(y))
#define min(x,y) ((x)<(y) ? (x):(y))

int n = 20;
int A[20];
int H[20];
int s;
int m[20];

int airtel(int n) {
	m[0] = 0;
	int cost;
	for (int d = 1; d < n; d++) {
		m[d] = 100000;
		for (int k = 0; k < d; k++) {
			cost = m[k] + H[k] + A[d - k];
			m[d] = min(m[d], cost);
		}

	}

	return m[n - 1];
}

int main() {
	int d;
	for (int i = 0; i < 20; i++)
		A[i] = ++i;
	srand((int)time(NULL));
	for (int i = 0; i < 20; i++)
		H[i] = rand() % 99 + 1;
	scanf("%d %d", &s, &d);
	printf("%d\n", airtel(d));

	return 0;
}

