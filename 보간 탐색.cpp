#include<stdio.h>
#include<stdlib.h>


/*
 ����Ž��
 �����̳� ��ȭ��ȣ�θ� Ž���ϴ� ���
	������ �����ϸ� ������ �޺κ� ���� ã��
	������ �����ϸ� ������ �պκп��� ã��
	
	Ž��Ű�� ������ ��ġ�� �����Ͽ� Ž���ϴ� ���
	O(nlogn)

	��ʽ��� �̿��� 
	Ž����ġ = (k-list[left]) / list[right]-list[left] *(right-left) + left

	����Ž������ ����� 
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 30

void insertionSort(int list[]) {

	int i, j;
	int key;

	for (i = 1; i < 30; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}

}

int search_interpolation(int list[], int key)
{
	int left;
	int right,j;
	left = 0;
	right = SIZE - 1;

	while (list[right] >= key && list[left] < key)
	{
		j = (int)((float)(key - list[left]) / (list[right] - list[left])*(right - left)) + left;
		if (key > list[j])
			left = j + 1;
		else if (key < list[j])
			right = j - 1;
		else
			left = j;
	}

	if (list[left] == key)
		return left;
	else
		return -1;

}

int main() {
	int list[SIZE];
	int i;
	int j = 100;
	for (i = 0; i < 30; i++) {
		list[i] = j--;
	}
	insertionSort(list);

	for (i = 0; i < 30; i++) {
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%d ", list[i]);
	}

	int key;
	printf("�˻��� Ű :");
	scanf("%d", &key);
	int index = search_interpolation(list, key); //���� �˻�
	
	if (index == -1) {
		printf("�˻�����\n");
	}
	else {
		printf("Ű�� ��ġ�� %d\n", index + 1);
	}




	return 0;
}