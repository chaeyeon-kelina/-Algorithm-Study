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
	int n;	//vertex의 개수
	GraphNode* adj_list[MAX_VERTICES];			//vertex 개수 크기의 포인터 배열
}GraphType;

int found[MAX_VERTICES];		//선택된 vertex의 집합
int distance[MAX_VERTICES]; //spanning tree 내의 vertex에서 각 vertex 까지의 distance

void init(GraphType* g) {		//그래프 초기화
	g->n = 0;		//노드 수 0
	for (int i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;		//모든 vertex NULL로 초기화
}

void insert_vertex(GraphType* g, int v) {		//정점 추가
	if (g->n + 1 > MAX_VERTICES) {
		fprintf(stderr, "그래프 : 정점의 개수 초과\n");
		return;
	}
	else g->n++;		//정점의 개수 증가
}

void insert_edge(GraphType* g, int s, int e, int w) {
	if (s >= g->n || e >= g->n) {
		fprintf(stderr, "그래프 : 정점 번호 오류\n");
		return;
	}
	//추가되는 vertex 생성
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = e;
	node->weight = w;
	node->link = g->adj_list[s];		//해당 vertex 인접리스트의 맨 앞에 insert
	g->adj_list[s] = node;		//inseret된 노드가 리스트의 맨 앞 vertex가 됨
}

int choose(int distance[], int n, int found[]) {		//sp 집합으로부터 가장 짧은 distance를 갖는 vertex 반환
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];		//아직 선택 안된 최소거리 vertex 찾기
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
			printf("  *");		//무한대를 갖는 경우 '*' 로 표시
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
	//start vertex로부터의 weight를 distance에 저장
	for (int i = 0; i < g->n; i++)
		distance[i] = INF;
	while (node != NULL) {
		distance[node->vertex] = node->weight;		
		node = node->link;
	}	
	found[start] = TRUE;		//시작 vertex 방문 표시
	distance[start] = 0;
	printf("\n<Shortest Path from vertex %d>\n", start);
	for (i = 0; i < g->n - 1; i++) {		//start 제외하고 나머지 n-1개 vertex만 체크
		print_status(g);
		u = choose(distance, g->n, found);		//남은 vertex 중 distance가 가장 짧은 vertex
		found[u] = TRUE;		//해당 vertex u를 집합에 추가
		node = g->adj_list[u];
		while (node != NULL) {		//선택 안된 모든 vertex의 distance 값 update
			if (distance[u] + node->weight < distance[node->vertex])
				distance[node->vertex] = distance[u] + node->weight;
			node = node->link;
		}
	}
	print_status(g);
}

void print_graph(GraphType* g) {			//그래프 형태 출력
	printf("<Graph 형태>\n");
	for (int i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];
		printf("vertex %d  ", i);
		while (node != NULL) {
			printf("-> %d(%d)  ", node->vertex, node->weight);		//연결된 vertex, weight 출력
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
	for (int i = 0; i < 7; i++)		//정점 7개 추가
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
	insert_edge(g, 6, 4, 5);    //edge 24개 추가

	print_graph(g);			//그래프 형태 출력
	printf("\n시작 vertex번호: ");
	scanf("%d", &start);		//시작 vertex 받기
	shortest_path(g, start);

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