#include<stdio.h>
#include<stdlib.h>
//원형 연결리스트
// 헤드는 마지막 노드를 가르키고
// 마지막 노드는 첫 번째 노드를 가르킨다
typedef struct NODE {
	struct NODE* next;
	int elem;
}node;

node* insert_first(node* head, int elem) {

	node* p = (node*)malloc(sizeof(node));

	p->elem = elem;

	if (head == NULL)
	{
		head = p;  // ?
		p->next = head;

	}

	else
	{
		p->next = head->next;
		head->next = p;

	}

	return head;
}

node* insert_last(node* head,int elem) {

	node* p = (node*)malloc(sizeof(node));

	p->elem = elem;

	if (head == NULL)
	{
		head = p;
		p->next = head;
	}
	else
	{
		p->next = head->next;  //head->next가 첫 번째 노드
		head->next = p;
		head = p;
	}

	return head;
}

void print(node* head) {
	
	node* p;

	if (head == NULL) return;

	
	p = head->next;

	do {
		printf("%d->", p->elem);
		p = p->next;
	} while (p != head);
	printf("%d\n", p->elem);  //마지막 노드 출력

}

int main() {

	node* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print(head);

	return 0;
}