// 신장 트리 (spanning tree)
// 최소 신장 트리 (minimum spanning tree)
	/*
		탐욕법 (greedy method) 
			잔돈 거스르기, 부분적 배낭, 최소 신장 트리

			kruskal의 최소신장트리 알고리즘
	
				1. 가중치가 가장 작은 edge 선택
				2. 가중치가 같은 모서리가 있다면 모두 선택
				3. 단, 싸이클이 된다면 선택하지 않음
				4. 위를  반복 --> 정점의 갯수 -1개가 연결이 된다면 종료


				edge들을 오름차순으로 정렬한다
				EDGE = 간선의 갯수 0으로 초기화
				K =0
				while (edge < n-1)
				{
					k = k+1
					if(edgrk edge(k)가 싸이클을 포함하지 않으면
						edge집합에 포함시킨다.
						edge갯수 증가
				}
					union_find 알고리즘 (싸이클 검사에 사용)
						union(x,y) : 원소 x와y가 속해있는 집합을 입력받아 합집합을 만드는 연산
							root1 = FIND(a);
							root2 = FIND(b);
							if root1 != root2
							parent[root1] = root2;

						
						find(x) : 원소 x가 속해있는 집합을 반환하는 연산
							if (parent[curr] == -1)
								return curr;
							while(parent[curr] != -1)
								curr = parent[curr];
							return curr;


						// 다른 집합이면 사이클이 만들어지지 않으니까!

						1.정점배열을 모두 -1로 초기화
						2. 부모의 정보를 표시

				 
						가중치로 정렬 (v,u weight)
						5 0 10
						2 3 12
						6 1 15
						1 2 16
						6 3 18
						'
						'

						find 알고리즘을 실행하고 서로 다른 집합이면 union함수 실행



	*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define INF 10000

typedef struct {

	int u, v, weight;
}edge;

typedef struct {

	int n;
	edge edges[2 * SIZE]; //간선의 갯수를 저장하기 위한 배열
}GraphType;

void insert_edge(GraphType* g, int u, int v, int weight)
{
	g->edges[g->n].u = u;
	g->edges[g->n].v = v;
	g->edges[g->n].weight= weight;
	g->n++;
}

void init_graph(GraphType *g)
{
	g->n = 0;
	for (int i = 0; i < 2 * SIZE; i++)
	{
		g->edges[i].u = 0;
		g->edges[i].v = 0;
		g->edges[i].weight = INF;
	}
}

int compare(const void *a, const void *b)
{
	edge* x = (edge*)a;
	edge* y = (edge*)b;
	return (x->weight - y->weight);

}

int parent[SIZE];

void init_set(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
}


int set_find(int curr) //curr = 현재정점 번호
{
	if (parent[curr] == -1)  //아무와도 연결 안 되어있으면
		return curr;
	while (parent[curr] != -1)  //아무와도 연결 안될때 까지
		curr = parent[curr];
	return curr;
}


void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;

}


void kruskal(GraphType *g)
{
	int edge_accepted = 0; //현재까지 선택된 간선의 갯수
	int uset, vset;   //집합 번호
	edge e;

	//라이브러리에서 정렬함수 쓰자 그냥;;
	//edges 배열 오름차순 정렬
	qsort(g->edges, g->n, sizeof(edge),compare);


	init_set(g->n);
	int i = 0;

	while (edge_accepted < g->n - 1)
	{
		e = g->edges[i];
		uset = set_find(e.u);
		vset = set_find(e.v);
		
		if (uset != vset)
		{
			printf("간선 (%d, %d, %d)가 선택\n", e.u, e.v, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}

}

void main()
{
	GraphType g;
	init_graph(&g);

	insert_edge(&g, 0, 1, 29);
	insert_edge(&g, 1, 2, 16);
	insert_edge(&g, 2, 3, 12);
	insert_edge(&g, 3, 4, 22);
	insert_edge(&g, 4, 5, 27);
	insert_edge(&g, 5, 0, 10);
	insert_edge(&g, 6, 1, 15);
	insert_edge(&g, 6, 3, 18);
	insert_edge(&g, 6, 4, 25);

	for (int i = 0; i < g.n; i++)
	{
		printf("(%d %d %d)\n", g.edges[i].u, g.edges[i].v, g.edges[i].weight);
	}
	printf("\n");

	kruskal(&g);

}