#include <stdio.h>
#include <string.h>

void name()
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void func_recursive(char *X) {		//���ڿ��� �Ųٷ� ����ϴ� �Լ�
	if (*X == 0)	//null���ڸ� ������
		return;
	else {	
		func_recursive(X + 1);		//���� ���ڸ� ��� ����Լ� ȣ��
		printf("%c", *X);		//�ش� ���� ���
	}
}

int main(void) {
	name();		//�й�, �̸�, ���� ���

	char X[100];
	printf("Input string\n");
	gets_s(X);
	puts("������:");
	puts(X);
	puts("������:");
	func_recursive(X);		//����Լ�ȣ��
	return 0;
}