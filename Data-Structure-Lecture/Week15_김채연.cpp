#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11

typedef struct
{
	int key;
}element;

struct list {
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE];

void name();		//����, �й�, �̸� ���

int hash_function(int key) {		//��ⷯ ���� �̿��� �ؽ� �Լ�
	return key % TABLE_SIZE;
}

void hash_chain_add(element item, struct list* ht[]) // key�� hash table�� insert
{
	int hash_value = hash_function(item.key);

	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];

	for (; node; node_before = node, node = node->link) { // �ش� ��ġ�� ��� �˻�
		if (node->item.key == item.key) { // ���� ���� ���������
			fprintf(stderr, "%d is already stored\n", item.key);
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list)); // �ش� key ���� ����Ǿ����� ������
	ptr->item = item; // ���ο� ��忡 key�� ��ũ ����
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr; // ������ ��ġ�� �߰�
	else
		ht[hash_value] = ptr; // �ش� ��ġ�� ��尡 �����Ƿ� ù ���� ����
}

void hash_chain_search(element item, struct list* ht[]) {
	struct list* node;
	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {		//�ش� ��ġ�� ��� �˻�
		if (node->item.key == item.key) {	//���� ���� ��� ������
			fprintf(stderr, "%d is found at index %d\n", item.key, hash_value);		//�˻� ����
			return;
		}
	}
	fprintf(stderr, "%d is not in the table\n", item.key);
}

void hash_chain_print(struct list* ht[]) {		//���̺��� ����ϴ� �Լ�
	struct list* node;
	printf("\n===============================\n");
	for (int i = 0; i < TABLE_SIZE; i++) {
		printf("[%d]", i);
		for (node = ht[i]; node; node = node->link)
			printf(" -%3d", node->item.key);
		printf("\n");
	}
	printf("===============================\n\n");
}

void hash_chain_delete(element item, struct list* ht[]) {		//�ش� �� ����� �Լ�
	int hash_value = hash_function(item.key);
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {		//�ش� ��ġ�� ��� �˻�
		if (node->item.key == item.key) {		//ã����
			if (node_before)
				node_before->link = node->link;
			else		//�� ��尡 ����Ʈ�� ù��° ����� ���
				ht[hash_value] = node->link;
			return;
		}
	}
	
}

int main() {
	name();

	int data[11];
	element e;
	int ans = 0;
	printf("Input 10 keys to add\n");
	for (int i = 0; i < 10; i++) {		//10���� �� �Է¹ޱ�
		scanf("%d", &data[i]);
		e.key = data[i];
		hash_chain_add(e, hash_table);		//�ؽ� ���̺� �߰�
	}
	hash_chain_print(hash_table);

	while (true) {
		printf("\nChoose operation (1.insert  2.delete  3.search  4.print  5.exit):");
		scanf("%d", &ans);
		if (ans == 1) {
			printf("input data to add:");
			scanf("%d", &e.key);
			hash_chain_add(e, hash_table);		//�� �߰�
		}
		else if (ans == 2) {
			printf("input data to delete:");
			scanf("%d", &e.key);
			hash_chain_delete(e, hash_table);		//�� ����
		}
		else if (ans == 3) {
			printf("input data to search:");
			scanf("%d", &e.key);
			hash_chain_search(e, hash_table);		//�� �˻�
		}
		else if (ans == 4)
			hash_chain_print(hash_table);		//���̺� ���
		else if (ans == 5) {		//���α׷� ����
			printf("\nProgram finished");
			break;
		}
		else
			printf("Wrong input\n");
	}

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