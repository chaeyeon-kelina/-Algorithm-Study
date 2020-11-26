#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void name();		//����, �̸�, �й��� ����ϴ� �Լ�

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));		//���� �޸� �Ҵ� ���
}

void init(HeapType* h) {		//�� �ʱ�ȭ
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {		//�ִ� ���� �� insert
	int i;
	i = ++(h->heap_size);		//��� �߰� �� ������ ���� ��� �ε����� i�� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {		//Ʈ���� �Ž��� �ö󰡸� �θ� ��� key���� ��
		h->heap[i] = h->heap[i / 2];		//�θ��尡 �� ���� ��� �θ��带 ����
		i /= 2;		//�ε��� ���ο� ��ġ�� �̵�
	}
	h->heap[i] = item;		//���� ������ ��ġ�� ���ο� ��带 insert
}

void insert_min_heap(HeapType* h, element item) {		//�ּ� ���� �� insert
	int i;
	i = ++(h->heap_size);		//��� �߰� �� ������ ���� ��� �ε����� i�� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {		//Ʈ���� �Ž��� �ö󰡸� �θ� ��� key���� ��
		h->heap[i] = h->heap[i / 2];		//�θ��尡 �� Ŭ ��� �θ��带 ����
		i /= 2;		//�ε��� ���ο� ��ġ�� �̵�
	}
	h->heap[i] = item;		//���� ������ ��ġ�� ���ο� ��带 insert
}

void delete_max_heap(HeapType* h) {		//�ִ� ������ ��� ����
	int p = 1, c = 2;		//p�� �θ�, c�� �ڽ�. �ι�° ������ root���� �� ����
	element item = h->heap[1];		//�����Ǵ� ���
	element temp = h->heap[h->heap_size--];		//���� ��带 temp�� ����, ��� ���� �� heap_size ����
	while (c <= h->heap_size) {		//���� ������ Ʈ���� �������� �ڽĳ�� Ű ���� temp Ű �� ��
		if ((c < h->heap_size) && (h->heap[c].key < h->heap[c + 1].key))	//�ڽ� ��尡 �ΰ� �϶� �� �� ū �� ã��
			c++;
		if (temp.key >= h->heap[c].key)		//�űԳ�尡 �� ũ�� ��ġ Ȯ��
			break;
		h->heap[p] = h->heap[c];		//�ڽĳ�尡 �� ũ�� �θ� ��忡 �ڽ� ��� ����
		p = c;
		c *= 2;		//�ڽ� �ε����� �� �Ʒ� �ڽ����� ����
	}
	h->heap[p] = temp;		//���� ������ ��ġ�� �ű� ��� insert
}

void delete_min_heap(HeapType* h) {
	int p = 1, c = 2;		//p�� �θ�, c�� �ڽ�. �ι�° ������ root���� �� ����
	element item = h->heap[1];		//�����Ǵ� ���
	element temp = h->heap[h->heap_size--];		//���� ��带 temp�� ����, ��� ���� �� heap_size ����
	while (c <= h->heap_size) {		//���� ������ Ʈ���� �������� �ڽĳ�� Ű ���� temp Ű �� ��
		if ((c < h->heap_size) && (h->heap[c].key > h->heap[c + 1].key))	//�ڽ� ��尡 �ΰ� �϶� �� �� ���� �� ã��
			c++;
		if (temp.key <= h->heap[c].key)		//�űԳ�尡 �� ������ ��ġ Ȯ��
			break;
		h->heap[p] = h->heap[c];		//�ڽĳ�尡 �� ������ �θ� ��忡 �ڽ� ��� ����
		p = c;
		c *= 2;		//�ڽ� �ε����� �� �Ʒ� �ڽ����� ����
	}
	h->heap[p] = temp;		//���� ������ ��ġ�� �ű� ��� insert
}

void print_heap(HeapType* max_h, HeapType* min_h) {		//�� ���¸� ����ϴ� �Լ�
	printf("<Max Heap>\n");
	for (int i = 1; i <= max_h->heap_size; i++)
		printf("%d ", max_h->heap[i].key);		//�ִ� �� ���
	printf("\n<Min Heap>\n");
	for (int i = 1; i <= min_h->heap_size; i++)
		printf("%d ", min_h->heap[i].key);		//�ּ� �� ���
	printf("\n");
}

int main() {
	name();

	char ans;
	element item;
	//�� ����
	HeapType* max_heap = create();
	HeapType* min_heap = create();
	//�� �ʱ�ȭ
	init(max_heap);
	init(min_heap);
	while (true) {
		printf("*Input Operation I(Insert) D(Delete) X(Exit): ");
		scanf(" %c", &ans);
		switch (ans) {
			case 'I':		//�� ����ֱ�
				printf("Input value to insert:");
				scanf("%d", &item);
				insert_max_heap(max_heap, item);
				insert_min_heap(min_heap, item);
				print_heap(max_heap, min_heap);
				break;
			case 'D':		//��� �����ϱ�
				delete_max_heap(max_heap);
				delete_min_heap(min_heap);
				print_heap(max_heap, min_heap);
				break;
			case 'X':		//����
				exit(1);	
		}
	}

	free(max_heap);
	free(min_heap);

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