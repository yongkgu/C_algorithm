#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int elem;
	//6�ڸ� �Ǵ� 8�ڸ� �й�
}hash_table;

int M;

int h(int x) {
	return x % M;
}
void insert_table(hash_table ht[], int elem) {
	int index, initvalue;

	initvalue = index = h(elem);
	int initelem = elem;

	while (1) {


		if ((ht + index)->elem == NULL) {
			(ht + index)->elem = initelem;
			printf("%d\n", index);
			return;
		}
		else //������� ������
		{
			elem = elem + 1;
			printf("C");
			index = h(elem);
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

	while (1) {


		if ((ht + index)->elem == initelem) {
			printf("%d %d\n", index, initelem); //�ּ�, �� ����
			return;
		}
		else //���� ������
		{
			elem = elem + 1; //���� ����
			index = h(elem);
			if (index == initvalue) //�ѹ������� ���ڸ��̸� 
				break;
		}
	}
	printf("-1\n"); //Ž�� ��� ����
}
int main() {

	int n, elem;
	char op;
	scanf("%d %d", &M, &n);
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
			insert_table(ht, elem);
		}
		else if (op == 's') {
			scanf("%d", &elem);
			getchar();
			search_table(ht, elem);
		}
		else if (op == 'e') {
			break;

		}

	}
	free(ht);

	return 0;
}