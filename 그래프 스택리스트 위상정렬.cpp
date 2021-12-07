/*
동적 프로그래밍
	재귀알고리즘은 대부분 프로그램의 효율을 높일 때가 많지만
	비효율적일 때도 있다.

	대표적인 예 --> 피보나치 수 (중복호출이 너무 많아짐)

	이를 동적 프로그래밍을 이용해서 해결할 수 있다.

	재귀로 그때그때 호출할게 아니라
	한번 계산된 애들은 어딘가에 저장해 놨다가 그 저장된 값을 그냥 사용하면 되지 않을까???
	-> 동적프로그래밍

	동적프로그래밍 기법 ex) 피보나치
	1.f[1] = f[2] = 1;
	2.for i = 3 to n
		f[i] = f[i-1] + f[i-2] //누적해서 저장
	3.return f[n]  //n번째가 최종적으로 모든 누적값! ->  리턴

	특성: 분할통치의 양방향과 다르게 단방향의 특성을 가짐 따라서 종종 효율적이다!

	//돌 놓기 문제 , 행렬의 경로 문제, 최장 공통부분 찾기 문제 풀어보면 좋겠지


방향 비싸이클 그래프 (DAG)
	방향싸이클이 존재하지 않는 방향 그래프
		ex) 교과목 간의 선수 관계 (c->자료구조->알고리즘)
	
	DAG와 위상 정렬
		위상 순서 : 정점들을 번호로 나열한 것
	
	방향 그래프가 DAG면, 위상순서를 가지며 그 역도 참이다.

	위상 정렬 : DAG로부터 위상순서를 얻는 절차
	
	방법 : 1. 정점의 진입차수를 이용하는 위상 정렬 (큐 이용)
		1. Q = EMPTY QUEUE
		2. for vertex
			in(u) = inDegree(u)  //배열에 각각의 정점들의 들어오는 진입차수 저장
			if(in(u) = 0) //위상 순서가 가장 먼저인 노드를
				Q.enqueue  //인큐
		3. i = 1
		4. while(!Q.isEmpty())
			u = Q.dequeue  //비어있지 않는 동안 디큐
			//디큐한 노드번호가 위상순서
			i = i+1
			for each edge
				w = opposite(u,edge)
				in(w) = in(w)-1
				if(in(w) =0)
					Q.enqueue(w)
		5. if(i<=n)
			write( "G는 방향 싸이클이다" )
		6. return

		큐로 하면 입력된 순서로 정렬이될 것이고
		스택으로 하면 뒤에 들어온 순서로 정렬이된다


*/


//스택으로 구현한 인접리스트 위상정렬



#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
/*
	입력 커멘드

	6 8 1
	1 3
	1 4
	2 4
	2 5
	3 4
	3 6
	4 6
	5 6
*/
typedef struct GraphNode
{
	int vertex;
	struct GraphNode* next;
}GraphNode;


typedef struct StackType {  //스택 구조체
	int stack[SIZE];
	int top;

}StackType;

typedef struct
{
	int n, m;  //노드 , 간선의 갯수
	GraphNode *adj_list[SIZE];

}GraphType;

void init_graph(GraphType *g)
{
	
	for (int v = 0; v < SIZE; v++)
		g->adj_list[v] = NULL;
}

void init_stack(StackType *s)  //스택 초기화
{
	s->top = -1;
}

int is_empty(StackType *s)  //스택이 비어있는지
{
	return (s->top == -1); //비어있음 1
}
int is_full(StackType *s)
{
	return (s->top == (SIZE - 1));
}

//first_input
void push(StackType *s, int e) {
	if (s->top == SIZE - 1) {
		printf("Stack FULL\n");
		return;
	}
	s->top = s->top + 1;
	s->stack[s->top] = e;
}
//last_out
int pop(StackType *s) {
	if (s->top == -1) {
		printf("Stack Empty\n");
		return -1;
	}
	s->top = s->top - 1;

	return s->stack[s->top + 1];
}

void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node1;

	if ((u >= g->n || (v >= g->n))) {
		printf("error\n");
		return;
	}

	node1 = (GraphNode*)malloc(sizeof(GraphNode));
	node1->vertex = v;
	node1->next = g->adj_list[u];
	g->adj_list[u] = node1;

}


int  topo_sort(GraphType *g)
{
	int i;
	StackType s;
	GraphNode *node;

	int * in_degree = (int*)malloc(sizeof(int));
	for (i = 0; i < g->n; i++)
		in_degree[i] = 0;
	for (i=0; i < g->n; i++)
	{
		GraphNode* node = g->adj_list[i];
		while (node != NULL)
		{
			in_degree[node->vertex]++;  //진입차수 기록 (진입차수 가 있을때마다 +1;
			node = node->next;
		}
	}

	init_stack(&s);
	for(i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) //진입차수가 0이면 push
			push(&s, i); //0,과 1이 들어가겠네요 
	}

	while (!is_empty(&s))// 비어있지 않는 동안
	{
		int w;
		w = pop(&s); // 첫번째 예시 1 두번째 4 세번째 0 
		printf("[정점 %d] ", w);  //1
 		node = g->adj_list[w]; //3 //5
		while (node != NULL)
		{
			int u = node->vertex; //3 //5
			in_degree[u]--; //2 //2
			if (in_degree[u] == 0)
				push(&s, u); // //4
			node = node->next; //4
		}
	}
	printf("\n");
	return (i == g->n); //1이면 성공 0이면 실패 (방향 싸이클을 가지기때문에 실패)
}

void main()
{
	GraphType g;
	StackType s;

	init_stack(&s);
	init_graph(&g);

	int  v; //v는 깊이우선탐색을 위한 시작정점 기억함수
	int start, end; //두 정점

	scanf("%d %d %d", &g.n, &g.m, &v); //정점, 간선, 시작정점
	getchar();

	for (int i = 0; i < g.m; i++)
	{
		scanf("%d %d", &start, &end);
		getchar();
		insert_edge(&g, start - 1, end - 1);

	}

	topo_sort(&g);

}