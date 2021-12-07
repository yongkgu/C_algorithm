/*
	prim �˰���
		1.���۳�� ����
		2.���� ����� ��� ������ �߿� ����ġ�� ���� ���� ������ ����
		3. �̸� ����n�϶� n-1�� ������ ���� �ɶ����� �ݺ�

		sel�迭 F�� �ʱ�ȭ
		DIST �迭 INF�� �ʱ�ȭ

		DIST���� ���� ���� ���� ����ϸ鼭 SEL�� T�� ���� (�湮�ߴ����� ��� X)



*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define INF 10000
#define TRUE 1
#define FALSE 0

int selected[SIZE] = { FALSE };
int distance[SIZE];

typedef struct
{
	int n;
	int weight[SIZE][SIZE];

}GraphType;

int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
	{
		if (!selected[i])
		{
			v = i;	
			break;
		}
	}

	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) //�ѹ��� �湮���� �ʾҸ鼭, ���õ� v���� ������
			v = i;
	return v;
}

void prim(GraphType *g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++) //��� ���Ѵ�� �ʱ�ȭ
		distance[u] = INF;

	distance[s] = 0; //���ۺκ� 0���� �ʱ�ȭ

	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n); //��ΰ��� ������ ���� �޾ƿ���
		selected[u] = TRUE;

		if (distance[u] == INF)
			return;
		
		printf("����  %d �湮\n", u);
		
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF) //����ġ���� �ִٸ�
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}

}

void main()
{

	GraphType g = { 7,
	{{0,29,INF,INF,INF,10,INF},
	{29,0,16,INF,INF,INF,15},
	{INF,16,0,12,INF,INF,INF},
	{INF,INF,12,0,22,INF,18},
	{INF,INF,INF,22,0,27,25},
	{10,INF,INF,INF,27,0,INF},
	{INF,15,INF,18,25,INF,0}}
	};
	
	prim(&g, 0);
}
