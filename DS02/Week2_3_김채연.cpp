#include <stdio.h>

void name()
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void iterative(int n) {		//�ݺ��Լ�
	double sum = 0;		//���� �����ϴ� ����
	while (n != 0) {
		sum += (double)1 / n;
		n--;
	}
	printf("%.2f\n", sum);		//�� ���
}

double recursive(int n) {		//����Լ�
	if (n == 1)		//n�� 1�̸� 1 ��ȯ
		return 1;
	else    //1�� �ƴϸ�
		return (double)1 / n + recursive(n - 1);	//���İ� n-1�� ���� ��� ȣ��
}

int main() {
	name();		//�й�, �̸�, ����

	int n;		//�Է¹��� ���� ����
	double sum = 0;		//���� ������ ����

	while (true) {		//�ݺ�
		printf("���� ���� �Է�:");
		scanf("%d", &n);	//���� ���� �Է¹ޱ�
		if (n == 0)		//0�� �Է¹����� ����
			break;
		printf("Result from iterative: ");
		iterative(n);	//�ݺ��Լ� ȣ��
		printf("Result from recursive: %.2f\n", recursive(n));		//����Լ� ȣ�� �� ���
	}

	return 0;
}