#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t)	((t)=(x), (x)=(y), (y)=(t))	//switch ���� ��ũ��

void name();

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
		} while (list[low] < pivot);		//left ���� ��Һ��� �����ϸ鼭 pivot �� �̻��� ��� ã��
		do {
			high--;
		} while (list[high] > pivot);		//right ���� ��Һ��� �����ϸ鼭 pivot �� ������ ��� ã��
		if (low < high) {
			SWAP(list[low], list[high], temp);		//�� ��� �ڸ� �ٲٱ�
		}
	} while (low < high);	//low, high�� �����Ҷ����� �ݺ�

	SWAP(list[left], list[high], temp);		//pivot�� �߾ӿ� ��ġ��Ų��
	return high;	//pivot ��ġ ��ȯ
}

int median_of_three(int list[], int left, int right, int mid) { //����Ʈ�� ù��° ��, ������ ��, �߰��� ��ġ�� �� �� median ���� ���ϴ� �Լ�
	if (left >= mid) {
		if (mid >= right)
			return mid;
		else if (left <= right)
			return left;
		else
			return right;
	}
	else if (left >= right)
		return left;
	else if (mid >= right)
		return right;
	else
		return mid;
}

int partition_mid(int list[], int left, int right, int mid){
	int pivot, t;
	int temp, low, high;
	t = median_of_three(list, left, right, mid);//����Ʈ�� ù��° ��, ������ ��, �߰��� ��ġ�� �� �� median ���� ���ϱ�
	pivot = list[t];		//median���� pivot���� ����
	low = left;
	high = right + 1;
	do
	{
		do {
			low++;
		} while (list[low] < pivot);		//left ���� ��Һ��� �����ϸ鼭 pivot �� �̻��� ��� ã��
		do {
			high--;
		} while (list[high] > pivot);		//right ���� ��Һ��� �����ϸ鼭 pivot �� ������ ��� ã��
		if (low < high) {
			SWAP(list[low], list[high], temp);		//�� ��� �ڸ� �ٲٱ�
		}
	} while (low < high);	//low, high�� �����Ҷ����� �ݺ�

	SWAP(list[t], list[high], temp);		//pivot�� �߾ӿ� ��ġ��Ų��
	return high;	//pivot ��ġ ��ȯ
}

void quick_sort(int list[], int left, int right, int n)
{
	if (left < right) {
		int p = partition(list, left, right);		//partition ȣ���ؼ� pivot ã��
		printf("* pivot: %d\n", list[p]);		//pivot ���
		quick_sort(list, left, p - 1, n);		//pivot �߽����� pivot �ٷ� �ձ��� ���ȣ��
		quick_sort(list, p + 1, right, n);		//pivot �߽����� pivot �������� ������ ���ȣ��
	}
}

void quick_sort_mid(int list[], int left, int right, int mid, int n)
{
	if (left < right) {
		int p = partition_mid(list, left, right, mid);		//partition_mid ȣ���ؼ� pivot ã��
		printf("* pivot: %d\n", list[p]);		//pivot ���
		quick_sort_mid(list, left, p - 1, (p-1+left)/2, n);		//pivot �߽����� pivot �ٷ� �ձ��� ���ȣ��
		quick_sort_mid(list, p + 1, right, (p+1+right)/2, n);		//pivot �߽����� pivot �������� ������ ���ȣ��
	}
}

int main() {
	name();			//����, �̸�, �й� ���

	int i, n;
	printf("Input size of list(1~50):");		//����Ʈ ������ �Է¹ޱ�
	scanf("%d", &n);
	int* list = (int*)malloc(sizeof(int) * n);		//�迭 �����Ҵ�
	printf("Input %d numbers in the list\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);		//�迭 ��� �Է¹ޱ�

	printf("\n<<���� ���� ����>>\n");		//���� �� �迭 ���
	for (i = 0; i < n; i++)
		printf("%3d ", list[i]);
	printf("\n");
	printf("\n<Quick Sorting>\n");
	quick_sort(list, 0, n - 1, n);		//����
	printf("<Result>\n");		//���� �� �迭 ���
	for (i = 0; i < n; i++)
		printf("%3d ", list[i]);

	printf("\n\n<Quick Sorting(Median of three)>\n");
	quick_sort_mid(list, 0, n - 1, n/2, n);		//����
	printf("<Result>\n");		//���� �� �迭 ���
	for (i = 0; i < n; i++)
		printf("%3d ", list[i]);

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