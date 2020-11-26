#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

// ������ ���� ��� �Լ�
void whoAmI() {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971060\n");
    printf("����: �輭��\n");
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
} // ���� �޸� �Ҵ� ���

void init(HeapType* h) {
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) { // item ��带 �߰��ϴ� ����
    int i;

    i = ++(h->heap_size); // ��� �߰� �� ������ ���ܳ�� �ε����� i�� ����

    while ((i != 1) && (item.key > h->heap[i / 2].key)) { // Ʈ���� �ż��� �ö󰡸鼭 �θ� ��� key ���� ��
        h->heap[i] = h->heap[i / 2]; // �߰� �� ��� key������ ���� ��� �θ��带 ����
        i /= 2; // �ε��� ���ο� ��ġ(�θ�)�� �̵�
    }
    h->heap[i] = item; // ���� ������ ��ġ�� ���ο� ��带 insert
}

void insert_min_heap(HeapType* h, element item) { // item ��带 �߰��ϴ� ����
    int i;

    i = ++(h->heap_size); // ��� �߰� �� ������ ���ܳ�� �ε����� i�� ����

    while ((i != 1) && (item.key < h->heap[i / 2].key)) { // Ʈ���� �ż��� �ö󰡸鼭 �θ� ��� key ���� ��
        h->heap[i] = h->heap[i / 2]; // �߰� �� ��� key������ ���� ��� �θ��带 ����
        i /= 2; // �ε��� ���ο� ��ġ(�θ�)�� �̵�
    }
    h->heap[i] = item; // ���� ������ ��ġ�� ���ο� ��带 insert
}

element delete_max_heap(HeapType* h) {
    int parent = 1, child = 2; // �� ��° ������ root ���� �� ����

    element item = h->heap[1]; // �����Ǵ� ���(���� �� ��ȯ)
    element temp = h->heap[h->heap_size--]; // ���� ��带 temp�� ����(��� ���� �� heap_size�� ����)

    while (child <= h->heap_size) { // �ִ� ���ܱ��� Ʈ���� �������鼭 �ڽĳ�� key���� temp key ��
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) // sibling�� ���� �� �� �� ū �� ã��
            child++; // sibling�� �񱳴�� ��尡 ��(subtree ����)

        if (temp.key >= h->heap[child].key)
            break; // �ڽ� ��庸�� �ű� ��� key�� ũ�� ��ġ Ȯ���Ǿ� �ݺ� ����

        h->heap[parent] = h->heap[child]; // �ڽ� ��� key�� �� ũ�� parent ��忡 child ��� ����
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp; // Ȯ����ġ(parent)�� �űԳ�� insert

    return item;
}

element delete_min_heap(HeapType* h) {
    int parent = 1, child = 2; // �� ��° ������ root ���� �� ����

    element item = h->heap[1]; // �����Ǵ� ���(���� �� ��ȯ)
    element temp = h->heap[(h->heap_size)--]; // ���� ��带 temp�� ����(��� ���� �� heap_size�� ����)

    while (child <= h->heap_size) { // �ִ� ���ܱ��� Ʈ���� �������鼭 �ڽĳ�� key���� temp key ��
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key)) // sibling�� ���� �� �� �� ū �� ã��
            child++; // sibling�� �񱳴�� ��尡 ��(subtree ����)

        if (temp.key < h->heap[child].key)
            break; // �ڽ� ��庸�� �ű� ��� key�� ũ�� ��ġ Ȯ���Ǿ� �ݺ� ����

        h->heap[parent] = h->heap[child]; // �ڽ� ��� key�� �� ũ�� parent ��忡 child ��� ����
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp; // Ȯ����ġ(parent)�� �űԳ�� insert

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
    char op; // operation ���� ����

    HeapType* heap_max = create(); // ���� �޸� �Ҵ� ���
    init(heap_max); // heap �ʱ�ȭ

    HeapType* heap_min = create(); // ���� �޸� �Ҵ� ���
    init(heap_min); // heap �ʱ�ȭ

    whoAmI(); // ������ ���� ���

    do {
        // operation ����
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