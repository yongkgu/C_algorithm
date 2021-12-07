#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct AVL
{
	int key;
	struct AVL *left;
	struct AVL *right;       
}AVL;


AVL* rotate_right(AVL* parent) //�������� ����Ǿ� �ִ� ���
{
	AVL*child = parent->left;
	parent->left = child->right;  //�ڽ��� ������ �ڽ��� �θ��� �����ڽ��� ��
	child->right = parent; //�ڽ��� ������ �ڽ��� �θ� ��
	return child; //���ϵ尡 ��Ʈ�� �� ���·� ����

}
AVL* rotate_left(AVL* parent) // ���������� ����Ǿ� �ִ� ���
{
	AVL*child = parent->right;
	parent->right = child->left;

	child->left = parent;
	return child;
}

//����
int get_height(AVL* p) {
	int height = 0;

	if (p != NULL) {
		height = 1 + __max(get_height(p->left), get_height(p->right));
	}
	return height;
}

//����� ���� �μ��� ��ȯ�ϴ� �Լ�
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
	//Ʈ�� ��ġ�κ�
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	int balance = get_balanced(node);

	if (balance > 1 && key < node->left->key) //���� ����Ʈ������ ������ ���� ll Ÿ���̴ϱ� ������ ȸ��
		return rotate_right(node);
	if (balance < -1 && key > node->right->key) //������ ����Ʈ������ ������ ���� rr Ÿ���̴ϱ� ���� ȸ��
		return rotate_left(node);

	if (balance > 1 && key > node->left->key) //lr Ÿ���̴ϱ� ����ȸ��, ������ȸ��
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	if (balance < -1 && key < node->right->key) //rl Ÿ���̴ϱ� ������ȸ��, ����ȸ��
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