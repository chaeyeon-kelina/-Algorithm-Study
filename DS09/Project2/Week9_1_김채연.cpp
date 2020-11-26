#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

// 제출자 정보 출력 함수
void whoAmI() {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971060\n");
    printf("성명: 김서현\n");
    printf("====================\n");
    printf("\n");
}

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
} // 동적 메모리 할당 사용

void init(HeapType* h) {
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) { // item 노드를 추가하는 과정
    int i;

    i = ++(h->heap_size); // 노드 추가 후 증가된 말단노드 인덱스를 i에 대입

    while ((i != 1) && (item.key > h->heap[i / 2].key)) { // 트리를 거술러 올라가면서 부모 노드 key 값과 비교
        h->heap[i] = h->heap[i / 2]; // 추가 된 노드 key값보다 작은 경우 부모노드를 내림
        i /= 2; // 인덱스 새로운 위치(부모)로 이동
    }
    h->heap[i] = item; // 최종 결정된 위치에 새로운 노드를 insert
}

void insert_min_heap(HeapType* h, element item) { // item 노드를 추가하는 과정
    int i;

    i = ++(h->heap_size); // 노드 추가 후 증가된 말단노드 인덱스를 i에 대입

    while ((i != 1) && (item.key < h->heap[i / 2].key)) { // 트리를 거술러 올라가면서 부모 노드 key 값과 비교
        h->heap[i] = h->heap[i / 2]; // 추가 된 노드 key값보다 작은 경우 부모노드를 내림
        i /= 2; // 인덱스 새로운 위치(부모)로 이동
    }
    h->heap[i] = item; // 최종 결정된 위치에 새로운 노드를 insert
}

element delete_max_heap(HeapType* h) {
    int parent = 1, child = 2; // 두 번째 노드부터 root 노드와 비교 시작

    element item = h->heap[1]; // 삭제되는 노드(삭제 후 반환)
    element temp = h->heap[h->heap_size--]; // 말단 노드를 temp에 대입(노드 삭제 후 heap_size가 감소)

    while (child <= h->heap_size) { // 최대 말단까지 트리를 내려가면서 자식노드 key값과 temp key 비교
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) // sibling이 있을 때 둘 중 큰 값 찾기
            child++; // sibling이 비교대상 노드가 됨(subtree 선택)

        if (temp.key >= h->heap[child].key)
            break; // 자식 노드보다 신규 노드 key가 크면 위치 확정되어 반복 종료

        h->heap[parent] = h->heap[child]; // 자식 노드 key가 더 크면 parent 노드에 child 노드 복사
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp; // 확정위치(parent)에 신규노드 insert

    return item;
}

element delete_min_heap(HeapType* h) {
    int parent = 1, child = 2; // 두 번째 노드부터 root 노드와 비교 시작

    element item = h->heap[1]; // 삭제되는 노드(삭제 후 반환)
    element temp = h->heap[(h->heap_size)--]; // 말단 노드를 temp에 대입(노드 삭제 후 heap_size가 감소)

    while (child <= h->heap_size) { // 최대 말단까지 트리를 내려가면서 자식노드 key값과 temp key 비교
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key)) // sibling이 있을 때 둘 중 큰 값 찾기
            child++; // sibling이 비교대상 노드가 됨(subtree 선택)

        if (temp.key < h->heap[child].key)
            break; // 자식 노드보다 신규 노드 key가 크면 위치 확정되어 반복 종료

        h->heap[parent] = h->heap[child]; // 자식 노드 key가 더 크면 parent 노드에 child 노드 복사
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp; // 확정위치(parent)에 신규노드 insert

    return item;
}

void print_heap(HeapType* h1, HeapType* h2) {
    //  int i;

    printf("< Max heap >\n");
    for (int i = 1; i <= h1->heap_size; i++) {
        printf("%d ", h1->heap[i].key);
    }

    printf("\n");

    printf("< Min heap >\n");
    for (int i = 1; i <= h2->heap_size; i++) {
        printf("%d ", h2->heap[i].key);
    }

    free(h1);
    free(h2);
}

int main(void) {
    element insrt, dlt;
    char op; // operation 선택 변수

    HeapType* heap_max = create(); // 동적 메모리 할당 사용
    init(heap_max); // heap 초기화

    HeapType* heap_min = create(); // 동적 메모리 할당 사용
    init(heap_min); // heap 초기화

    whoAmI(); // 제출자 정보 출력

    do {
        // operation 선택
        printf("* Input Operation I(Insert)   D(Delete)   E(Exit): ");
        scanf(" %c", &op);

        switch (op) {
        case 'I':
            printf("Input value to insert: ");
            scanf("%d", &insrt);
            //     getchar();

            insert_max_heap(heap_max, insrt);
            insert_min_heap(heap_min, insrt);

            print_heap(heap_max, heap_min);

            break;
        case 'D':
            delete_max_heap(heap_max);
            delete_min_heap(heap_min);

            print_heap(heap_max, heap_min);

            break;
        case 'X':
            exit(0);
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
        printf("\n\n");
    } while (op != 'X');

    return 0;
}