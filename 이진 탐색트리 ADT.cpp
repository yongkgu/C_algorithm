#include<stdio.h>
#include<stdlib.h>

typedef struct node {

	int key;
	struct node* left;
	struct node* right;

}node;

int isExternal(node* p) {  //외부노드니
	if (p->left == NULL && p->right == NULL)
		return 1;
	else
		return 0;
}

int isInternal(node* p) {  //내부노드니
	if (p->left == NULL && p->right == NULL)
		return 0;
	else
		return 1;
}

node* treeSearch(node* p, int key){
	if (p == NULL)
		return NULL;
	if (p->key == key)
		return p;
	else if (p->key > key)
		return treeSearch(p->left, key);
	else
		return treeSearch(p->right, key);
}


node* insertitem(node* p, int key) {
	if (p == NULL)
	{
		node* newnode = (node*)malloc(sizeof(node));
		newnode->key = key;
		newnode->left = NULL;
		newnode->right = NULL;

		return newnode;
	}
	
	if (key < p->key) {
		p->left = insertitem(p->left, key);
	}
	
	else if (key > p->key)
	{
		p->right = insertitem(p->right, key);
	}

	return p;
}


node*  inorderSucc(node* root) {
	node* p = root;

	while (p->left != NULL) {  //가장 외쪽으로 이동
		p = p->left;
	}

	return p;
}


node* removed(node* p, int key)
{
	if (p == NULL)
		return p;
	if (key < p->key)
		p->left = removed(p->left, key);
	else if (key > p->key)
		p->right = removed(p->right, key);

	else //삭제할 노드인 경우
	{
		//case 1
		if (p->left == NULL)
		{
			node*temp = p->right; //오른쪽을 부모에 연결하기 위해
			free(p);
			return temp;
		}
		//case 2
		else if (p->right == NULL)
		{
			node* temp = p->left;
			free(p);
			return temp;
		}

		else  //양쪽 다 자식이 있는 경우 중위계승자
		{
			node* temp = inorderSucc(p->right); //오른쪽 서브트리에서 최솟값
			p->key = temp->key; //덮어씌우기
			p->right = removed(p->right, temp->key);
		}
	}

	return p;
}


void preorder(node *root) {

	if (root)
	{
		printf(" %d", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}


node* getnode() {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->key = NULL;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}


int main() {
	char op = NULL;
	int key;
	node* root = NULL;
	node* p = NULL;
	while (op != 'q') {
		scanf("%c", &op);
		getchar();

		switch (op) {
		case('i'):
			scanf("%d", &key);
			getchar();
			root = insertitem(root, key);
			//삽입
			break;
		case('d'):
			//삭제
			scanf("%d", &key);
			getchar();
			p = getnode();
			p = treeSearch(root, key);
			if (p == NULL) {
				printf("X\n");
			}
			else {
				printf("%d\n", p->key);
			}

			removed(root, key);


			break;
		
		case('s'):
			scanf("%d", &key);
			getchar();
			p = getnode();
			p = treeSearch(root, key);
			if (p == NULL) {
				printf("X\n");
			}
			else {
				printf("%d\n", p->key);
			}
			//탐색
			break;

		case('p'):
			//전위순회
			preorder(root);
			printf("\n");
			break;
		case('q'):
			//종료
			free(p);
		}
	}
	return 0;
}

