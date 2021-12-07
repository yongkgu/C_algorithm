#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define INF 100000 // 무한대

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
	for (i = 0; i < g->n; i++)  //그래프 복사
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];

	print_weigh(g);  //기존 초기화된 그래프

	for (k = 0; k < g->n; k++)    //0~g/n
	{
		for (i = 0; i < g->n; i++) {   //모든 행 
			for (j = 0; j < g->n; j++)  //i 행의 0~g.n의 열
				if (A[i][k] + A[k][j] < A[i][j])  // (a,b) + (b,c) < (a,c)  // transtive가 존재하지 않으면, 존재하더라도 바로가는게 거쳐가는 것보다 무게가 크다면 작은무게로 변경 
					A[i][j] = A[i][k] + A[k][j];  // (a,c) = (a,b),(b,c)   // transtive를 만족하게 해주는 원소 추가
		}
		print_weigh(g);
	}

}

void main()
{	//루프이면 0 무한대이면 inf
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
