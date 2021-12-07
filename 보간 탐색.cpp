#include<stdio.h>
#include<stdlib.h>


/*
 보간탐색
 사전이나 전화번호부를 탐색하는 방법
	ㅎ으로 시작하면 사전의 뒷부분 부터 찾음
	ㄱ으로 시작하면 사전의 앞부분에서 찾음
	
	탐색키가 존재할 위치를 예측하여 탐색하는 방법
	O(nlogn)

	비례식을 이용함 
	탐색위치 = (k-list[left]) / list[right]-list[left] *(right-left) + left

	이진탐색보다 우수함 
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
	printf("검색할 키 :");
	scanf("%d", &key);
	int index = search_interpolation(list, key); //보간 검색
	
	if (index == -1) {
		printf("검색실패\n");
	}
	else {
		printf("키의 위치는 %d\n", index + 1);
	}




	return 0;
}