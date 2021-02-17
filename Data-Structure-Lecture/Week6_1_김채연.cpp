#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100	//������ �ִ� ũ�� ����

typedef int element;
typedef struct StackType {	//����ü ����
	element data[MAX_STACK_SIZE];	//element Ÿ���� ��Ҹ� ���� �迭
	int top;	//top�� ���� member�� ����
}StackType;

void name() {
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void init_stack(StackType* s) {		//���� �ʱ�ȭ
	s->top = -1;
}

void push(StackType* s, int num_10) {	//���ÿ� push�ϴ� �Լ�
	s->data[++(s->top)] = num_10;	//top ��ġ ���� �� data�迭�� ���޹��� �������� push
}

int pop(StackType* s) {		//���ÿ��� pop�ϴ� �Լ�
	return s->data[s->top--];	//data �迭���� top�� ����Ű�� �� ��ȯ�� top ��ġ ����
}

void calculate(StackType* s, int num_10) {		//10�������� 2������ ��� �� ����ϴ� �Լ�
	while (num_10 != 0) {		//10������ 2�� ���� ���� 0�� �ɶ����� �ݺ�
		int r = num_10 % 2;
		push(s, r);		//2�� ���� ������ ���� push
		num_10 /= 2;
	}
	printf("������ ǥ��:");		//2���� ��� ���
	while (s->top != -1) {
		printf("%d", pop(s));	//2�� ���� ������ ���� ���߿� �� ������ pop
	}
}


int main() {
	name();		//�̸�, �й�, ���� ���

	StackType s;		//����ü ���� s
	int num = 1;		//�Է¹��� 10����
	while (true) {
		init_stack(&s);		//���� �ʱ�ȭ
		printf("������ �Է�(����: 0 ���� �Է�)\n");
		scanf("%d", &num);
		if (num > 0)
			calculate(&s, num);		//�Է¹��� 10������ calculate�Լ��� ����
		else
			break;		//0���ϸ� �Է¹����� ����
		printf("\n\n");
	}

	return 0;

}