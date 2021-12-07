#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct AVL
{
	int key;
	struct AVL *left;
	struct AVL *right;       
}AVL;


AVL* rotate_right(AVL* parent) //왼쪽으로 편향되어 있는 경우
{
	AVL*child = parent->left;
	parent->left = child->right;  //자식의 오른쪽 자식이 부모의 왼쪽자식이 됨
	child->right = parent; //자식의 오른쪽 자식이 부모가 됨
	return child; //차일드가 루트가 된 상태로 리턴

}
AVL* rotate_left(AVL* parent) // 오른쪽으로 편향되어 있는 경우
{
	AVL*child = parent->right;
	parent->right = child->left;

	child->left = parent;
	return child;
}

//높이
int get_height(AVL* p) {
	int height = 0;

	if (p != NULL) {
		height = 1 + __max(get_height(p->left), get_height(p->right));
	}
	return height;
}

//노드의 균형 인수를 반환하는 함수
int get_balanced(AVL *node)
{
	if (node == NULL)
		return 0;
	return get_height(node->left) - get_height(node->right);
}
AVL *getnode(int key)
{
	AVL *node = (AVL*)malloc(sizeof(AVL));
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return node;
}
AVL *insert(AVL*node, int key)
{
	if (node == NULL)
		return getnode(key); 
	//트리 서치부분
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	int balance = get_balanced(node);

	if (balance > 1 && key < node->left->key) //왼쪽 서브트리에서 균형이 깨짐 ll 타입이니까 오른쪽 회전
		return rotate_right(node);
	if (balance < -1 && key > node->right->key) //오른쪽 서브트리에서 균형이 깨짐 rr 타입이니까 왼쪽 회전
		return rotate_left(node);

	if (balance > 1 && key > node->left->key) //lr 타입이니까 왼쪽회전, 오른쪽회전
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	if (balance < -1 && key < node->right->key) //rl 타입이니까 오른쪽회전, 왼쪽회전
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}
void preorder(AVL *root) {

	if (root)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
int main() {
	
	AVL *root = NULL;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int key = rand() % 100;
		root = insert(root, key);
	}

	preorder(root);

	return 0;
}