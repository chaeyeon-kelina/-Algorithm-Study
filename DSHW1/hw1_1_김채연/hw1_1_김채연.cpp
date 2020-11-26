#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode {		//다항식의 항마다 생성되는 노드
	int coef;		//계수
	int exponent;		//차수
	struct ListNode *link;
}ListNode;

typedef struct ListType {		//다항식의 정보를 저장하는 노드
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void name();		//이름, 학번, 전공 출력
void error(const char* message);		//에러 메세지를 출력하는 함수

ListType* create() {		//다항식의 정보를 저장하는 노드 생성하는 함수
	ListType*pinfo = (ListType*)malloc(sizeof(ListType));
	pinfo->head = NULL;
	pinfo->tail = NULL;
	pinfo->size = 0;
	return pinfo;
}

void insert_poly(ListType* pinfo, int coef, int exponent) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//식을 저장할 노드 생성
	if (p == NULL)		//메모리 할당 실패
		error("memory allocation error\n");
	p->coef = coef;				//새로운 노드 설정
	p->exponent = exponent;
	p->link = NULL;
	if (pinfo->tail == NULL)		//첫번째 노드 생성일 때
		pinfo->head = pinfo->tail = p;
	else {		//기존에 노드가 있다면
		pinfo->tail->link = p;		//다항식 리스트에 노드 추가
		pinfo->tail = p;		//다항식 마지막 항의 정보를 새 노드 주소로 수정
	}
	pinfo->size++;		//다항식의 개수 증가
}

void poly_print(ListType* pinfo) {		//다항식을 출력하는 함수
	ListNode *node = pinfo->head;
	for (int i = 0; i < pinfo->size - 1; i++) {
		printf("%dx^%d + ", node->coef, node->exponent);
		node = node->link;
	}
	printf("%dx^%d \n\n", node->coef, node->exponent);
}

int calculate(ListType *pinfo, int x) {		//다항식을 계산하는 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p = pinfo->head;

	int result = 0;
	for (int i = 0; i < pinfo->size; i++) {
		result += (p->coef) * (int)(pow(x, p->exponent));		//계수 * x^차수
		p = p->link;	//다음 노드로 이동
	}
	return result;		//결과값 반환
}

void Clear(ListType* d) //각 노드 free
{
	ListNode* temp = d->head;
	ListNode* p = NULL;
	while (temp->link != NULL) {		//노드 끝까지 반복
		p = temp;
		temp = p->link;
		free(p);		//메모리 반환
	}
	free(temp);
}


int main() {
	name();

	int coef, exponent, x;
	ListType* polyinfo = create();		//다항식의 정보를 저장할 노드 생성
//	ListNode* p = NULL;

	printf("Input coef and exponent of polynomial(마지막항: exponent를 0으로 입력)\n");
	while (true) {
		scanf("%d %d", &coef, &exponent);
		insert_poly(polyinfo, coef, exponent);		//다항식 생성
		if (exponent == 0)		//차수에 0을 입력하면 반복문 종료
			break;
	}
	printf("<Polynominal>\n");
	poly_print(polyinfo);		//다항식 출력

	printf("Input the value x: ");
	scanf("%d", &x);
	printf("Result of polynomal with x: %d", calculate(polyinfo, x));		//다항식 계산한 값을 출력

	
	Clear(polyinfo);		//다항식 각 노드 메모리 반환
	free(polyinfo);		//메모리 반환

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

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
