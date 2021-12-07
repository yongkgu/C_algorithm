//분리 연쇄법

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//실습 :  KEY : 영단어 value : 한글의미 
// 해시테이블

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
		ht[i] = NULL;  //비어있는 문자열로 초기화
	}
}
//문자열 키를 정수로 바꾸고 사이즈에 맞게끔 압축시키는 해시 함수
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
			printf("탐색키 중복");
			return;
		}
	}

	p = (node*)malloc(sizeof(node));  //공간할당
	//삽입
	strcpy(p->key, key);
	strcpy(p->value, value);
	//insert_first 작업
	p->next = ht[hash_value]; //원래 앞에 있던 친구가 다음 
	ht[hash_value] = p; 

}


int search_node(node* ht[], char* key) //선형 조사
{
	node* p;
	int hash_value = hash_function(key);

	for (p = ht[hash_value]; p != NULL; p = p->next)
	{
		if (strcmp(p->key, key) == 0)
		{
			printf("[%8s] 탐색 성공 인덱스 [%2d]	%10s = %s\n",key,hash_value,p->key,p->value);
			return 1;
		}
	}
	printf("[%8s] 탐색 실패\n",key);

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
	node* hash_table[TABLE_SIZE]; //선언
								   //초기화
	init_table(hash_table);
	insert_node(hash_table, "do", "반 복");
	insert_node(hash_table, "for", "반 복");
	insert_node(hash_table, "if", "분 기");
	insert_node(hash_table, "case", "분 기");
	insert_node(hash_table, "else", "분 기");
	insert_node(hash_table, "return", "반 환");
	insert_node(hash_table, "function", "함 수");

	print_table(hash_table);
	printf("\n");

	search_node(hash_table, "return");
	search_node(hash_table, "function");
	search_node(hash_table, "class");


}
