#include <stdio.h>
#include <stdlib.h>


void buildList(int *S, int n) {
	for (int i = 0; i < n; i++)
		S[i] = i+1;
}

int runSimulation(int* S, int n, int k) {
	int r = 0;	//strat candle
	int N = n;
	while (n > 1) {
		int i = 0;
		while (i < k) {
			r = (r + 1) % N;
			if (S[r] != 0)
				i++;
		}
		S[r] = 0;
		n--;
		while(S[r] == 0)
			r = (r + 1) % N;
	}
	return S[r];
}

void candle(int n, int k) {
	int* S = (int*)malloc(sizeof(int) * n);
	buildList(S, n);
	printf("���������� ���� �к��� �� ��° �к��ΰ�? : %d��°\n", runSimulation(S, n, k));
}

int main() {
	int n = 7;
	int k = 3;
	printf("�־��� �к��� ���� : %d��\n", n);
	printf("�ǳ� �ٴ� �к��� ���� : %d��\n", k);
	candle(n, k);

	return 0;
}