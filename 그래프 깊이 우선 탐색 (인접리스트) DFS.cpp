#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* next;
}GraphNode;


typedef struct
{
	int n, m;
	GraphNode *adj_list[SIZE];

}GraphType;

void init(GraphType *g)
{
	for (int v = 0; v < SIZE; v++)
		g->adj_list[v] = NULL;
}

void insert_edge(GraphType *g, int u, int v)
{	
	GraphNode *node1, *node2;

	if ((u >= g->n || (v >= g->n))) {
		printf("error\n");
		return;
	}

	node1 = (GraphNode*)malloc(sizeof(GraphNode));
	node1->vertex = v;
	node1->next = g->adj_list[u];
	g->adj_list[u] = node1;

	node2 = (GraphNode*)malloc(sizeof(GraphNode));
	node2->vertex = u;
	node2->next = g->adj_list[v];
	g->adj_list[v] = node2;

}

void print_adj_list(GraphType *g)
{
	printf("\n");

	for (int i = 0; i < g->n; i++)
	{
		GraphNode*p = g->adj_list[i];
		printf("\n\t���� %d�� ��������Ʈ : ",i+1);
		while (p != NULL)
		{
			printf(" %d", p->vertex + 1);
			p = p->next;
		}
		printf("\n");
	}
}

void dfs_list(GraphType *g, int visited[], int v)
{
	GraphNode *w;
	visited[v] = TRUE;
	printf("�� ��[%d] ", v + 1);
	for (w = g->adj_list[v]; w != NULL; w = w->next)
	{
		if (!visited[w->vertex])
			dfs_list(g, visited, w->vertex);
	}

}

void main()
{
	GraphType g;
	init(&g);
	int n, m, v; //v�� ���̿켱Ž���� ���� �������� ����Լ�
	int start, end; //�� ����

	scanf("%d %d %d", &g.n, &g.m, &v); //����, ����, ��������
	getchar();

	for (int i = 0; i < g.m; i++)
	{
		scanf("%d %d", &start, &end);
		getchar();
		insert_edge(&g, start - 1, end - 1);

	}
	print_adj_list(&g);

	int visited[SIZE] = { FALSE }; 
	printf("\n ���� �켱 Ž�� \n");
	dfs_list(&g, visited, v - 1);
	printf("\n");
}