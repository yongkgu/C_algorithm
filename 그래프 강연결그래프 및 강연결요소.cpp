/*
방향 그래프 (direct graph)  dg
	구현 방법 : 무방향에서 node2부분 제거해주면 됨
	
	방향 DFS 
		트리 간선 : 그래프의 EDGE
		후향 간선 :  지손에서 조상으로가는 간선 (단 그래프에는 포함되지 않은)
		전향 간선 : 조상에서 자손으로가는 간선 (단 그래프에는 포함되지 않은)
		교차 간선 : 트리간선,후향간선,전향간선이 아닌 간선 (단 그래프에는 포함되지 않은)

	도달 가능성
		정점 u에서 v로의 방향경로가 존재한다면 u는 v에 도달한다 또는 도달 가능하다라고 말한다.
	
	강연결성
		어느 정점에서든지 u에서 v가 도달가능하고 v에서 u로도 도달 가능한 그래프이면 강연결하다라고 한다.

		강연결 그래프 알고리즘 
		1. g의 임의의 정점 v를 선택
		2. g의 v로부터 깊이우선탐색 수행
			만약 방문되지 않은 정점 w가 있다면, false를 반환 (visited배열에 하나라도 f라면)
		3. g의 간선들을 모두 역행시킨 g'을 얻음
		4. g'의 v로부터 깊이 우선탐색 수행
			만약 방문되지 않은 정점 w가 있다면, false를 반환 (visited배열에 하나라도 f라면)
			그렇지 않으면, true를 반환 (강연결 그래프이다.)
		

		7 12
		1 3
		1 4
		1 6
		2 6
		3 7
		4 5
		4 7
		5 2
		6 4
		6 5
		7 1
		7 2

		강연결요소
			강연결을 갖는 부그래프들 (강연결그래프가 아니더라도)
			
			강연결을 가진 부그래프 찾는 알고리즘
			1. 그래프 g에 대해서 각 정점 v의 완료시간 f[v]를 계산 (완료시간 : 재귀에서 빠져나올때(마지막 경로부터) 순서 [뒤에서부터] f(0))
			2. 모든 정점을 대상으로 깊이우선 탐색 (한번에 모든 정점 방문이 안됐을때, 임의의 정점으로부터 다시 깊이우선 탐색)
			3. reverse그래프 g'을 만들고 1번을 수행 (f[v]가 가장큰 정점을 찾음)
			4. 그래프(또는 트리)가 분리된다 (갈 곳이 없으면)(강연결 그래프가 아니라면) ----> 분리된 요소들이 강연결 요소이다
		
		이행적 폐쇄
			: a->b이고 b->c이면 a->c이다.--> 전향간선 // 최단거리 찾기(가중치의 합의 최솟값)
			
			계산방법 : Floyd-Warshall의 알고리즘 (동적프로그래밍이용)

			그래프에 존재하는 모든 정점 사이의 최단경로
			2차원 배열을 이용을 (3중 반복)
			(I==J) WEIGH[I][J] = 0  -> 루프일 경우 
			(I,J) != E = 00 무한대  -> 간선이 존재하지 않으면
			(I,J) = E = 가중치 값   -> 간선이 존재하면

			for k = 0 to n-1
				for i = 0 to n-1
					for j = 0 to n-1
						a[i][j] = min(A[i][j],A[i][k]+A[k][j])  // 가중치행렬값 = (기존의값,더한값) 중 더 작은 값
			
		*/




		/*
		깊이우선탐색 DFS (Depth-first search)

		O(N+M) 선위순회와 비슷함
		DFS로 가능한 기능
		모든 VERTEX와 EDGE방문
		연결그래프인지 결정 (끊어져있으면 탐색할 수 없으니)
		연결요소들을 계산
		신장숲을 계산

		구현할 그래프 모양
		vertex  edge
		1 : 3 5
		2 : 3 6
		3 : 1 2 4 6
		4 : 3 6
		5 : 1 6
		6 : 2 3 4 5

		인접행렬 경우
		1-> 3-> 2-> 6-> 4-> 5 순서로 방문 됨
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
	//g->adj_mat[end][start] = 1; 방향그래프니까 주석처리
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
	printf("정점 [%d] ", v + 1);
	for (int w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w])  // 1 && 0
			dfs_mat(g, visited, w);
}

void reverse_mat(GraphType *g, int v) //그래프, 시작정점 
{
	GraphType r;
	init(&r);
	r.n = g->n;
	int visited[SIZE] = { FALSE };

	for (int row = 0; row < SIZE; row++)
		for (int col = 0; col < SIZE; col++)
			r.adj_mat[col][row] = g->adj_mat[row][col];

	printf("\n");
	print_adj_mat(&r); //역행시킨 그래프 (트랜스포스 한 그래프)
	printf("\n");

	dfs_mat(&r, visited, v - 1); //깊이우선 탐색
	
}
void main()
{
	GraphType g;
	init(&g);
	int n, m, v; //v는 깊이우선탐색을 위한 시작정점 기억함수
	int start, end; //두 정점
	printf("정점과 간선의 갯수를 입력 : \n");
	scanf("%d %d", &g.n, &g.m); //정점, 간선
	getchar();

	for (int i = 0; i < g.m; i++)
	{
		scanf("%d %d", &start, &end);
		getchar();
		insert_edge(&g, start - 1, end - 1);

	}
	print_adj_mat(&g);

	int visited[SIZE] = { FALSE };
	printf("\n 깊이 우선 탐색을 위한 정점 입력 :  \n");
	scanf("%d", &v);

	printf("\n");
	
	dfs_mat(&g, visited, v - 1);
	printf("\n");
	reverse_mat(&g, v);

}