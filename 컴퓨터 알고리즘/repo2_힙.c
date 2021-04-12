#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100
typedef int element;

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

typedef struct {
	element stack[MAX_ELEMENT];
	int top;
}StackType;

void init_heap(HeapType* h) {
	h->heap_size = 0;
}

void upHeap(HeapType* h) {
	int i = h->heap_size;
	int key = h->heap[i];

	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}


void insertItem(HeapType* h, int key) {
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}

void printHeap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
	printf("\n");
}

void init_stack(StackType* s) {
	s->top = -1;
}

int isEmpty(StackType* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}

element pop(StackType* s) {
	if (isEmpty(s) == 1)
		return -1;
	else
		return s->stack[(s->top)--];
}

void push(StackType* s, element item) {
	s->stack[++(s->top)] = item;
}

void binaryExpansion(int i, StackType* s) {
	while (i >= 2) {
		push(s, i % 2);
		i /= 2;
	}
	push(s, i);
}

int findLastNode(HeapType *h, int n) {
	StackType stack;
	int bit;
	int v = -1;
	int i = 0;

	init_stack(&stack);
	binaryExpansion(h->heap_size, &stack);

	while (isEmpty(&stack) != 1) {
		bit = pop(&stack);
		if (bit == 0) {
			i = i * 2;
			v = h->heap[i];
		}
		else {
			i = i * 2 + 1;
			v = h->heap[i];
		}
	}
	return v;
}

int main() {
	HeapType heap;
	init_heap(&heap);
	insertItem(&heap, 2);
	insertItem(&heap, 6);
	insertItem(&heap, 4);
	insertItem(&heap, 14);
	insertItem(&heap, 7);
	insertItem(&heap, 12);
	insertItem(&heap, 8);
	insertItem(&heap, 17);
	insertItem(&heap, 15);
	insertItem(&heap, 9);

	printf("힙의 마지막 노드 : %d", findLastNode(&heap, heap.heap_size));
//	printHeap(&heap);

	return 0;
}
