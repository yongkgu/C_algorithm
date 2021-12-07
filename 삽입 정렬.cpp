#include<stdio.h>

//삽입정렬 n**2
//복잡도는 선택 버블 삽입 정렬 모두 같지만 이 중에서 가장 효율적인 정렬은 삽입정렬
// 거의 정렬된 상태라면 매우 효율적인 정렬이다.

int main() {

	int i, j, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };

	for (i = 0; i < 9; i++) {
		j = i;
		while (array[j] > array[j + 1] && j>=0){
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}