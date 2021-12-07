#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int elem;
	//6자리 또는 8자리 학번
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
		else //비어있지 않으면
		{
			elem = elem + 1;
			printf("C");
			index = h(elem);
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

	while (1) {


		if ((ht + index)->elem == initelem) {
			printf("%d %d\n", index, initelem); //주소, 값 리턴
			return;
		}
		else //같지 않으면
		{
			elem = elem + 1; //선형 조사
			index = h(elem);
			if (index == initvalue) //한바퀴돌아 제자리이면 
				break;
		}
	}
	printf("-1\n"); //탐색 결과 없음
}
int main() {

	int n, elem;
	char op;
	scanf("%d %d", &M, &n);
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