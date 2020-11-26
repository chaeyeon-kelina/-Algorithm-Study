#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

void name();

typedef struct GraphNode {
	int vertex;
	int edge;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;	//vertex�� ����
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

int found[MAX_VERTICES];		//���õ� vertex�� ����
int distance[MAX_VERTICES]; //spanning tree ���� vertex���� �� vertex ������ distance

void init_graph(GraphType* g) {		//�׷��� �ʱ�ȭ
	g->n = 0;		//��� �� 0
	for (int i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;		//��� vertex NULL�� �ʱ�ȭ
}

void insert_vertex(GraphType* g, int v) {		//���� �߰�
	if (g->n + 1 > MAX_VERTICES) {
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�\n");
		return;
	}
	else g->n++;		//������ ���� ����
}

void insert_edge(GraphType* g, int s, int e, int w) {
	if (s >= g->n || e >= g->n) {
		fprintf(stderr, "�׷��� : ���� ��ȣ ����\n");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = e;
	node->edge = w;
	g->adj_list[s] = node;
}

int choose(int distance[], int n, int found[]) {		//sp �������κ��� ���� ª�� distance�� ���� vertex ��ȯ
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
		}
	}
	return minpos;
}

void pirnt_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d: \n", step++);
	printf(" distance: ");
	for (int i = 0; i < g->n; i++) {
		if()
	}
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;
	for (i = 0; i < g->n; i++) {
		distance[g->adj_list[start]->vertex] = g->adj_list[start]->edge;
	}
}





int main() {
	name();
	GraphType g;
	init_graph;

	for(int i=0; i<7; i++)		//���� 7�� �߰�
		insert_vertex(&g, i);

	insert_edge(&g, 0, 4, 3);
	insert_edge(&g, 0, 1, 7);
	insert_edge(&g, 0, 5, 10);
	insert_edge(&g, 4, 1, 2);
	insert_edge(&g, 4, 3, 11);
	insert_edge(&g, 4, 6, 5);
	insert_edge(&g, 1, 3, 10);
	insert_edge(&g, 1, 2, 4);
	insert_edge(&g, 1, 5, 6);
	insert_edge(&g, 2, 3, 2);
	insert_edge(&g, 5, 3, 9);
	insert_edge(&g, 6, 3, 4);		//edge 12�� �߰�




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