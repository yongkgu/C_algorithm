/*
6 8 1
5 6
4 6
3 6
3 4
2 6
2 3
1 5
1 3
*/

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

typedef struct StackType {  //스택 구조체
	int stack[SIZE];
	int top;

}StackType;

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

void init_stack(StackType *s)  //스택 초기화
{
	s->top = -1;
}

int is_empty(StackType *s)  //스택이 비어있는지
{
	return (s->top == -1); //비어있음 1
}

//first_input
void push(StackType *s, int e) {
	if (s->top == SIZE - 1) {
		printf("Stack FULL\n");
		return;
	}
	s->top = s->top + 1;
	s->stack[s->top] = e;
}
//last_out
int pop(StackType *s) {
	if (s->top == -1) {
		printf("Stack Empty\n");
		return -1;
	}
	s->top = s->top - 1;

	return s->stack[s->top + 1];
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
		printf("\n\t정점 %d의 인접리스트 : ", i + 1);
		while (p != NULL)
		{
			printf(" %d", p->vertex + 1);
			p = p->next;
		}
		printf("\n");
	}
}

void dfs_list(GraphType *g, int visited[], int v)  //재귀와 스택을 이용한 깊이 우선 탐색
{
	GraphNode *w;
	StackType s;
	init_stack(&s);
	int flag = 0;

	visited[v] = TRUE;
	printf("정 점[%d] ", v + 1);

	push(&s, v);



	while (!is_empty(&s))
	{
		for (w = g->adj_list[v]; w != NULL; w = w->next)
		{
			if (!visited[w->vertex])
			{
				visited[w->vertex] = TRUE;
				printf("정 점[%d] ", w->vertex + 1);
				push(&s, w->vertex);
				v = w->vertex;
				flag = 1;
				break;
			}
		}

		if (flag == 0)
			v = pop(&s);
	
		flag = 0;
	}

}


void main()
{
	GraphType g;
	StackType s;

	init_stack(&s);
	init(&g);

	int n, m, v; //v는 깊이우선탐색을 위한 시작정점 기억함수
	int start, end; //두 정점

	scanf("%d %d %d", &g.n, &g.m, &v); //정점, 간선, 시작정점
	getchar();

	for (int i = 0; i < g.m; i++)
	{
		scanf("%d %d", &start, &end);
		getchar();
		insert_edge(&g, start - 1, end - 1);

	}
	print_adj_list(&g);

	int visited[SIZE] = { FALSE };
	printf("\n 깊이 우선 탐색 \n");
	dfs_list(&g, visited, v - 1);
	printf("\n");
}