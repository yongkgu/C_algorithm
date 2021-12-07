#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ǽ� :  KEY : ���ܾ� value : �ѱ��ǹ� 
// �ؽ����̺�

#define TABLE_SIZE 13

typedef struct {
	char key[20];
	char value[100];

}Record;

void init_table(Record ht[])
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		ht[i].key[0] = ht[i].value[0] = NULL;  //����ִ� ���ڿ��� �ʱ�ȭ
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

int hash_function_prime(char *key)  //h'(k) DIVISOR
{
	//h'(k) = c - [k mod c]
	return 11 - (transform(key) % 11);
}


void insert_record(Record ht[], char *key, char *value)
{
	int i, hash_value;
	//�ؽ��ּ� ���
	hash_value = i = hash_function(key); 
	//�ּҰ� ����ִ��� ���
	while (ht[i].key[0] != NULL)  //������� �ʴ� ����
	{
		//����� Ű�� �����Ϸ��� Ű�� ��������??
		if (strcmp(ht[i].key, key) == 0)  //���̺��� Ű���� �����Ϸ��� Ű���� ������
		{
			printf("[%s] Ž��Ű�� �ߺ��Ǿ����ϴ�.\n", key);
			return;
		}
		 //������� ������ Ű ���� �ߺ��� �ƴ϶�� i���� �������Ѽ� ���� ��Ŷ�� ����Ű���� �Ѵ�.
		
			i = (i + 1) % TABLE_SIZE; //�ε��� �Ҵ�
			if (i == hash_value) { //�ѹ��� ���Ƽ� ó�� i���� �Ǹ� (������ �ּҰ� �����ּҷ� �ǵ��� �Դٸ� �� ��Ŷ�� ����.)
				printf("���̺��� ����ã���ϴ�.\n");
				return;
			}
		
	}
	//��ĭ�� ã������ ����
	strcpy(ht[i].key, key);
	strcpy(ht[i].value, value);

}

void insert_record_qp(Record ht[], char *key, char *value) //2�� �����
{
	int i, hash_value,inc = 0;  //inc �� inc���� �κ�
	//�ؽ��ּ� ���
	hash_value = i = hash_function(key);
	//�ּҰ� ����ִ��� ���
	while (ht[i].key[0] != NULL)  //������� �ʴ� ����
	{
		//����� Ű�� �����Ϸ��� Ű�� ��������??
		if (strcmp(ht[i].key, key) == 0)  //���̺��� Ű���� �����Ϸ��� Ű���� ������
		{
			printf("[%s] Ž��Ű�� �ߺ��Ǿ����ϴ�.\n", key);
			return;
		}

		//a[(h(k) + inc *inc) % mod M]
		i = (hash_value + inc * inc) % TABLE_SIZE; //�ε��� �Ҵ�
		inc = inc + 1;

		if (i == hash_value) { //�ѹ��� ���Ƽ� ó�� i���� �Ǹ� (������ �ּҰ� �����ּҷ� �ǵ��� �Դٸ� �� ��Ŷ�� ����.)
			printf("���̺��� ����ã���ϴ�.\n");
			return;
		}

	}
	//��ĭ�� ã������ ����
	strcpy(ht[i].key, key);
	strcpy(ht[i].value, value);

}


void insert_record_double(Record ht[], char *key, char *value)  //�����ؽ�
{
	int i, hash_value;
	//�ؽ��ּ� ���
	hash_value = i = hash_function(key);
	int inc = hash_function_prime(key);
	int j = 2;
	//�ּҰ� ����ִ��� ���
	while (ht[i].key[0] != NULL)  //������� �ʴ� ����
	{
		//����� Ű�� �����Ϸ��� Ű�� ��������??
		if (strcmp(ht[i].key, key) == 0)  //���̺��� Ű���� �����Ϸ��� Ű���� ������
		{
			printf("[%s] Ž��Ű�� �ߺ��Ǿ����ϴ�.\n", key);
			return;
		}
		//������� ������ Ű ���� �ߺ��� �ƴ϶�� i���� �������Ѽ� ���� ��Ŷ�� ����Ű���� �Ѵ�.

		i = (hash_value + inc) % TABLE_SIZE; //�ε��� �Ҵ�
		inc = j*inc; //2�� �浹 ��
		j++;

		if (i == hash_value) { //�ѹ��� ���Ƽ� ó�� i���� �Ǹ� (������ �ּҰ� �����ּҷ� �ǵ��� �Դٸ� �� ��Ŷ�� ����.)
			printf("���̺��� ����ã���ϴ�.\n");
			return;
		}

	}
	//��ĭ�� ã������ ����
	strcpy(ht[i].key, key);
	strcpy(ht[i].value, value);

}
int search_record(Record ht[], char* key) //���� ����
{
	int i, hash_value;
	hash_value = i = hash_function(key); //���ϵǾ����� �ε��� ���� �޾ƿ´�.

	while(ht[i].key[0] != NULL) //������� ������
	{
		//Ž���Ϸ��� Ű�� ��������
		if (strcmp(ht[i].key, key) == 0) 
		{
			printf("[%8s] Ž�� ����. �ε��� [%2d] %10s = %s.\n", key,i,ht[i].key,ht[i].value);
			return hash_value + i; //ã�� �ε��� ���� (��ġ�� �̵����� ���� ������ + i)
		}

		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) //������ �ּҰ� �����ּҷ� �ǵ��� �Դٸ� �� ��Ŷ�� ����.
			break;
	}
	printf("[%8s] Ž�� ���� \n", key);
	return NULL;
}
void print_table(Record ht[])
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%2d] %10s %s\n", i, ht[i].key, ht[i].value);
	}
	printf("\n");
}
void main()
{
	Record hash_table[TABLE_SIZE]; //����
	//�ʱ�ȭ
	init_table(hash_table);
	insert_record(hash_table, "do", "�� ��");
	insert_record(hash_table, "for", "�� ��");
	insert_record(hash_table, "if", "�� ��");
	insert_record(hash_table, "case", "�� ��");
	insert_record(hash_table, "else", "�� ��");
	insert_record(hash_table, "return", "�� ȯ");
	insert_record(hash_table, "function", "�� ��");

	print_table(hash_table);

	search_record(hash_table, "return");
	search_record(hash_table, "function");
	search_record(hash_table, "class");


}
