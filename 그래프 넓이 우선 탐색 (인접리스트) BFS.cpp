
/*
깊이우선탐색 DFS (Depth-first search)

O(N+M) 선위순회와 비슷함
DFS로 가능한 기능
모든 VERTEX와 EDGE방문
연결그래프인지 결정 (끊어져있으면 탐색할 수 없으니)
연결요소들을 계산
신장숲을 계산

구현할 그래프 모양
vertex  edge
1 : 3 5
2 : 3 6
3 : 1 2 4 6
4 : 3 6
5 : 1 6
6 : 2 3 4 5

인접행렬 경우
1-> 3-> 2-> 6-> 4-> 5 순서로 방문 됨
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct //원형 큐
{
	int queue[SIZE];
	int front, rear;

}QueueType;

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

void queue_init(QueueType *q)
{
	q->front = q->rear = 0;
}

void graph_init(GraphType *g)
{
	for (int v = 0; v < SIZE; v++)
		g->adj_list[v] = NULL;

}

int is_empty(QueueType *q)
{
	return (q->front == q->rear); //비어있음 1
}
int is_full(QueueType *q)
{
	return ((q->rear + 1) % SIZE == q->front); //앞에 한칸 비워놔야하니까 +1
}

void enqueue(QueueType*q, int item)
{
	if (is_full(q))
		return;
	q->rear = (q->rear + 1) % SIZE; // 원형이니까 모듈
	q->queue[q->rear] = item;
}
int dequeue(QueueType *q)
{
	if (is_empty((q)))
		return -1;
	q->front = (q->front + 1) % SIZE;
	return q->queue[q->front];
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
void bfs_list(GraphType *g, int visited[], int v)
{
	GraphNode *w;
	QueueType q;
	queue_init(&q);

	visited[v] = TRUE;
	printf("정 점[%d] ", v + 1);

	enqueue(&q,v);

	while (!is_empty(&q))
	{
		v = dequeue(&q);
		for (w = g->adj_list[v]; w != NULL; w = w->next)
		{
			if (!visited[w->vertex])
			{
				visited[w->vertex] = TRUE;
				printf("->정 점[%d] ", w->vertex + 1);
				enqueue(&q, w->vertex);
			}
		}
	}


}

void main()
{
	GraphType g;
	graph_init(&g);
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
	printf("\n 너비 우선 탐색 \n");

	bfs_list(&g, visited, v - 1);
	printf("\n");
}