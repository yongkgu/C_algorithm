/*
	prim 알고리즘
		1.시작노드 선택
		2.노드와 연결된 모든 간선들 중에 가중치가 가장 낮은 간선을 선택
		3. 이를 정점n일때 n-1의 간선이 연결 될때까지 반복

		sel배열 F로 초기화
		DIST 배열 INF로 초기화

		DIST값이 가장 작은 값을 출력하면서 SEL을 T로 변경 (방문했던곳은 출력 X)



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
		if (!selected[i] && (distance[i] < distance[v])) //한번도 방문하지 않았면서, 선택된 v보다 작으면
			v = i;
	return v;
}

void prim(GraphType *g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++) //모두 무한대로 초기화
		distance[u] = INF;

	distance[s] = 0; //시작부분 0으로 초기화

	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n); //경로값이 최저인 정점 받아오기
		selected[u] = TRUE;

		if (distance[u] == INF)
			return;
		
		printf("정점  %d 방문\n", u);
		
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF) //가중치값이 있다면
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
