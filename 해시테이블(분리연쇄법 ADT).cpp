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
	node *head = ht + hash_value; //ht의 할당받은 인덱스

	if (head->next == NULL)
	{
		head->next = newnode;
	}
	else
	{
		newnode->next = head->next; //새로운 노드의 다음은 이전 노드 (p가 헤드)
		head->next = newnode; //헤드의 다음은 뉴노드
		
	}

}

void search_table(int elem) {
	int c = 0;
	int hash_value = h(elem);
	node * head = ht + hash_value; //ht의 할당받은 인덱스

	
	while (head->next != NULL) {
		head = head->next;
		c++;
		if (head->elem == elem) { //찾는 원소이면
			printf("%d\n", c);
			return;
		}
	}
	

	printf("0\n");
}

void remove_table(int elem) {
	int c=0;
	int hash_value = h(elem);
	node * p = ht + hash_value; //ht의 할당받은 인덱스
	node *prenode = ht + hash_value;


	while (p->next != NULL) {
		p = p->next;
		c++;
		if (p->elem == elem) { //삭제할 원소이면
			while (prenode->next != p)//p의 이전노드로 이동
				prenode = prenode->next;

			prenode->next = p->next; //이전노드의 다음 노드는 삭제할 노드의 다음노드
			free(p); //메모리해제
			printf("%d\n", c); //순위 출력
				return; //삭제완료 리턴
			}
		}
	

	printf("0\n");
}

void print_table() {
	node* p = ht; //해시테이블 연결

	for (int i = 0; i < M; i++) {
		p = ht + i; //해시테이블 인덱스 이동
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