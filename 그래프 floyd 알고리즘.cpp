#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define INF 100000 // ���Ѵ�

typedef struct
{
	int n;
	int weight[SIZE][SIZE];
}GraphType;

int A[SIZE][SIZE];

void print_weigh(GraphType *g)
{
	printf("================================================\n");
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			if (A[i][j] == INF)
				printf("  * ");
			else
				printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("================================================\n");

}

void floyd(GraphType *g)
{
	int i, j, k;
	for (i = 0; i < g->n; i++)  //�׷��� ����
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];

	print_weigh(g);  //���� �ʱ�ȭ�� �׷���

	for (k = 0; k < g->n; k++)    //0~g/n
	{
		for (i = 0; i < g->n; i++) {   //��� �� 
			for (j = 0; j < g->n; j++)  //i ���� 0~g.n�� ��
				if (A[i][k] + A[k][j] < A[i][j])  // (a,b) + (b,c) < (a,c)  // transtive�� �������� ������, �����ϴ��� �ٷΰ��°� ���İ��� �ͺ��� ���԰� ũ�ٸ� �������Է� ���� 
					A[i][j] = A[i][k] + A[k][j];  // (a,c) = (a,b),(b,c)   // transtive�� �����ϰ� ���ִ� ���� �߰�
		}
		print_weigh(g);
	}

}

void main()
{	//�����̸� 0 ���Ѵ��̸� inf
	GraphType g = { 6,
	{
		{ 0,50,45,10,INF,INF },
		{ INF,0,10,15,INF,INF },
		{ INF,INF,0,INF,30,INF },
		{ 20,INF,INF,0,15,INF },
		{ INF,20,35,INF,0,INF },
		{ INF,INF,INF,INF,3,0 }
	} };
	floyd(&g);

}
