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

int find_index(HeapType* h, element item) {		//�־��� ���� ���� �����ϴ� �ε��� ��ȯ
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == item.key)			//�־��� ���� ã���� ���
			return i;		//�ش� ����� �ε��� ��ȯ
	}
	return 0;		//ã�� ���� ���
}

void delete_item(HeapType* h, element item) {
	int index = find_index(h, item);		//�ش� ���� �����ϴ� �ε��� ã��
	if (index != 0) {		//���� �����Ѵٸ�
		int p = index, c = index*2;		//p�� �ش� ���� �����ϴ� ���(�θ�), c�� �� �ڽ�.
		element item = h->heap[p];		//�����Ǵ� ��� : �ش� ���� �����ϴ� ���
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
	else            //�ش� ���� �������� �ʴ´ٸ�
		printf("value does not exist\n");
}

bool same_value(HeapType* h, element value) {		//���� ���� ���� �����ϴ��� �˻��ϴ� �Լ�
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == value.key)
			return true;		//�����Ѵٸ� true ��ȯ
	}
	return false;		//�������� �ʴ´ٸ� false
}

void print_heap(HeapType* max_h) {		//�� ���¸� ����ϴ� �Լ�
	for (int i = 1; i <= max_h->heap_size; i++)
		printf("%d ", max_h->heap[i].key);		//�ִ� �� ���
	printf("\n");
}

int main() {
	name();

	char ans;
	element item;
	//�� ����
	HeapType* heap = create();
	//�� �ʱ�ȭ
	init(heap);
	while (true) {
		printf("Input Operation I(Insert) D(Delete) P(Print) X(Exit): ");
		scanf(" %c", &ans);
		switch (ans) {
		case 'I':		//�� ����ֱ�
			printf("Input value to insert:");
			scanf("%d", &item);
			if (same_value(heap, item)) {		//���� ���� ���� �̹� ���� �����Ѵٸ�
				printf("same value exists\n");
				break;
			}
			insert_max_heap(heap, item);		//���� ���� ���� �������� �ʴ´ٸ� ���� �� ����ֱ�
			break;
		case 'D':		//��� �����ϱ�
			printf("Input value to delete:");
			scanf("%d", &item);
			delete_item(heap, item);		//�ش� ���� ã�Ƽ� ����
			break;
		case 'P':
			print_heap(heap);		//�� ���� ���
			break;
		case 'X':		//����
			exit(1);
		}
	}

	free(heap);

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