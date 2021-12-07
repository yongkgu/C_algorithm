
/*
���̿켱Ž�� DFS (Depth-first search)

O(N+M) ������ȸ�� �����
DFS�� ������ ���
��� VERTEX�� EDGE�湮
����׷������� ���� (������������ Ž���� �� ������)
�����ҵ��� ���
���彣�� ���

������ �׷��� ���
vertex  edge
1 : 3 5
2 : 3 6
3 : 1 2 4 6
4 : 3 6
5 : 1 6
6 : 2 3 4 5

������� ���
1-> 3-> 2-> 6-> 4-> 5 ������ �湮 ��
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct //���� ť
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
	return (q->front == q->rear); //������� 1
}

int is_full(QueueType *q)
{
	return ((q->rear + 1) % SIZE == q->front); //�տ� ��ĭ ��������ϴϱ� +1
}

void enqueue(QueueType*q, int item)
{
	if (is_full(q))
		return;
	q->rear = (q->rear + 1) % SIZE; // �����̴ϱ� ���
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
	printf("���� [%d] ", v + 1);
	enqueue(&q, v);
	
	while (!is_empty(&q))
	{
		v = dequeue(&q);
		for(w=0;w<g->n;w++)
			if (g->adj_mat[v][w] && !visited[w])
			{
				visited[w] = TRUE;
				printf(" �� ��[%d] ", w + 1);
				enqueue(&q, w);
			}
	}
}

void main()
{
	GraphType g;
	graph_init(&g);
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
	print_adj_mat(&g);

	int visited[SIZE] = { FALSE };
	printf("\n �ʺ� �켱 Ž�� \n");

	bfs_mat(&g, visited, v - 1);
	printf("\n");
}