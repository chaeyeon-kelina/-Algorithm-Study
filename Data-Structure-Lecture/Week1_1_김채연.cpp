#include <stdio.h>

void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}

int main()
{
	name();

	int a, sum = 0;

	while (true) {
		sum = 0;
		printf("Input an integer\n");
		scanf("%d", &a);
		if (a <= 0) {
			printf("Program finished");
			break;
		}
		for (int i = 1; i <= a; i += 2) {
			if (i % 5 != 0)
				sum += i;
		}
		printf("Sum of odd numbers which is not the multiples of 5 between 1 and %d is %d\n", a, sum);
	}

	return 0;
}