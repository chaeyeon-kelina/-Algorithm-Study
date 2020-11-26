#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t)	((t)=(x), (x)=(y), (y)=(t))	//switch 위한 매크로

void name();		//학번, 이름, 전공 출력

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
		while (list[low] < pivot);		//left 다음 요소부터 증가하면서 pivot 값 이상인 요소 찾기
		do {
			high--;
		}
		while (list[high] > pivot);		//right 다음 요소부터 감소하면서 pivot 값 이하인 요소 찾기
		if (low < high) {
			SWAP(list[low], list[high], temp);		//두 요소 자리 바꾸기
		}
	} while (low < high);	//low, high가 교차할때까지 반복

	SWAP(list[left], list[high], temp);		//pivot을 중앙에 위치시킨다
	return high;	//pivot 위치 반환
}

void quick_sort(int list[], int left, int right, int n)
{
	if (left < right) {
		int p = partition(list, left, right);		//partition 호출해서 pivot 찾기
		printf("* pivot: %d\n", list[p]);		//pivot 출력
		for (int i = 0; i < n; i++)			//list 출력
			printf("%d ", list[i]);
		printf("\nleft size: %d	right size: %d\n", p-left, right-p);		//좌,우측 분할상태 출력
		quick_sort(list, left, p - 1, n);		//pivot 중심으로 pivot 바로 앞까지 재귀호출
		quick_sort(list, p + 1, right, n);		//pivot 중심으로 pivot 다음부터 끝까지 재귀호출
		
	}
}

int main() {
	name();
	
	int i, n;
	printf("Input size of list(1~10):");		//리스트 사이즈 입력받기
	scanf("%d", &n);
	int *list = (int*)malloc(sizeof(int)*n);		//배열 동적할당
	printf("Input %d numbers in the list\n", n);
	for(i=0; i<n; i++)
		scanf("%d", &list[i]);		//배열 요소 입력받기

	printf("\n<Before sorting>\n");		//정렬 전 배열 출력
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	quick_sort(list, 0, n-1, n);		//정렬

	printf("\n<After Quick Sorting>\n");		//정렬 후 배열 출력
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

	free(list);		//동적할당 메모리 해제
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