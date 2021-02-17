#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick_sort.h"
#define SIZE 100
#define INDEX_SIZE 256

typedef struct {
	int key;
	int index;
}itable;
itable index_list[INDEX_SIZE];		//index table

int list[SIZE];

void name();

int seq_search(int key, int low, int high)
{
	int i;
	for (int i = low; i <= high; i++)		// �ش� ������ ���� ã�� key�� �ִ��� �˻�
		if (list[i] == key)
			return i;
	return -1;			//������ -1 ��ȯ
}

int index_search(int key, int n) {
	int i, low, high;
	if (key < list[0] || key>list[n - 1])
		return -1;			// ���� ���� ��� ����
	for (i = 0; i < INDEX_SIZE; i++) {
		if (index_list[i].key <= key && key < index_list[i + 1].key) {		//�ش� Ű�� ���Ե� ��ġ ã��
			break;
		}
	}

	printf("index location: %d\n", i);			//index ��ġ ���

	if (i == INDEX_SIZE) {					//���������� i�� ������ ��� ������ index ������ key ���Ե� ���
		low = index_list[i - 1].index;
		high = n;
	}
	else {				//Ư�� index i~i+1 ���̿� key ���Ե� ���
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}
	return seq_search(key, low, high);
}

void make_itable(int interval, int n) {				//�ε��� ���̺� ����
	int i = 0;
	while(i*interval < n) {			//�ش� ������ list size�� ���� ������
		index_list[i].index = i*interval;		//�ε����� �ش� ����Ʈ�� �ε��� �߰�
		index_list[i].key = list[i*interval];		//Ű���� �ش� ����Ʈ�� ������ �ִ� �� �߰�
		printf("%4d : %4d\n", i, index_list[i].key);		//�ε����� ��ȣ�� �ش� �ε����� Ű �� ���
		i++;
	}
}

int main() {
	name();			//����, �й�, �̸� ���

	int interval, key, res;

	srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 1000;		//����(0~999) �� size��ŭ �����ؼ� list �����

	for (int i = 0; i < SIZE; i++) {			//����Ʈ ���
		if (i % 10 == 0)
			putchar('\n');
		printf("%4d", list[i]);
	}

	printf("\n\n<���İ��>\n");
	quick_sort(list, 0, SIZE);		//quick ���� ȣ��
	for (int i = 0; i < SIZE; i++) {				//���ĵ� ����Ʈ ���
		if (i % 10 == 0)
			putchar('\n');
		printf("%4d", list[i]);
	}

	printf("\n\nInput index interval(1-100):");
	scanf("%d", &interval);				//index interval �Է¹ޱ�

	printf("\n<index table>\n");
	make_itable(interval, SIZE);		//�ε��� ���̺� ����

	printf("\n\nInput key to serach:");		//ã�� Ű�� �Է¹ޱ�
	scanf("%d", &key);

	printf("\n<indexed_search���>\n");			//Ž�� ��� ���
	res = index_search(key, SIZE);

	if (res != -1)
		printf("%d is found in position %d\n", key, res);
	else
		printf("search failed.\n");

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