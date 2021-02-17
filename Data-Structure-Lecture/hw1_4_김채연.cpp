#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100		//���ڿ��� ����

typedef struct Stack {		//���ÿ� ����� ����ü ����
	char data[MAX_STACK_SIZE];
	int top;
}Stack;

void name()			//�й�, �̸�, ���� ���
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void init_stack(Stack* s) {		//���� �ʱ�ȭ
	s->top = -1;
}

bool is_full(Stack* s) {		//������ ���� á�� ���
	return (s->top == MAX_STACK_SIZE - 1);
}

bool is_empty(Stack* s) {		//������ ����� ���
	return (s->top == -1);
}

void push(Stack* s, char c) {		//���ÿ� ���� �ִ� �Լ�
	if (is_full(s)) {		//������ ���� á���� ���� �޼��� ��� �� ����
		printf("stack is full\n");
		exit(1);
	}
	else
		s->data[++(s->top)] = c;		//���� top���� �� ���� �ֱ� 
}

char pop(Stack* s) {		//���ÿ��� ���� ������ �Լ�
	if (is_empty(s)) {		//������ ����� ��� ���� �޼��� ��� �� ����
		printf("stack is empty\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];		//���ÿ��� ���� �������� ���� ���� ��ȯ�ϰ� top ����
}

void check_array(char *str, int n) {		//�迭�� �̿��� ���ڿ� ��Ī üũ�ϴ� �Լ�
	for (int i = 0; i < n/2; i++) {
		if (str[i] != str[n-1- i]) {		//���ʴ�� �迭�� �� �հ� �� �ڸ� ��
			printf("���Ī(�迭)\n");		//�ϳ��� ��ġ���� ������ ��� �Լ� ����
			return;
		}
	}
	printf("��Ī(�迭)\n");	
}

void check_stack(char *str, int n) {		//������ �̿��� ���ڿ� ��Ī üũ�ϴ� �Լ�
	Stack s;		//����ü ����
	init_stack(&s);		//���� �ʱ�ȭ
	for (int i = 0; i < n; i++) {		//���ڿ��� ���̸�ŭ �ݺ�
		if (i < n / 2)
			push(&s, str[i]);		//���ڿ��� ������ ���ÿ� �ֱ�
		else {
			if (i==n/2 && n % 2 == 1)		//���ڿ��� ���̰� Ȧ���� ��� ���� ����� �ִ� ���ڴ� �ƹ��͵� ���� �ʰ� �н�
				continue;
			if (pop(&s) != str[i]) {		//���ÿ��� ���� ���ڰ� ���� ���ڿ� ��ġ���� ���� ��� ��� �Լ� ����
				printf("���Ī(����)\n");
				return;
			}
		}
	}
	printf("��Ī(����)\n");
}

int main() {
	name();		//����, �̸�, �й� ���

	char str[MAX_STACK_SIZE];		//���ڿ��� ������ �迭

	while (true) {
		printf("���ĺ����� ������ ���ڿ� �Է�\n");
		scanf("%s", &str);		//����ڷκ��� ���ڿ� �Է¹ޱ�
		if (strcmp(str, "0") == 0)		//0�� �Է¹��� ��� �ݺ��� Ż��
			break;
		int n = strlen(str);		//n�� ���ڿ��� ����
		check_array(str, n);		//�迭�� �̿��� ���ڿ� ��Ī üũ
		check_stack(str, n);		//������ �̿��� ���ڿ� ��Ī üũ
		printf("\n");
	}

	return 0;
}