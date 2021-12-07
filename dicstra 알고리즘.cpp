/*
최단경로 (cost가 가장 적게 드는 경로)

dijkstra의 최단 경로 알고리즘
직접간것보다 거쳐서 가는게 더 작은 cost라면 거쳐서 가는것을 선택
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
	for (int i = 0; i < g->n; i++) //거리 출력
	{
		if (distance[i] == INF)   //무한대이면 별로 출력
			printf(" * ");
		else
			printf("%2d ", distance[i]);

	}

	printf("\n");

	printf("selected : ");  //선택된 정점
	for (int i = 0; i < g->n; i++)
		printf("%2d ", selected[i]);

	printf("\n\n");
}

int choose(int n)
{

	int i, min, minposition;
	min = INT_MAX; //가장 큰값
	minposition = -1;


	for (i = 0; i < n; i++) //모든 거리 검사
		if (distance[i] < min && !selected[i])  //선택되지 않았으면서 거리가 MIN보다 작으면
		{
			min = distance[i];  //MIN은 MIN보다거리
			minposition = i;    //인덱스 저장
		}

	return minposition; //인덱스 반환
}

void dicstra(GraphType *g, int s)
{

	int i, u, v;
	for (i = 0; i < g->n; i++)  //거리를 시작 행으로 초기화
		distance[i] = g->weight[s][i];

	selected[s] = TRUE; //시작행 방문 완료

	for (i = 0; i < g->n; i++)
	{
		print_status(g);   //출력
		u = choose(g->n);  //가장 작은 거리의 인덱스 받아오기

		selected[u] = TRUE; //체크하기
		for (v = 0; v < g->n; v++)
			if (!selected[v] && distance[u] + g->weight[u][v] < distance[v])  //선택하지 않았고, 거쳐가는것이 직접가는것보다 거리가 작으면 
				distance[v] = distance[u] + g->weight[u][v]; //거리 수정  (선택된 거리 + 선택된열 제외하고 선택된 행의 각 열값)
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
