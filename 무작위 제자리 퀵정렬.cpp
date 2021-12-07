#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 15
#define SWAP(x,y,t) ((t) = (x), (x)=(y), (y) = (t))
int partition(int list[], int left, int right,int k) {

	int pivot, temp, low, high;

	pivot = list[k];
	SWAP(list[k], list[right], temp);

	low = left-1;
	high = right;  // do while ���� ����ϱ� ���ؼ�

	

	do
	{
		do
			low++;
		while (list[low] < pivot);

		do
			high--;
		while (list[high] > pivot);

		if (low < high)
			SWAP(list[low], list[high], temp);

	} while (low < high);

	SWAP(list[low], list[right], temp);

	return high;
}
void quick_sort(int list[], int left, int right) {

	if (left < right)
	{
		int k = rand() % (right - left)+ left +1;
		int q = partition(list, left, right,k);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}

}

void main() {
	int list[MAX_SIZE];
	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");

	quick_sort(list, 0, MAX_SIZE - 1);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
}
