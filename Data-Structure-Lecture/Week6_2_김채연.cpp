#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100	//������ �ִ� ũ�� ����

typedef struct StackType {	//����ü ����
	int data[MAX_STACK_SIZE];	//element Ÿ���� ��Ҹ� ���� �迭
	int top;	//top�� ���� member�� ����
}stack;


void name(){
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void init_stack(stack *s) {		//���� �ʱ�ȭ
	s->top = -1;
}

int peek(stack *s) {			//������ �� �� ���Ҹ� �������� �ʰ� ��ȯ
	return s->data[s->top];
}

void push(stack *s, int x) {	//���ÿ� push�ϴ� �Լ�
	s->data[++(s->top)] = x;	//top ��ġ ���� �� data�迭�� ���޹��� �������� push
}

int pop(stack* s) {		//���ÿ��� pop�ϴ� �Լ�
	return s->data[(s->top)--];		//data �迭���� top�� ����Ű�� �� ��ȯ�� top ��ġ ����
}

void count_alp(char *str) {		//�̾��� ������ ������ ���� �Լ�
	stack s;		//����ü ����
	int x, count;	
	init_stack(&s);		//���� �ʱ�ȭ
	push(&s, str[0]);		//���ڿ��� ù ���Ҹ� push
	for (int i = 1; i <= strlen(str); i++) {		//null�� ���� ������ �ݺ���
		x = str[i];
		if (peek(&s) == x)		//���� ���� ���ڿ� ���� ���ڰ� ���� ���
			push(&s, x);		//���� ���ڸ� ���ÿ� �ִ´�
		else {
			count = s.top + 1;		//���� ���ÿ� ����ִ� ���� ����
			printf("%d%c", count, pop(&s));		//�̾��� ����+���� ���
			init_stack(&s);		//���� �ʱ�ȭ
			push(&s, x);	//���� �񱳸� ���� ù���� ���ÿ� push
		}
	}

}

int main() {
	name();		//�̸�, �й�, ���� ���
	char str[100];
	while (true) {
		printf("�ݺ��Ǵ� ���ĺ����� ������ ���ڿ� �Է�(����� '0' �Է�)\n");
		scanf("%s", str);
		if (strcmp(str,"0") != 0)		//�Էµ� ���ڰ� 0�� �ƴϸ�
			count_alp(str);
		else        //�Էµ� ���ڰ� 0�̸� ����
			break;
		printf("\n\n");
	}

	return 0;

}