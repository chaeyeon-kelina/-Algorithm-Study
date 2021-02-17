#include <stdio.h>
#include <time.h>

void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

bool isPrime(int n)
{
	for (int i = 2; i < n; i++) {
		if ( n % i == 0)
			return false;
	}
	return true;
}

int main(void)
{
	name();

	int start, stop;
	int n, cnt = 0;

	printf("Input n:");
	scanf("%d", &n);
	start = clock();
	for (int i = 2; i <= n; i++)
		if (isPrime(i)) {
			cnt++;
			printf("%5d", i);
		}
	putchar('\n');
	stop = clock();
	printf("start: %d\n", start);
	printf("stop: %d\n", stop);
	printf("총 %d개\n", cnt);
	printf("time1: %.2f sec\n\n", (double)(stop - start) / CLOCKS_PER_SEC);

	return 0;
}