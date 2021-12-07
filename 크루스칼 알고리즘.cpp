// ���� Ʈ�� (spanning tree)
// �ּ� ���� Ʈ�� (minimum spanning tree)
	/*
		Ž��� (greedy method) 
			�ܵ� �Ž�����, �κ��� �賶, �ּ� ���� Ʈ��

			kruskal�� �ּҽ���Ʈ�� �˰���
	
				1. ����ġ�� ���� ���� edge ����
				2. ����ġ�� ���� �𼭸��� �ִٸ� ��� ����
				3. ��, ����Ŭ�� �ȴٸ� �������� ����
				4. ����  �ݺ� --> ������ ���� -1���� ������ �ȴٸ� ����


				edge���� ������������ �����Ѵ�
				EDGE = ������ ���� 0���� �ʱ�ȭ
				K =0
				while (edge < n-1)
				{
					k = k+1
					if(edgrk edge(k)�� ����Ŭ�� �������� ������
						edge���տ� ���Խ�Ų��.
						edge���� ����
				}
					union_find �˰��� (����Ŭ �˻翡 ���)
						union(x,y) : ���� x��y�� �����ִ� ������ �Է¹޾� �������� ����� ����
							root1 = FIND(a);
							root2 = FIND(b);
							if root1 != root2
							parent[root1] = root2;

						
						find(x) : ���� x�� �����ִ� ������ ��ȯ�ϴ� ����
							if (parent[curr] == -1)
								return curr;
							while(parent[curr] != -1)
								curr = parent[curr];
							return curr;


						// �ٸ� �����̸� ����Ŭ�� ��������� �����ϱ�!

						1.�����迭�� ��� -1�� �ʱ�ȭ
						2. �θ��� ������ ǥ��

				 
						����ġ�� ���� (v,u weight)
						5 0 10
						2 3 12
						6 1 15
						1 2 16
						6 3 18
						'
						'

						find �˰����� �����ϰ� ���� �ٸ� �����̸� union�Լ� ����



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
	edge edges[2 * SIZE]; //������ ������ �����ϱ� ���� �迭
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


int set_find(int curr) //curr = �������� ��ȣ
{
	if (parent[curr] == -1)  //�ƹ��͵� ���� �� �Ǿ�������
		return curr;
	while (parent[curr] != -1)  //�ƹ��͵� ���� �ȵɶ� ����
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
	int edge_accepted = 0; //������� ���õ� ������ ����
	int uset, vset;   //���� ��ȣ
	edge e;

	//���̺귯������ �����Լ� ���� �׳�;;
	//edges �迭 �������� ����
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
			printf("���� (%d, %d, %d)�� ����\n", e.u, e.v, e.weight);
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