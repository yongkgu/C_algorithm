#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	int elem;

}node;

int M;

int h(int x) {
	return x % M;
}

node *ht;

node* getnode() {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->elem = NULL;
	newnode->next = NULL;

	return newnode;
}

void insert_table(int elem) {
	node* newnode = getnode();
	newnode->elem = elem;

	int hash_value = h(elem);
	node *head = ht + hash_value; //ht�� �Ҵ���� �ε���

	if (head->next == NULL)
	{
		head->next = newnode;
	}
	else
	{
		newnode->next = head->next; //���ο� ����� ������ ���� ��� (p�� ���)
		head->next = newnode; //����� ������ �����
		
	}

}

void search_table(int elem) {
	int c = 0;
	int hash_value = h(elem);
	node * head = ht + hash_value; //ht�� �Ҵ���� �ε���

	
	while (head->next != NULL) {
		head = head->next;
		c++;
		if (head->elem == elem) { //ã�� �����̸�
			printf("%d\n", c);
			return;
		}
	}
	

	printf("0\n");
}

void remove_table(int elem) {
	int c=0;
	int hash_value = h(elem);
	node * p = ht + hash_value; //ht�� �Ҵ���� �ε���
	node *prenode = ht + hash_value;


	while (p->next != NULL) {
		p = p->next;
		c++;
		if (p->elem == elem) { //������ �����̸�
			while (prenode->next != p)//p�� �������� �̵�
				prenode = prenode->next;

			prenode->next = p->next; //��������� ���� ���� ������ ����� �������
			free(p); //�޸�����
			printf("%d\n", c); //���� ���
				return; //�����Ϸ� ����
			}
		}
	

	printf("0\n");
}

void print_table() {
	node* p = ht; //�ؽ����̺� ����

	for (int i = 0; i < M; i++) {
		p = ht + i; //�ؽ����̺� �ε��� �̵�
			while (p->next != NULL) {
				p = p->next;
				printf(" %d", p->elem);
			}
	}
	printf("\n");
}

void freeTable() {

	struct node *p, *q;

	for (int i = 0; i < M; i++) {

		if ((ht + i)->next != NULL) {

			p = (ht + i)->next;

			q = p;

			while (q->next != NULL) {

				p = p->next;

				free(q);

				q = p;

			}

		}

	}

	free(ht);

}

int main() {
	scanf("%d", &M);
	getchar();

	ht = (node*)malloc(M*sizeof(node));

	for (int i = 0; i < M; i++) {
		(ht + i)->elem = NULL;
		(ht + i)->next = NULL;
	}

	char op;
	int elem;

	while (1) {
		scanf("%c", &op);
		getchar();

		if (op == 'i') {
			scanf("%d", &elem);
			getchar();

			insert_table(elem);
		}
		else if (op == 's') {
			scanf("%d", &elem);
			getchar();

			search_table(elem);
		}
		else if (op == 'd') {
			scanf("%d", &elem);
			getchar();

			remove_table(elem);
		}
		else if (op == 'p') {
			print_table();
		}
		else if (op == 'e') {
			freeTable();
			return 0;
		}
	}
	return 0;

}