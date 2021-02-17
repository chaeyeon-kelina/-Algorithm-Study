#include <stdio.h>
#define MAX_TERMS 100

void name()
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}

void elementPrint(int array[], int* n) {		//�迭 ��� �Լ�
	printf("Array:	");
	for (int i = 0; i < *n; i++)
		printf("%d ", array[i]);		//�迭�� ���� ���
	printf("\n");
}

void elementGeneration(int array[], int *n) {	//�迭�� ���� �Է� �Լ�
	printf("Input %d numbers\n", *n);
	for (int i = 0; i < *n; i++)
		scanf("%d", &array[i]);		//�Է¹��� ���Ҹ� �迭�� ����
}

void elementInsertion(int array[], int* n) {		//���ο� element �߰� �Լ�
	int l, v;
	printf("Input location and value to insert\n");
	scanf("%d %d", &l, &v);		//��ġ�� l, ���� v�� ����
	if (!(l > 0 && l <= *n + 1)) {		//��ġ�� 1 ~ n ���̰� �ƴ϶��
		printf("Choose between 1 and %d\n", *n + 1);
		return;
	}
	for (int i = *n-1; i >= l-1; i--)		//
		array[i + 1] = array[i];		//�ش� ��ġ���� �迭�� ���� �ϳ��� �ڷ� �̷��	
	array[l - 1] = v;		//�ش� ��ġ l�� v �� �߰�
	*n += 1;		//�迭�� ���� +1
	elementPrint(array, n);		//�迭 ��� �Լ� ȣ��
}

void elementDeletion(int array[], int* n) {			//element ���� �Լ�
	int l;
	printf("Input location to delete\n");
	scanf("%d", &l);		//���� ��ġ�� l�� ����
	if (!(l >= 1 && l <= *n)) {		//��ġ�� 1 ~ n ���̰� �ƴ϶��
		printf("No element in location %d\n", l);
		return;
	}
	for (int i = l; i < *n; i++)
		array[i - 1] = array[i];		//�ش� ��ġ���� �迭�� ���� �ϳ��� ������ ����	
	*n -= 1;		//�迭�� ���� -1
	elementPrint(array, n);		//�迭 ��� �Լ� ȣ��
}



int main(void) {
	name();		//�̸�, �й�, ���� ���

	int array[MAX_TERMS], n;
	int answer = 1;		//operation ���� ������ ����
	printf("How many numbers? ");
	scanf("%d", &n);	//������ ���� �ޱ�
	elementGeneration(array, &n);	//�迭�� ���� �Է� �Լ� ȣ��
	elementPrint(array, &n);		//�迭 ��� �Լ� ȣ��
	while (answer != 0) {		//�ݺ���(answer�� 0�� �ƴҰ�� �ݺ�)
		printf("\nChoose operation:\n");
		printf("1.insertion  2.deletion  3.output  0:program end\n");
		scanf("%d", &answer);
		switch (answer) {
			case 1:		//����ڰ� 1�� ����
				elementInsertion(array, &n);		//���ο� element �߰� �Լ� ȣ��
				break;
			case 2:		//����ڰ� 2�� ����
				elementDeletion(array, &n);			//element ���� �Լ� ȣ��
				break;
			case 3:		//����ڰ� 3�� ����
				elementPrint(array, &n);		//�迭 ��� �Լ� ȣ��
				break;
			default:
				break;
		}
	}
	return 0;
}
