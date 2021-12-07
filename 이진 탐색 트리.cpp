#include<stdio.h>
#include<stdlib.h>
 
typedef struct TreeNode{

	int key;
	struct TreeNode *left, *right;
}node;

node* getnode(int key,node* left,node* right) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->left = left;
	newnode->right = right;
	newnode->key = key;

	return newnode;
}

node* search(node* p, int key) {
	if (p == NULL)
		return NULL;
	if (p->key == key)
		return p;
	else if (p->key > key)
		return search(p->left, key);
	else
		return search(p->right, key);
}
//��� ����
int getcount(node* p) {
	
	int count = 0;

	if (p != NULL) 
		count = 1 + getcount(p->left) + getcount(p->right); //��ȸ�ϸ鼭 �� ���� (����)
	
	return count;
	
}

//�ܸ���� ���� (���ڽ� ���)
//�ܸ�����̸� 1��ȯ �ƴϸ� ��ȸ

int get_leaf_count(node*p) {
	int count = 0;

	if (p != NULL) {
		if (p->left == NULL && p->right == NULL)
			return 1;
		else
			count = get_leaf_count(p->left) + get_leaf_count(p->right);
	}
	return count;
}
//avl ����
int get_height(node* p) {
	int height = 0;
	
	if (p != NULL) { 
		height = 1 + __max(get_height(p->left), get_height(p->right));
	}
	return height;
}

void inorder(node *root) {

	if (root)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}
void preorder(node *root) {

	if (root)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
//�������� 
/*
1. ��尡 �ܸ� ����� ���
	���� �� NULL�� ���� �޸� ��ȯ
2. �����̳� ������ ����Ʈ�� �ϳ��� ������ �ִ� ���
	���� �� ����Ʈ���� �θ��ڸ��� ���� �޸� ��ȯ
3. �� ���� �ڽ��� ������ �ִ� ���
	ù ��° ���
		������ ���� ���尡��� ���� ��ü������Ѵ�. (������ �ڽ��̵� �� ��� ���� �ڽ����� �̵�) or (���� �ڽ��̵� �� ��� ������ �ڽ����� �̵�)
		
*/
node* insertNode(node* p,int key)
{
	if (p == NULL)
	{
		node* newnode = (node*)malloc(sizeof(node));
		newnode->key = key;
		newnode->left = NULL;
		newnode->right = NULL;

		return newnode;
	}
	if (key < p->key) {
		p->left = insertNode(p->left, key);
	}
	else if (key > p->key)
	{
		p->right = insertNode(p->right, key);
	}

	return p;
}
node*  minValueNode(node* root) {
	node* p = root;

	while (p->left != NULL) {  //���� �������� �̵�
		p = p->left;
	}

	return p;
}
node* remove(node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key) 
		root->left = remove(root->left,key);
	else if (key > root->key)
		root->right = remove(root->right,key);
	else
	{
		//case 1
		if (root->left == NULL)
		{
			node*temp = root->right; //�������� �θ� �����ϱ� ����
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}
		else  //���������
		{
			node* temp = minValueNode(root->right); //������ ����Ʈ������ �ּڰ�
			root->key = temp->key; //������
			root->right = remove(root->right, temp->key);
		}
	}
	return root;
}
void main() {

	

	node* root = NULL;

	root = insertNode(root, 35);
	root = insertNode(root, 68);
	root = insertNode(root, 99);
	root = insertNode(root, 18);
	root = insertNode(root, 7);
	root = insertNode(root, 3);
	root = insertNode(root, 12);
	root = insertNode(root, 26);
	root = insertNode(root, 22);
	root = insertNode(root, 30);

	preorder(root);
	printf("\n\n");

	if (search(root, 18) != NULL)
	{
		printf("���� Ž��Ʈ������ 18�� �߰���\n");
		remove(root, 18);
	}
	preorder(root);
}

/*
 1. ���� ȸ��
	�ܺγ��κ��� ���� ����� ����������� ȸ��
	
	(1) LL type ȸ�� (�������� ����� ���)
		�θ� ������ �ڽ��� �ǰ� �����ڽ��� �θ� �ȴ�.
	(2) RR type ȸ�� (���������� ����� ���)
	�θ� ���� �ڽ��̵�� ������ �ڽ��� �θ� �ȴ�.
 2. ���� ȸ��
	
	(1) LR type ȸ�� (�����ڽ� ������ ���ڻ���)
	����� �� �ڽ� ��尡 �θ���� ���
	�θ� �����ڽ��� �ǰ� ������ �ڽ��� �θ� �ȴ�
	���� �������� ����� Ʈ���� �������� LL type ȸ���� ���ָ� �ȴ�.

	(2) RL type ȸ�� (������ �ڽ� ���ʼ��� ����)
	����� �� �ڽ� ��尡 �θ���� ���
	�θ� ������ �ڽ��̵ǰ� ���� �ڽ��� �θ� �ȴ�.
	���� ���������� ����� Ʈ���� �������� RR type ȸ���� ���ָ� �ȴ�.

*/