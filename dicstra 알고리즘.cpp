/*
�ִܰ�� (cost�� ���� ���� ��� ���)

dijkstra�� �ִ� ��� �˰���
�������ͺ��� ���ļ� ���°� �� ���� cost��� ���ļ� ���°��� ����
*/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

void print_status(GraphType *g)
{

	printf("distance : ");
	for (int i = 0; i < g->n; i++) //�Ÿ� ���
	{
		if (distance[i] == INF)   //���Ѵ��̸� ���� ���
			printf(" * ");
		else
			printf("%2d ", distance[i]);

	}

	printf("\n");

	printf("selected : ");  //���õ� ����
	for (int i = 0; i < g->n; i++)
		printf("%2d ", selected[i]);

	printf("\n\n");
}

int choose(int n)
{

	int i, min, minposition;
	min = INT_MAX; //���� ū��
	minposition = -1;


	for (i = 0; i < n; i++) //��� �Ÿ� �˻�
		if (distance[i] < min && !selected[i])  //���õ��� �ʾ����鼭 �Ÿ��� MIN���� ������
		{
			min = distance[i];  //MIN�� MIN���ٰŸ�
			minposition = i;    //�ε��� ����
		}

	return minposition; //�ε��� ��ȯ
}

void dicstra(GraphType *g, int s)
{

	int i, u, v;
	for (i = 0; i < g->n; i++)  //�Ÿ��� ���� ������ �ʱ�ȭ
		distance[i] = g->weight[s][i];

	selected[s] = TRUE; //������ �湮 �Ϸ�

	for (i = 0; i < g->n; i++)
	{
		print_status(g);   //���
		u = choose(g->n);  //���� ���� �Ÿ��� �ε��� �޾ƿ���

		selected[u] = TRUE; //üũ�ϱ�
		for (v = 0; v < g->n; v++)
			if (!selected[v] && distance[u] + g->weight[u][v] < distance[v])  //�������� �ʾҰ�, ���İ��°��� �������°ͺ��� �Ÿ��� ������ 
				distance[v] = distance[u] + g->weight[u][v]; //�Ÿ� ����  (���õ� �Ÿ� + ���õȿ� �����ϰ� ���õ� ���� �� ����)
	}
}


void main()
{

	GraphType g = { 7,

	{ { 0,7,INF,INF,3,10,INF },
	{ 7,0,4,10,2,6,INF },
	{ INF,4,0,2,INF,INF,INF },
	{ INF,10,2,0,11,9,4 },
	{ 3,2,INF,11,0,INF,5 },
	{ 10,6,INF,9,INF,0,INF },
	{ INF,INF,INF,4,5,INF,0 } }
	};

	dicstra(&g, 0);
}
