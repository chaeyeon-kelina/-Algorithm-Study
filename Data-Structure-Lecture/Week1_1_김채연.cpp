#include <stdio.h>

void name()
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
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