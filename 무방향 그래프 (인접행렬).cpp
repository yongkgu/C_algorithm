#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50
/*
	0-1-2
	0-2-3
	0-3

	������ �׷���
	
*/
//������� ������ �������� ������ �����ϸ� 1 ������ 0
// ������ ���ٰ� ����

typedef struct 
{
	int n; //������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; //�������

}GraphType;

void init(GraphType* g)
{
	int row, col;
	g->n = 0;
	for (row = 0; row < MAX_VERTICES; row++)
		for (col = 0; col < MAX_VERTICES; col++)
			g->adj_mat[row][col] = 0;
}

void insert_vertex(GraphType *g)
{
	if ((g->n + 1) > MAX_VERTICES)
	{
		printf("invalid exception\n");
		return;
	}
	g->n++;


}

void insert_edge(GraphType *g, int start, int end)
{
	//������ �׷����̸� ������Ŀ��� 0��1���̿� ������ ������ 1��0���̿��� ������ �־���Ѵ�.
	// symetric matrix�� ������ش�

	if ((start >= g->n) || (end >= g->n))
	{
		printf("invalid exception\n");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1; //symetric

}

void print_adj_mat(GraphType *g)
{
	for (int row = 0; row < g->n; row++) {
		for (int col = 0; col < g->n; col++) {
			printf(" %d ", g->adj_mat[row][col]);
		}
		printf("\n");
	}
}
void main() {

	GraphType g;
	init(&g);

	for (int i = 0; i < 4; i++) {
		insert_vertex(&g);
	}

	insert_edge(&g, 0, 1);
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 2, 3);


	print_adj_mat(&g);
}