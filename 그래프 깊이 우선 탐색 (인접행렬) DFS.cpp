
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

typedef struct
{
	int n, m;
	int adj_mat[SIZE][SIZE];

}GraphType;




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
void dfs_mat(GraphType *g, int visited[], int v)
{
	visited[v] = TRUE;
	printf("���� [%d] ", v + 1);
	for (int w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w])  // 1 && 0
			dfs_mat(g, visited, w);
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
	print_adj_mat(&g);

	int visited[SIZE] = { FALSE };
	printf("\n ���� �켱 Ž�� \n");

	dfs_mat(&g, visited, v - 1);
	printf("\n");
}