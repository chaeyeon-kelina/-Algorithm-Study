#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

int visited[MAX_VERTICES];		//방문 체크할 배열

typedef struct GraphType {
	int n;		//vertex의 수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

typedef struct StackType {		//스택 구조체
	int vertex[MAX_VERTICES];		//vertex를 담을 배열
	int top;
}StackType;

void name();

void init(GraphType* g) {		//그래프 초기화
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;		//모든 원소 0으로 초기화
	}
}

void init_stack(StackType* s) {		//스택 초기화
	s->top = -1;
}

void init_visited() {		//방문 체크하는 배열 초기화
	for (int i = 0; i < MAX_VERTICES; i++)
		visited[i] = 0;
}

void insert_vertex(GraphType* g, int v) {		//vertex insertion 연산
	if (g->n + 1 > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과\n");
		return;
	}
	else
		g->n++;		//vertex 개수 증가
}

void insert_edge(GraphType* g, int start, int end) {		//무방향 그래프의 edge insertion 연산

	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점의 번호 오류\n");
		return;
	}
	g->adj_mat[start][end] = 1;		//대칭 위치에 모두 1로 set
	g->adj_mat[end][start] = 1;
}

void insert_edge_digraph(GraphType* g, int start, int end) {	//방향 그래프의 edge insertion 연산
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점의 번호 오류\n");
		return;
	}
	g->adj_mat[start][end] = 1;
}

void print_adj_mat(GraphType* g) {			//인접 행렬 출력
	int r, c;
	printf("<Graph Matrix>\n");
	for (r = 0; r < g->n; r++) {
		for (c = 0; c < g->n; c++)
			printf("%2d", g->adj_mat[r][c]);
		printf("\n");
	}
}

void dfs_recursive(GraphType* g, int v) {		//재귀로 dfs 탐색
	int w;
	visited[v] = true;		//dfs 시작된 vertex는 방문한 것으로 표시
	printf("vertex%d  ", v);		//방문한 vertex 출력
	for (w = 0; w < g->n; w++) {			//해당 vertex의 row를 하나씩 검사해서
		if (g->adj_mat[v][w] && !visited[w])		//특정 vertex값이 1인데 아직 방문 안했으면 
			dfs_recursive(g, w);		//그 vertex로 이동해서 다시 dfs 실행
	}
}

bool is_full(StackType* s) {		//스택이 가득 찼는지 검사
	return (s->top == (MAX_VERTICES - 1));
}

bool is_empty(StackType* s) {		//스택이 비었는지 검사
	return (s->top == -1);
}

int pop(StackType* s) {		//stack에서 pop하는 함수
	if (is_empty(s)) {			//스택이 비었다면 에러 출력
		fprintf(stderr, "Stack empty\n");
		exit(1);
	}
	else
		return s->vertex[(s->top)--];
}

void push(StackType* s, int item) {		//stack에 push하는 함수
	if (is_full(s)) {			//스택이 가득 찼다면 에러 출력
		fprintf(stderr, "Overflow\n");
		return;
	}
	else
		s->vertex[++(s->top)] = item;		//스택에 값 집어넣기
}

void dfs_stack(GraphType* g, int v) {		//스택으로 dfs 탐색
	int w;
	StackType s;
	init_stack(&s);		//스택 초기화
	init_visited();		//방문 체크하는 배열 초기화
	push(&s, v);		//dfs 시작된 vertex는 방문한 것으로 표시
	while (!is_empty(&s)) {		//스택이 비지 않았다면
		v = pop(&s);
		if (!visited[v]) {		//v가 방문되지 않았다면
			printf("vertex%d  ", v);
			visited[v] = true;			//방문 체크
			for (w = 0; w < g->n; w++) {					//해당 vertex의 row를 하나씩 검사해서
				if (g->adj_mat[v][w] && !visited[w]) {		//특정 vertex값이 1인데 아직 방문 안했으면 
					push(&s, w);		//그 vertex로 이동해서 다시 dfs 실행
				}
			}
		}
	}
}

int main() {
	name();

	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));		//그래프 동적할당

	//무방향 그래프
	init(g);
	for (int i = 0; i < 5; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 4);
	insert_edge(g, 2, 4);
	print_adj_mat(g);			//인접행렬 출력
	printf("<Depth First Search-recursive>\n");
	dfs_recursive(g, 0);			//dfs 재귀 방식으로 돌린 과정 출력
	printf("\n<Depth First Search-stack>\n");
	dfs_stack(g, 0);			//dfs 스택 방식으로 돌린 과정 출력

	printf("\n\n");

	//방향 그래프
	init(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);
	insert_edge_digraph(g, 0, 2);
	insert_edge_digraph(g, 2, 1);
	insert_edge_digraph(g, 1, 5);
	insert_edge_digraph(g, 2, 3);
	insert_edge_digraph(g, 0, 4);
	insert_edge_digraph(g, 4, 5);
	print_adj_mat(g);			//인접행렬 출력
	printf("<Depth First Search-recursive>\n");
	init_visited();			//dfs 재귀 방식으로 돌린 과정 출력
	dfs_recursive(g, 0);
	printf("\n<Depth First Search-stack>\n");
	dfs_stack(g, 0);		//dfs 스택 방식으로 돌린 과정 출력

	free(g);			//메모리 해제
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