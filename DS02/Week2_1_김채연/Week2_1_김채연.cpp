#include <stdio.h>

void name()
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void bin(int n) {
	int i = 0;
	int result[100];	//2������ ��ȯ�� ���� ������ ����

	while (n != 0) {		//2������ ��ȯ�ϴ� �ݺ���
		result[i] = n % 2;
		n /= 2;
		i++;
	}
	while (i != 0) {	//������ ������ �Ųٷ� ���
		i--;
		printf("%d", result[i]);	//2���� ���
	}
}

int main() {
	name();		//�а�, �й�, ���� ���

	int n;		//�޾ƿ� ���� ����

	printf("�������� �Է�:");
	scanf("%d", &n);	//���� ���� �Է¹ޱ�
	printf("������ %d�� ����ǥ��: ", n);
	bin(n);		//2������ ��ȯ�ϴ� �Լ�

	return 0;
}