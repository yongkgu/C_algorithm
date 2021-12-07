
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

typedef struct
{
	int n, m;
	int adj_mat[SIZE][SIZE];

}GraphType;

void queue_init(QueueType *q)
{
	q->front = q->rear = 0;
}

void graph_init(GraphType *g)
{
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
			g->adj_mat[r][c] = 0;

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

void init(GraphType *g)
{
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
			g->adj_mat[r][c] = 0;

}
void insert_edge(GraphType *g, int start, int end)
{
	if ((start >= g->n || (end >= g->n))) {
		printf("error\n");
		return;
	}

	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType *g)
{
	printf("\n");

	for (int r = 0; r < g->n; r++)
	{
		printf("|");
		for (int c = 0; c < g->n; c++)
			printf(" %d ", g->adj_mat[r][c]);
		printf("|\n");
	}
}
void bfs_mat(GraphType *g, int visited[], int v)
{
	int w;
	QueueType q;
	queue_init(&q);  
	visited[v] = TRUE;
	printf("정점 [%d] ", v + 1);
	enqueue(&q, v);
	
	while (!is_empty(&q))
	{
		v = dequeue(&q);
		for(w=0;w<g->n;w++)
			if (g->adj_mat[v][w] && !visited[w])
			{
				visited[w] = TRUE;
				printf(" 정 점[%d] ", w + 1);
				enqueue(&q, w);
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
	print_adj_mat(&g);

	int visited[SIZE] = { FALSE };
	printf("\n 너비 우선 탐색 \n");

	bfs_mat(&g, visited, v - 1);
	printf("\n");
}