#include<stdio.h>

int Factorial(int a) {
	int result = 1;
	for (int i = 1; i <= a; i++) {
		result *= i;
	}
	return result;
}

int main() {
	int N, K;

	scanf("%d", &N);
	scanf("%d", &K);

	int a = Factorial(N);
	int b = Factorial(K);
	int c = Factorial(N - K);
	int answer = a / (b*c);

	printf("%d", answer);

	return 0;
}

