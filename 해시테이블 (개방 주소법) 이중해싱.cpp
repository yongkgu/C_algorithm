#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int elem;
	//6�ڸ� �Ǵ� 8�ڸ� �й�
}hash_table;

int M,q;

int h(int x) {
	return x % M;
}
int h2(int x) {
	return (q - (x%q));
}
void insert_table(hash_table ht[],int elem) {
	int index,initvalue;

	initvalue = index = h(elem);
	int initelem = elem;
	int value = h2(elem),i=1;

	while (1) {
		

		if ((ht + index)->elem == NULL) {
			(ht + index)->elem = initelem;
			printf("%d\n", index); //�ּ�
			return;
		}
		else //������� ������
		{
			value = h2(elem);
			index = (initvalue + (i*value)) % M;
			i = i + 1;
			printf("C"); 

			if (index == initvalue) //�ѹ������� ���ڸ��̸� 
				break;
		}
	}
	printf("invalid exception\n"); //������� ����
}

void search_table(hash_table ht[], int elem) {
	int index, initvalue;

	initvalue = index = h(elem);
	int initelem = elem;
	int value,i=1;
	while (1) {
		

		if ((ht + index)->elem == initelem) {
			printf("%d %d\n", index,initelem); //�ּ�, �� ����
			return;
		}
		else //���� ������
		{
			value = h2(elem);
			index = (initvalue + (i*value)) % M;
			i = i + 1;
		
			if (index == initvalue) //�ѹ������� ���ڸ��̸� 
				break;
		}
	}
	printf("-1\n"); //Ž�� ��� ����
}

void print_table(hash_table ht[])
{
	for (int i = 0; i < M; i++) {
		printf(" %d", ht[i].elem);
	}
	printf("\n");
}
int main(){

	int n,elem;
	char op;
	scanf("%d %d %d", &M, &n,&q);
	getchar();

	//���� �� �ʱ�ȭ
	hash_table *ht;
	ht = (hash_table*)malloc(M * sizeof(hash_table));

	for (int i = 0; i < M; i++) 
	{
		(ht + i)->elem = NULL;
	}

	while (1)
	{
		scanf("%c", &op);
		getchar();
		
		if (op == 'i') {
			scanf("%d", &elem);
			getchar();
			insert_table(ht,elem);
		}
		else if (op == 's') {
			scanf("%d", &elem);
			getchar();
			search_table(ht,elem);
		}
		else if (op == 'p') {
			print_table(ht);
		}
		else if (op == 'e') {
			print_table(ht);
			break;
			
		}

	}
	free(ht);

	return 0;
}