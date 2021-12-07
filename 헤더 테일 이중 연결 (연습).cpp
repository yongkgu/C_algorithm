#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {

	struct NODE* next;
	struct NODE* prev;
	int elem;

}node;

void initd(node* head,node* tail) {

	head->next = tail;
	head->prev = NULL;
	head->elem = NULL;

	tail->next = NULL;
	tail->prev = head;
	tail->elem = NULL;

}

node* getnode() {

	node* newnode = (node*)malloc(sizeof(node));
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->elem = NULL;

	return newnode;
}

void insert(node* head,int r,int elem) {

	node* p = head;
	node* newnode = getnode();
	
	newnode->elem = elem;

	for (int i = 1; i < r; i++) {
		p = p->next;
	}

	newnode->next = p->next;
	p->next->prev = newnode;

	p->next = newnode;
	newnode->prev = p;
	  
}

void removed(node* head, int r) {

	node* del = head;

	for (int i = 0; i < r; i++) {
		del = del->next;
	}

	del->prev->next = del->next;
	del->next->prev = del->prev;

	free(del);
}

void print(node* head,node* tail) {

	node* p = head->next;

	while (p != tail) {
		printf("%d ", p->elem);
		p = p->next;
	}
}


int main() {

	node* head = (node*)malloc(sizeof(node));
	node* tail = (node*)malloc(sizeof(node));

	initd(head, tail);

	insert(head, 1, 1);
	insert(head, 2, 2);
	insert(head, 3, 3);

	removed(head, 1);

	print(head,tail);

	return 0;
}