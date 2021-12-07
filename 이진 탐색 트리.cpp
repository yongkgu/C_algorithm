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
//노드 갯수
int getcount(node* p) {
	
	int count = 0;

	if (p != NULL) 
		count = 1 + getcount(p->left) + getcount(p->right); //순회하면서 값 증가 (선위)
	
	return count;
	
}

//단말노드 갯수 (무자식 노드)
//단말노드이면 1반환 아니면 순회

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
//avl 높이
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
//삭제연산 
/*
1. 노드가 단말 노드인 경우
	삭제 후 NULL로 연결 메모리 반환
2. 왼쪽이나 오른쪽 서브트리 하나만 가지고 있는 경우
	삭제 후 서브트리를 부모자리로 연결 메모리 반환
3. 두 개의 자식을 가지고 있는 경우
	첫 번째 방법
		삭제할 노드와 가장가까운 값을 대체해줘야한다. (오른쪽 자식이동 후 계속 왼쪽 자식으로 이동) or (외쪽 자식이동 후 계속 오른쪽 자식으로 이동)
		
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

	while (p->left != NULL) {  //가장 외쪽으로 이동
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
			node*temp = root->right; //오른쪽을 부모에 연결하기 위해
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}
		else  //중위계승자
		{
			node* temp = minValueNode(root->right); //오른쪽 서브트리에서 최솟값
			root->key = temp->key; //덮어씌우기
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
		printf("이진 탐색트리에서 18을 발견함\n");
		remove(root, 18);
	}
	preorder(root);
}

/*
 1. 단일 회전
	외부노드로부터 가장 가까운 찐빠난곳부터 회전
	
	(1) LL type 회전 (왼쪽으로 편향된 경우)
		부모가 오른쪽 자식이 되고 왼쪽자식이 부모가 된다.
	(2) RR type 회전 (오른쪽으로 편향된 경우)
	부모가 왼쪽 자식이디고 오른쪽 자식이 부모가 된다.
 2. 이중 회전
	
	(1) LR type 회전 (왼쪽자식 오른쪽 손자상태)
	찐빠난 곳 자식 노드가 부모노드로 출발
	부모가 왼쪽자식이 되고 오른쪽 자식이 부모가 된다
	이제 왼쪽으로 편향된 트리가 나왔으니 LL type 회전을 해주면 된다.

	(2) RL type 회전 (오른쪽 자식 왼쪽손자 상태)
	찐빠난 곳 자식 노드가 부모노드로 출발
	부모가 오른쪽 자식이되고 왼쪽 자식이 부모가 된다.
	이제 오른쪽으로 편향된 트리가 나왔으니 RR type 회전을 해주면 된다.

*/