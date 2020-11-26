#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t)	((t)=(x), (x)=(y), (y)=(t))	//switch ���� ��ũ��

void name();		//�й�, �̸�, ���� ���

int partition(int list[], int left, int right)
{
	int pivot = list[left];
	int temp, low, high;
	int l_count, r_count;
	low = left;
	high = right + 1;
	do
	{
		do {
			low++;
		}
		while (list[low] < pivot);		//left ���� ��Һ��� �����ϸ鼭 pivot �� �̻��� ��� ã��
		do {
			high--;
		}
		while (list[high] > pivot);		//right ���� ��Һ��� �����ϸ鼭 pivot �� ������ ��� ã��
		if (low < high) {
			SWAP(list[low], list[high], temp);		//�� ��� �ڸ� �ٲٱ�
		}
	} while (low < high);	//low, high�� �����Ҷ����� �ݺ�

	SWAP(list[left], list[high], temp);		//pivot�� �߾ӿ� ��ġ��Ų��
	return high;	//pivot ��ġ ��ȯ
}

void quick_sort(int list[], int left, int right, int n)
{
	if (left < right) {
		int p = partition(list, left, right);		//partition ȣ���ؼ� pivot ã��
		printf("* pivot: %d\n", list[p]);		//pivot ���
		for (int i = 0; i < n; i++)			//list ���
			printf("%d ", list[i]);
		printf("\nleft size: %d	right size: %d\n", p-left, right-p);		//��,���� ���һ��� ���
		quick_sort(list, left, p - 1, n);		//pivot �߽����� pivot �ٷ� �ձ��� ���ȣ��
		quick_sort(list, p + 1, right, n);		//pivot �߽����� pivot �������� ������ ���ȣ��
		
	}
}

int main() {
	name();
	
	int i, n;
	printf("Input size of list(1~10):");		//����Ʈ ������ �Է¹ޱ�
	scanf("%d", &n);
	int *list = (int*)malloc(sizeof(int)*n);		//�迭 �����Ҵ�
	printf("Input %d numbers in the list\n", n);
	for(i=0; i<n; i++)
		scanf("%d", &list[i]);		//�迭 ��� �Է¹ޱ�

	printf("\n<Before sorting>\n");		//���� �� �迭 ���
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	quick_sort(list, 0, n-1, n);		//����

	printf("\n<After Quick Sorting>\n");		//���� �� �迭 ���
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

	free(list);		//�����Ҵ� �޸� ����
	return 0;
}


void name()
{
	printf("===================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971066\n");
	printf("����: ��ä��\n");
	printf("===================\n");
}