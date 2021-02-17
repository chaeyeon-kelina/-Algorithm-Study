#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t)	((t)=(x), (x)=(y), (y)=(t))	//switch 위한 매크로

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
		} while (list[low] < pivot);		//left 다음 요소부터 증가하면서 pivot 값 이상인 요소 찾기
		do {
			high--;
		} while (list[high] > pivot);		//right 다음 요소부터 감소하면서 pivot 값 이하인 요소 찾기
		if (low < high) {
			SWAP(list[low], list[high], temp);		//두 요소 자리 바꾸기
		}
	} while (low < high);	//low, high가 교차할때까지 반복

	SWAP(list[left], list[high], temp);		//pivot을 중앙에 위치시킨다
	return high;	//pivot 위치 반환
}

int median_of_three(int list[], int left, int right, int mid) { //리스트의 첫번째 수, 마지막 수, 중간에 위치한 수 중 median 값을 구하는 함수
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
	t = median_of_three(list, left, right, mid);//리스트의 첫번째 수, 마지막 수, 중간에 위치한 수 중 median 값을 구하기
	pivot = list[t];		//median값을 pivot으로 설정
	low = left;
	high = right + 1;
	do
	{
		do {
			low++;
		} while (list[low] < pivot);		//left 다음 요소부터 증가하면서 pivot 값 이상인 요소 찾기
		do {
			high--;
		} while (list[high] > pivot);		//right 다음 요소부터 감소하면서 pivot 값 이하인 요소 찾기
		if (low < high) {
			SWAP(list[low], list[high], temp);		//두 요소 자리 바꾸기
		}
	} while (low < high);	//low, high가 교차할때까지 반복

	SWAP(list[t], list[high], temp);		//pivot을 중앙에 위치시킨다
	return high;	//pivot 위치 반환
}

void quick_sort(int list[], int left, int right, int n)
{
	if (left < right) {
		int p = partition(list, left, right);		//partition 호출해서 pivot 찾기
		printf("* pivot: %d\n", list[p]);		//pivot 출력
		quick_sort(list, left, p - 1, n);		//pivot 중심으로 pivot 바로 앞까지 재귀호출
		quick_sort(list, p + 1, right, n);		//pivot 중심으로 pivot 다음부터 끝까지 재귀호출
	}
}

void quick_sort_mid(int list[], int left, int right, int mid, int n)
{
	if (left < right) {
		int p = partition_mid(list, left, right, mid);		//partition_mid 호출해서 pivot 찾기
		printf("* pivot: %d\n", list[p]);		//pivot 출력
		quick_sort_mid(list, left, p - 1, (p-1+left)/2, n);		//pivot 중심으로 pivot 바로 앞까지 재귀호출
		quick_sort_mid(list, p + 1, right, (p+1+right)/2, n);		//pivot 중심으로 pivot 다음부터 끝까지 재귀호출
	}
}

int main() {
	name();			//전공, 이름, 학번 출력

	int i, n;
	printf("Input size of list(1~50):");		//리스트 사이즈 입력받기
	scanf("%d", &n);
	int* list = (int*)malloc(sizeof(int) * n);		//배열 동적할당
	printf("Input %d numbers in the list\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);		//배열 요소 입력받기

	printf("\n<<정렬 이전 상태>>\n");		//정렬 전 배열 출력
	for (i = 0; i < n; i++)
		printf("%3d ", list[i]);
	printf("\n");
	printf("\n<Quick Sorting>\n");
	quick_sort(list, 0, n - 1, n);		//정렬
	printf("<Result>\n");		//정렬 후 배열 출력
	for (i = 0; i < n; i++)
		printf("%3d ", list[i]);

	printf("\n\n<Quick Sorting(Median of three)>\n");
	quick_sort_mid(list, 0, n - 1, n/2, n);		//정렬
	printf("<Result>\n");		//정렬 후 배열 출력
	for (i = 0; i < n; i++)
		printf("%3d ", list[i]);

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