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
	for (int i = low; i <= high; i++)		// 해당 범위에 내가 찾는 key가 있는지 검사
		if (list[i] == key)
			return i;
	return -1;			//없으면 -1 반환
}

int index_search(int key, int n) {
	int i, low, high;
	if (key < list[0] || key>list[n - 1])
		return -1;			// 범위 밖인 경우 종료
	for (i = 0; i < INDEX_SIZE; i++) {
		if (index_list[i].key <= key && key < index_list[i + 1].key) {		//해당 키가 포함된 위치 찾기
			break;
		}
	}

	printf("index location: %d\n", i);			//index 위치 출력

	if (i == INDEX_SIZE) {					//마지막까지 i가 증가된 경우 마지막 index 구간에 key 포함된 경우
		low = index_list[i - 1].index;
		high = n;
	}
	else {				//특정 index i~i+1 사이에 key 포함된 경우
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}
	return seq_search(key, low, high);
}

void make_itable(int interval, int n) {				//인덱스 테이블 생성
	int i = 0;
	while(i*interval < n) {			//해당 범위가 list size를 넘지 않으면
		index_list[i].index = i*interval;		//인덱스에 해당 리스트의 인덱스 추가
		index_list[i].key = list[i*interval];		//키값에 해당 리스트가 가지고 있는 값 추가
		printf("%4d : %4d\n", i, index_list[i].key);		//인덱스의 번호와 해당 인덱스의 키 값 출력
		i++;
	}
}

int main() {
	name();			//전공, 학번, 이름 출력

	int interval, key, res;

	srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 1000;		//난수(0~999) 를 size만큼 생성해서 list 만들기

	for (int i = 0; i < SIZE; i++) {			//리스트 출력
		if (i % 10 == 0)
			putchar('\n');
		printf("%4d", list[i]);
	}

	printf("\n\n<정렬결과>\n");
	quick_sort(list, 0, SIZE);		//quick 정렬 호출
	for (int i = 0; i < SIZE; i++) {				//정렬된 리스트 출력
		if (i % 10 == 0)
			putchar('\n');
		printf("%4d", list[i]);
	}

	printf("\n\nInput index interval(1-100):");
	scanf("%d", &interval);				//index interval 입력받기

	printf("\n<index table>\n");
	make_itable(interval, SIZE);		//인덱스 테이블 생성

	printf("\n\nInput key to serach:");		//찾을 키값 입력받기
	scanf("%d", &key);

	printf("\n<indexed_search결과>\n");			//탐색 결과 출력
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
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}