#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

int visited[MAX_VERTICES];		//�湮 üũ�� �迭

typedef struct GraphType {
	int n;		//vertex�� ��
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

typedef struct StackType {		//���� ����ü
	int vertex[MAX_VERTICES];		//vertex�� ���� �迭
	int top;
}StackType;

void name();

void init(GraphType* g) {		//�׷��� �ʱ�ȭ
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;		//��� ���� 0���� �ʱ�ȭ
	}
}

void init_stack(StackType* s) {		//���� �ʱ�ȭ
	s->top = -1;
}

void init_visited() {		//�湮 üũ�ϴ� �迭 �ʱ�ȭ
	for (int i = 0; i < MAX_VERTICES; i++)
		visited[i] = 0;
}

void insert_vertex(GraphType* g, int v) {		//vertex insertion ����
	if (g->n + 1 > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�\n");
		return;
	}
	else
		g->n++;		//vertex ���� ����
}

void insert_edge(GraphType* g, int start, int end) {		//������ �׷����� edge insertion ����

	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ������ ��ȣ ����\n");
		return;
	}
	g->adj_mat[start][end] = 1;		//��Ī ��ġ�� ��� 1�� set
	g->adj_mat[end][start] = 1;
}

void insert_edge_digraph(GraphType* g, int start, int end) {	//���� �׷����� edge insertion ����
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ������ ��ȣ ����\n");
		return;
	}
	g->adj_mat[start][end] = 1;
}

void print_adj_mat(GraphType* g) {			//���� ��� ���
	int r, c;
	printf("<Graph Matrix>\n");
	for (r = 0; r < g->n; r++) {
		for (c = 0; c < g->n; c++)
			printf("%2d", g->adj_mat[r][c]);
		printf("\n");
	}
}

void dfs_recursive(GraphType* g, int v) {		//��ͷ� dfs Ž��
	int w;
	visited[v] = true;		//dfs ���۵� vertex�� �湮�� ������ ǥ��
	printf("vertex%d  ", v);		//�湮�� vertex ���
	for (w = 0; w < g->n; w++) {			//�ش� vertex�� row�� �ϳ��� �˻��ؼ�
		if (g->adj_mat[v][w] && !visited[w])		//Ư�� vertex���� 1�ε� ���� �湮 �������� 
			dfs_recursive(g, w);		//�� vertex�� �̵��ؼ� �ٽ� dfs ����
	}
}

bool is_full(StackType* s) {		//������ ���� á���� �˻�
	return (s->top == (MAX_VERTICES - 1));
}

bool is_empty(StackType* s) {		//������ ������� �˻�
	return (s->top == -1);
}

int pop(StackType* s) {		//stack���� pop�ϴ� �Լ�
	if (is_empty(s)) {			//������ ����ٸ� ���� ���
		fprintf(stderr, "Stack empty\n");
		exit(1);
	}
	else
		return s->vertex[(s->top)--];
}

void push(StackType* s, int item) {		//stack�� push�ϴ� �Լ�
	if (is_full(s)) {			//������ ���� á�ٸ� ���� ���
		fprintf(stderr, "Overflow\n");
		return;
	}
	else
		s->vertex[++(s->top)] = item;		//���ÿ� �� ����ֱ�
}

void dfs_stack(GraphType* g, int v) {		//�������� dfs Ž��
	int w;
	StackType s;
	init_stack(&s);		//���� �ʱ�ȭ
	init_visited();		//�湮 üũ�ϴ� �迭 �ʱ�ȭ
	push(&s, v);		//dfs ���۵� vertex�� �湮�� ������ ǥ��
	while (!is_empty(&s)) {		//������ ���� �ʾҴٸ�
		v = pop(&s);
		if (!visited[v]) {		//v�� �湮���� �ʾҴٸ�
			printf("vertex%d  ", v);
			visited[v] = true;			//�湮 üũ
			for (w = 0; w < g->n; w++) {					//�ش� vertex�� row�� �ϳ��� �˻��ؼ�
				if (g->adj_mat[v][w] && !visited[w]) {		//Ư�� vertex���� 1�ε� ���� �湮 �������� 
					push(&s, w);		//�� vertex�� �̵��ؼ� �ٽ� dfs ����
				}
			}
		}
	}
}

int main() {
	name();

	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));		//�׷��� �����Ҵ�

	//������ �׷���
	init(g);
	for (int i = 0; i < 5; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 4);
	insert_edge(g, 2, 4);
	print_adj_mat(g);			//������� ���
	printf("<Depth First Search-recursive>\n");
	dfs_recursive(g, 0);			//dfs ��� ������� ���� ���� ���
	printf("\n<Depth First Search-stack>\n");
	dfs_stack(g, 0);			//dfs ���� ������� ���� ���� ���

	printf("\n\n");

	//���� �׷���
	init(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);
	insert_edge_digraph(g, 0, 2);
	insert_edge_digraph(g, 2, 1);
	insert_edge_digraph(g, 1, 5);
	insert_edge_digraph(g, 2, 3);
	insert_edge_digraph(g, 0, 4);
	insert_edge_digraph(g, 4, 5);
	print_adj_mat(g);			//������� ���
	printf("<Depth First Search-recursive>\n");
	init_visited();			//dfs ��� ������� ���� ���� ���
	dfs_recursive(g, 0);
	printf("\n<Depth First Search-stack>\n");
	dfs_stack(g, 0);		//dfs ���� ������� ���� ���� ���

	free(g);			//�޸� ����
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