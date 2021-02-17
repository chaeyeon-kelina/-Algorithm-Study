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

void name();		//전공, 학번, 이름 출력

int hash_function(int key) {		//모듈러 연산 이용한 해시 함수
	return key % TABLE_SIZE;
}

void hash_chain_add(element item, struct list* ht[]) // key를 hash table에 insert
{
	int hash_value = hash_function(item.key);

	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];

	for (; node; node_before = node, node = node->link) { // 해당 위치의 노드 검색
		if (node->item.key == item.key) { // 같은 값이 들어있으면
			fprintf(stderr, "%d is already stored\n", item.key);
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list)); // 해당 key 값이 저장되어있지 않으면
	ptr->item = item; // 새로운 노드에 key와 링크 설정
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr; // 마지막 위치에 추가
	else
		ht[hash_value] = ptr; // 해당 위치에 노드가 없으므로 첫 노드로 연결
}

void hash_chain_search(element item, struct list* ht[]) {
	struct list* node;
	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {		//해당 위치의 노드 검색
		if (node->item.key == item.key) {	//같은 값이 들어 있으면
			fprintf(stderr, "%d is found at index %d\n", item.key, hash_value);		//검색 성공
			return;
		}
	}
	fprintf(stderr, "%d is not in the table\n", item.key);
}

void hash_chain_print(struct list* ht[]) {		//테이블을 출력하는 함수
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

void hash_chain_delete(element item, struct list* ht[]) {		//해당 값 지우는 함수
	int hash_value = hash_function(item.key);
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {		//해당 위치의 노드 검색
		if (node->item.key == item.key) {		//찾으면
			if (node_before)
				node_before->link = node->link;
			else		//그 노드가 리스트의 첫번째 노드인 경우
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
	for (int i = 0; i < 10; i++) {		//10개의 값 입력받기
		scanf("%d", &data[i]);
		e.key = data[i];
		hash_chain_add(e, hash_table);		//해시 테이블에 추가
	}
	hash_chain_print(hash_table);

	while (true) {
		printf("\nChoose operation (1.insert  2.delete  3.search  4.print  5.exit):");
		scanf("%d", &ans);
		if (ans == 1) {
			printf("input data to add:");
			scanf("%d", &e.key);
			hash_chain_add(e, hash_table);		//값 추가
		}
		else if (ans == 2) {
			printf("input data to delete:");
			scanf("%d", &e.key);
			hash_chain_delete(e, hash_table);		//값 삭제
		}
		else if (ans == 3) {
			printf("input data to search:");
			scanf("%d", &e.key);
			hash_chain_search(e, hash_table);		//값 검색
		}
		else if (ans == 4)
			hash_chain_print(hash_table);		//테이블 출력
		else if (ans == 5) {		//프로그램 종료
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
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}