//�и� �����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ǽ� :  KEY : ���ܾ� value : �ѱ��ǹ� 
// �ؽ����̺�

#define TABLE_SIZE 13

typedef struct node{
	char key[20];
	char value[100];
	struct node* next;

}node;

void init_table(node* ht[])
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		ht[i] = NULL;  //����ִ� ���ڿ��� �ʱ�ȭ
	}
}
//���ڿ� Ű�� ������ �ٲٰ� ����� �°Բ� �����Ű�� �ؽ� �Լ�
int transform(char* key) // -> INTERGER
{
	int number = 0;
	while (*key != NULL)
		number = number + *key++;
	return number;
}
int hash_function(char *key)  //DIVISOR
{
	return transform(key) % TABLE_SIZE;
}


void insert_node(node* ht[], char *key, char *value)
{
	node* p;
	int hash_value = hash_function(key);

	for (p = ht[hash_value]; p != NULL; p = p->next)
	{
		if (strcmp(p->key, key) == 0)
		{
			printf("Ž��Ű �ߺ�");
			return;
		}
	}

	p = (node*)malloc(sizeof(node));  //�����Ҵ�
	//����
	strcpy(p->key, key);
	strcpy(p->value, value);
	//insert_first �۾�
	p->next = ht[hash_value]; //���� �տ� �ִ� ģ���� ���� 
	ht[hash_value] = p; 

}


int search_node(node* ht[], char* key) //���� ����
{
	node* p;
	int hash_value = hash_function(key);

	for (p = ht[hash_value]; p != NULL; p = p->next)
	{
		if (strcmp(p->key, key) == 0)
		{
			printf("[%8s] Ž�� ���� �ε��� [%2d]	%10s = %s\n",key,hash_value,p->key,p->value);
			return 1;
		}
	}
	printf("[%8s] Ž�� ����\n",key);

}
void print_table(node* ht[])
{
	node *p;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%2d] ", i);
		for (p = ht[i]; p != NULL; p = p->next)
			printf("%8s", p->key);
		printf("\n");
	}
}
void main()
{
	node* hash_table[TABLE_SIZE]; //����
								   //�ʱ�ȭ
	init_table(hash_table);
	insert_node(hash_table, "do", "�� ��");
	insert_node(hash_table, "for", "�� ��");
	insert_node(hash_table, "if", "�� ��");
	insert_node(hash_table, "case", "�� ��");
	insert_node(hash_table, "else", "�� ��");
	insert_node(hash_table, "return", "�� ȯ");
	insert_node(hash_table, "function", "�� ��");

	print_table(hash_table);
	printf("\n");

	search_node(hash_table, "return");
	search_node(hash_table, "function");
	search_node(hash_table, "class");


}
