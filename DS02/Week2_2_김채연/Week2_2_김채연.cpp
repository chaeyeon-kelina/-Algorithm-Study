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
	while (n >= 0) {		
		printf("%d ", n);	//���
		n--;
	}
}

int recursive(int n) {		//����Լ�
	if (n == -1)
		return 0;		//����
	else {
		printf("%d ", n);	//���
		return recursive(n - 1);	//��� ȣ��
	}
	
}

int main() {
	name();		//�й�, �̸�, ����

	int n;		//�Է¹��� ���� ����

	printf("���� ���� �Է�:");
	scanf("%d", &n);	//���� ���� �Է¹ޱ�
	printf("�ݺ��Լ�ȣ��:");
	iterative(n);	//�ݺ��Լ� ȣ��
	printf("\n����Լ�ȣ��:");
	recursive(n);	//����Լ� ȣ��
}