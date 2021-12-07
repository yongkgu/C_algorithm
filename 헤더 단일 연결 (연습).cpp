#include<stdio.h>
#include<stdlib.h>

int r = 1;

typedef struct NODE {

	struct NODE* next;
	int elem;

}node;

node* getnode() {

	node* newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->elem = NULL;

	return newnode;
}

void insert(node* head, int elem, int index) {
	
	if (index > r)
	{
		printf("invalid rank\n");
		return;
	}
	node* p = getnode();
	node* pre = head;

	p->elem = elem;

	for (int i = 1; i < index; i++) {
		pre = pre->next;
	}

	p->next = pre->next;
	pre->next = p;

	r++;
}

void removed(node* head, int del_index) {


	if (del_index > r-1)
	{
		printf("invalid rank\n");
		return;
	}

	node* pre = head;
	node* del;

	for (int i = 1; i < del_index; i++) {
		pre = pre->next;
	}

	del = pre->next;

	pre->next = del->next;

	free(del);

	r--;
}

void get(node* head, int get_index) {

	if (get_index > r-1) {
		printf("invalid rank\n");
		return;
	}
	node* p = head;

	for (int i = 0; i < get_index; i++) {
		p = p->next;
	}

	printf("%d ", p->elem);
}
void print(node* head) {

	node* p = head->next;

	while (p != NULL) {
		printf("%d ", p->elem);
		p = p->next;
	}
}

int main() {

	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	head->elem = NULL;

	node* p = head;

	insert(head, 1, 1);
	insert(head, 2, 2);
	insert(head, 3, 3);
	insert(head, 4, 4);

	removed(head,6);

	print(head);

	get(head, 5);

	return 0;
}