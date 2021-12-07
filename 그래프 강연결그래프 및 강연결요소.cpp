/*
���� �׷��� (direct graph)  dg
	���� ��� : �����⿡�� node2�κ� �������ָ� ��
	
	���� DFS 
		Ʈ�� ���� : �׷����� EDGE
		���� ���� :  ���տ��� �������ΰ��� ���� (�� �׷������� ���Ե��� ����)
		���� ���� : ���󿡼� �ڼ����ΰ��� ���� (�� �׷������� ���Ե��� ����)
		���� ���� : Ʈ������,���Ⱓ��,���Ⱓ���� �ƴ� ���� (�� �׷������� ���Ե��� ����)

	���� ���ɼ�
		���� u���� v���� �����ΰ� �����Ѵٸ� u�� v�� �����Ѵ� �Ǵ� ���� �����ϴٶ�� ���Ѵ�.
	
	�����Ἲ
		��� ������������ u���� v�� ���ް����ϰ� v���� u�ε� ���� ������ �׷����̸� �������ϴٶ�� �Ѵ�.

		������ �׷��� �˰��� 
		1. g�� ������ ���� v�� ����
		2. g�� v�κ��� ���̿켱Ž�� ����
			���� �湮���� ���� ���� w�� �ִٸ�, false�� ��ȯ (visited�迭�� �ϳ��� f���)
		3. g�� �������� ��� �����Ų g'�� ����
		4. g'�� v�κ��� ���� �켱Ž�� ����
			���� �湮���� ���� ���� w�� �ִٸ�, false�� ��ȯ (visited�迭�� �ϳ��� f���)
			�׷��� ������, true�� ��ȯ (������ �׷����̴�.)
		

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

		��������
			�������� ���� �α׷����� (������׷����� �ƴϴ���)
			
			�������� ���� �α׷��� ã�� �˰���
			1. �׷��� g�� ���ؼ� �� ���� v�� �Ϸ�ð� f[v]�� ��� (�Ϸ�ð� : ��Ϳ��� �������ö�(������ ��κ���) ���� [�ڿ�������] f(0))
			2. ��� ������ ������� ���̿켱 Ž�� (�ѹ��� ��� ���� �湮�� �ȵ�����, ������ �������κ��� �ٽ� ���̿켱 Ž��)
			3. reverse�׷��� g'�� ����� 1���� ���� (f[v]�� ����ū ������ ã��)
			4. �׷���(�Ǵ� Ʈ��)�� �и��ȴ� (�� ���� ������)(������ �׷����� �ƴ϶��) ----> �и��� ��ҵ��� ������ ����̴�
		
		������ ���
			: a->b�̰� b->c�̸� a->c�̴�.--> ���Ⱓ�� // �ִܰŸ� ã��(����ġ�� ���� �ּڰ�)
			
			����� : Floyd-Warshall�� �˰��� (�������α׷����̿�)

			�׷����� �����ϴ� ��� ���� ������ �ִܰ��
			2���� �迭�� �̿��� (3�� �ݺ�)
			(I==J) WEIGH[I][J] = 0  -> ������ ��� 
			(I,J) != E = 00 ���Ѵ�  -> ������ �������� ������
			(I,J) = E = ����ġ ��   -> ������ �����ϸ�

			for k = 0 to n-1
				for i = 0 to n-1
					for j = 0 to n-1
						a[i][j] = min(A[i][j],A[i][k]+A[k][j])  // ����ġ��İ� = (�����ǰ�,���Ѱ�) �� �� ���� ��
			
		*/




		/*
		���̿켱Ž�� DFS (Depth-first search)

		O(N+M) ������ȸ�� �����
		DFS�� ������ ���
		��� VERTEX�� EDGE�湮
		����׷������� ���� (������������ Ž���� �� ������)
		�����ҵ��� ���
		���彣�� ���

		������ �׷��� ���
		vertex  edge
		1 : 3 5
		2 : 3 6
		3 : 1 2 4 6
		4 : 3 6
		5 : 1 6
		6 : 2 3 4 5

		������� ���
		1-> 3-> 2-> 6-> 4-> 5 ������ �湮 ��
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
	//g->adj_mat[end][start] = 1; ����׷����ϱ� �ּ�ó��
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
	printf("���� [%d] ", v + 1);
	for (int w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w])  // 1 && 0
			dfs_mat(g, visited, w);
}

void reverse_mat(GraphType *g, int v) //�׷���, �������� 
{
	GraphType r;
	init(&r);
	r.n = g->n;
	int visited[SIZE] = { FALSE };

	for (int row = 0; row < SIZE; row++)
		for (int col = 0; col < SIZE; col++)
			r.adj_mat[col][row] = g->adj_mat[row][col];

	printf("\n");
	print_adj_mat(&r); //�����Ų �׷��� (Ʈ�������� �� �׷���)
	printf("\n");

	dfs_mat(&r, visited, v - 1); //���̿켱 Ž��
	
}
void main()
{
	GraphType g;
	init(&g);
	int n, m, v; //v�� ���̿켱Ž���� ���� �������� ����Լ�
	int start, end; //�� ����
	printf("������ ������ ������ �Է� : \n");
	scanf("%d %d", &g.n, &g.m); //����, ����
	getchar();

	for (int i = 0; i < g.m; i++)
	{
		scanf("%d %d", &start, &end);
		getchar();
		insert_edge(&g, start - 1, end - 1);

	}
	print_adj_mat(&g);

	int visited[SIZE] = { FALSE };
	printf("\n ���� �켱 Ž���� ���� ���� �Է� :  \n");
	scanf("%d", &v);

	printf("\n");
	
	dfs_mat(&g, visited, v - 1);
	printf("\n");
	reverse_mat(&g, v);

}