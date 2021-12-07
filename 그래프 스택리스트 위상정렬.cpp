/*
���� ���α׷���
	��;˰����� ��κ� ���α׷��� ȿ���� ���� ���� ������
	��ȿ������ ���� �ִ�.

	��ǥ���� �� --> �Ǻ���ġ �� (�ߺ�ȣ���� �ʹ� ������)

	�̸� ���� ���α׷����� �̿��ؼ� �ذ��� �� �ִ�.

	��ͷ� �׶��׶� ȣ���Ұ� �ƴ϶�
	�ѹ� ���� �ֵ��� ��򰡿� ������ ���ٰ� �� ����� ���� �׳� ����ϸ� ���� ������???
	-> �������α׷���

	�������α׷��� ��� ex) �Ǻ���ġ
	1.f[1] = f[2] = 1;
	2.for i = 3 to n
		f[i] = f[i-1] + f[i-2] //�����ؼ� ����
	3.return f[n]  //n��°�� ���������� ��� ������! ->  ����

	Ư��: ������ġ�� ������ �ٸ��� �ܹ����� Ư���� ���� ���� ���� ȿ�����̴�!

	//�� ���� ���� , ����� ��� ����, ���� ����κ� ã�� ���� Ǯ��� ������


���� �����Ŭ �׷��� (DAG)
	�������Ŭ�� �������� �ʴ� ���� �׷���
		ex) ������ ���� ���� ���� (c->�ڷᱸ��->�˰���)
	
	DAG�� ���� ����
		���� ���� : �������� ��ȣ�� ������ ��
	
	���� �׷����� DAG��, ��������� ������ �� ���� ���̴�.

	���� ���� : DAG�κ��� ��������� ��� ����
	
	��� : 1. ������ ���������� �̿��ϴ� ���� ���� (ť �̿�)
		1. Q = EMPTY QUEUE
		2. for vertex
			in(u) = inDegree(u)  //�迭�� ������ �������� ������ �������� ����
			if(in(u) = 0) //���� ������ ���� ������ ��带
				Q.enqueue  //��ť
		3. i = 1
		4. while(!Q.isEmpty())
			u = Q.dequeue  //������� �ʴ� ���� ��ť
			//��ť�� ����ȣ�� �������
			i = i+1
			for each edge
				w = opposite(u,edge)
				in(w) = in(w)-1
				if(in(w) =0)
					Q.enqueue(w)
		5. if(i<=n)
			write( "G�� ���� ����Ŭ�̴�" )
		6. return

		ť�� �ϸ� �Էµ� ������ �����̵� ���̰�
		�������� �ϸ� �ڿ� ���� ������ �����̵ȴ�


*/


//�������� ������ ��������Ʈ ��������



#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
/*
	�Է� Ŀ���

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


typedef struct StackType {  //���� ����ü
	int stack[SIZE];
	int top;

}StackType;

typedef struct
{
	int n, m;  //��� , ������ ����
	GraphNode *adj_list[SIZE];

}GraphType;

void init_graph(GraphType *g)
{
	
	for (int v = 0; v < SIZE; v++)
		g->adj_list[v] = NULL;
}

void init_stack(StackType *s)  //���� �ʱ�ȭ
{
	s->top = -1;
}

int is_empty(StackType *s)  //������ ����ִ���
{
	return (s->top == -1); //������� 1
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
			in_degree[node->vertex]++;  //�������� ��� (�������� �� ���������� +1;
			node = node->next;
		}
	}

	init_stack(&s);
	for(i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) //���������� 0�̸� push
			push(&s, i); //0,�� 1�� ���ڳ׿� 
	}

	while (!is_empty(&s))// ������� �ʴ� ����
	{
		int w;
		w = pop(&s); // ù��° ���� 1 �ι�° 4 ����° 0 
		printf("[���� %d] ", w);  //1
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
	return (i == g->n); //1�̸� ���� 0�̸� ���� (���� ����Ŭ�� �����⶧���� ����)
}

void main()
{
	GraphType g;
	StackType s;

	init_stack(&s);
	init_graph(&g);

	int  v; //v�� ���̿켱Ž���� ���� �������� ����Լ�
	int start, end; //�� ����

	scanf("%d %d %d", &g.n, &g.m, &v); //����, ����, ��������
	getchar();

	for (int i = 0; i < g.m; i++)
	{
		scanf("%d %d", &start, &end);
		getchar();
		insert_edge(&g, start - 1, end - 1);

	}

	topo_sort(&g);

}