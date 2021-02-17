#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

void name();

typedef struct GraphNode {
	int vertex;
	int weight;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;	//vertex�� ����
	GraphNode* adj_list[MAX_VERTICES];			//vertex ���� ũ���� ������ �迭
}GraphType;

int found[MAX_VERTICES];		//���õ� vertex�� ����
int distance[MAX_VERTICES]; //spanning tree ���� vertex���� �� vertex ������ distance

void init(GraphType* g) {		//�׷��� �ʱ�ȭ
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
	//�߰��Ǵ� vertex ����
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = e;
	node->weight = w;
	node->link = g->adj_list[s];		//�ش� vertex ��������Ʈ�� �� �տ� insert
	g->adj_list[s] = node;		//inseret�� ��尡 ����Ʈ�� �� �� vertex�� ��
}

int choose(int distance[], int n, int found[]) {		//sp �������κ��� ���� ª�� distance�� ���� vertex ��ȯ
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];		//���� ���� �ȵ� �ּҰŸ� vertex ã��
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d: \n", step++);
	printf(" distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf("  *");		//���Ѵ븦 ���� ��� '*' �� ǥ��
		else
			printf("%3d", distance[i]);
	}
	printf("\n");
	printf(" found: ");
	for (int i = 0; i < g->n; i++) {
		printf("%3d", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;
	GraphNode* node;
	node = g->adj_list[start];
	//start vertex�κ����� weight�� distance�� ����
	for (int i = 0; i < g->n; i++)
		distance[i] = INF;
	while (node != NULL) {
		distance[node->vertex] = node->weight;		
		node = node->link;
	}	
	found[start] = TRUE;		//���� vertex �湮 ǥ��
	distance[start] = 0;
	printf("\n<Shortest Path from vertex %d>\n", start);
	for (i = 0; i < g->n - 1; i++) {		//start �����ϰ� ������ n-1�� vertex�� üũ
		print_status(g);
		u = choose(distance, g->n, found);		//���� vertex �� distance�� ���� ª�� vertex
		found[u] = TRUE;		//�ش� vertex u�� ���տ� �߰�
		node = g->adj_list[u];
		while (node != NULL) {		//���� �ȵ� ��� vertex�� distance �� update
			if (distance[u] + node->weight < distance[node->vertex])
				distance[node->vertex] = distance[u] + node->weight;
			node = node->link;
		}
	}
	print_status(g);
}

void print_graph(GraphType* g) {			//�׷��� ���� ���
	printf("<Graph ����>\n");
	for (int i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];
		printf("vertex %d  ", i);
		while (node != NULL) {
			printf("-> %d(%d)  ", node->vertex, node->weight);		//����� vertex, weight ���
			node = node->link;
		}
		printf("\n");
	}
}

int main() {
	name();
	int start;
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 7; i++)		//���� 7�� �߰�
		insert_vertex(g, i);
	insert_edge(g, 0, 1, 7);
	insert_edge(g, 0, 4, 3);
	insert_edge(g, 0, 5, 10);
	insert_edge(g, 1, 0, 7);
	insert_edge(g, 1, 2, 4);
	insert_edge(g, 1, 3, 10);
	insert_edge(g, 1, 4, 2);
	insert_edge(g, 1, 5, 6);
	insert_edge(g, 2, 1, 4);
	insert_edge(g, 2, 3, 2);
	insert_edge(g, 3, 1, 10);
	insert_edge(g, 3, 2, 2);
	insert_edge(g, 3, 4, 11);
	insert_edge(g, 3, 5, 9);
	insert_edge(g, 3, 6, 4);
	insert_edge(g, 4, 0, 3);
	insert_edge(g, 4, 1, 2);
	insert_edge(g, 4, 3, 11);
	insert_edge(g, 4, 6, 5);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 5, 1, 6);
	insert_edge(g, 5, 3, 9);
	insert_edge(g, 6, 3, 4);
	insert_edge(g, 6, 4, 5);    //edge 24�� �߰�

	print_graph(g);			//�׷��� ���� ���
	printf("\n���� vertex��ȣ: ");
	scanf("%d", &start);		//���� vertex �ޱ�
	shortest_path(g, start);

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