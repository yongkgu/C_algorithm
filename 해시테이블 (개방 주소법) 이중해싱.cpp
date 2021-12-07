#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int elem;
	//6자리 또는 8자리 학번
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
			printf("%d\n", index); //주소
			return;
		}
		else //비어있지 않으면
		{
			value = h2(elem);
			index = (initvalue + (i*value)) % M;
			i = i + 1;
			printf("C"); 

			if (index == initvalue) //한바퀴돌아 제자리이면 
				break;
		}
	}
	printf("invalid exception\n"); //저장공간 오류
}

void search_table(hash_table ht[], int elem) {
	int index, initvalue;

	initvalue = index = h(elem);
	int initelem = elem;
	int value,i=1;
	while (1) {
		

		if ((ht + index)->elem == initelem) {
			printf("%d %d\n", index,initelem); //주소, 값 리턴
			return;
		}
		else //같지 않으면
		{
			value = h2(elem);
			index = (initvalue + (i*value)) % M;
			i = i + 1;
		
			if (index == initvalue) //한바퀴돌아 제자리이면 
				break;
		}
	}
	printf("-1\n"); //탐색 결과 없음
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

	//선언 및 초기화
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