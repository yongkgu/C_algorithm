#include<stdio.h>
#include<stdlib.h>

/*
	연결리스트로 무방향 그래프 구현
	정점의 수 n
	간선의 수 m

	n개의 연결리스트가 필요
	2m개의 노드가 필요
*/

#define MAX_VERTICES 50

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* next;

}GraphNode;

typedef struct
{
	int n;
	GraphNode* adj_list[MAX_VERTICES]; //포인터 배열
	
}GraphType;

void init(GraphType *g)
{
	g->n = 0; //정점의 수 초기화
	for (int v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL; //헤더 노드들을 전부 null로 초기화
}

void insert_vertex(GraphType* g, int v)
{
	if (g->n + 1 > MAX_VERTICES)
	{
		printf("invalid exception\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u,int v)
{
	if (u > g->n || v >= g->n) {
		printf("invalid exception\n");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->next = g->adj_list[u];
	g->adj_list[u] = node;
	//insert_first
}

void print_adj_list(GraphType *g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL)
		{
			printf("->%d", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}
void main()
{

	GraphType g;
	init(&g);
	for (int i = 0; i < 4; i++)
	{
		insert_vertex(&g, i);
	}
	insert_edge(&g, 0, 1);
	insert_edge(&g, 1, 0);
	//symatric
	insert_edge(&g, 0, 2);
	insert_edge(&g, 2, 0);

	insert_edge(&g, 0, 3);
	insert_edge(&g, 3, 0);

	insert_edge(&g, 1, 2);
	insert_edge(&g, 2, 1);

	insert_edge(&g, 2, 3);
	insert_edge(&g, 3, 2);

	print_adj_list(&g);
}