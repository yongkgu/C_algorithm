#include<stdio.h>
#include<stdlib.h>

#define SIZE 30
#define INDEX_SIZE 6

//�ε��� ��ġ �����
typedef struct {
	int key;
	int index;

}indexTable;

void insertionSort(int list[]) {

	int i, j;
	int key;

	for (i = 1; i < 30; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--){
			list[j+1] = list[j];
		}
		list[j + 1] = key;
	}

}
void make_indexTable(indexTable ilist[], int list[]) {
	int i, j;

	for (i = 0,j = 0; i < 5,j < 30; i++,j += 5) {
		ilist[i].key = list[j];
		ilist[i].index = j;
	}
}

int index_serch(int list[], indexTable ilist[], int key) {
	//list[0] <= key <= list[SIZE-1]
	// �̰� �ƴϸ� return

	//0 ~ index_size�� ����
	// key���� index���̿� �־�� �Ѵ�
	// ���̰� ������ = left ū�� = right
	// ����Ž�� �ǽ�
}
int main() {
	indexTable indexlist[INDEX_SIZE];
	int list[SIZE];
	int i;
	int j = 100;
	for (i = 0; i < 30 ; i++) {
		list[i] = j--;
	}
	insertionSort(list);
	make_indexTable(indexlist, list);

	for (i = 0; i < 30; i++) {
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%d ", list[i]);
	}

	printf("\n");
	for (i = 0; i <= 5; i++) {
		printf("key :%d index: %d\n", indexlist[i].key,indexlist[i].index);
	}

	return 0;
}