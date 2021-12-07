#include<stdio.h>

//가장 작은 것을 앞으로 보내는 알고리즘 (선택정렬)
int main() {

	int i, j, temp, min, array[10] = { 1,2,3,4,7,6,5,9,10,8 }, mindex;

	for (i = 0; i < 10; i++) {
		min = array[i];
		for (j = i; j < 10; j++) {
			if (min > array[j])
			{
				min = array[j];
				mindex = j;
			}
		}

		if (min < array[i]) {
			temp = array[i];
			array[i] = array[mindex];
			array[mindex] = temp;
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d -> ", array[i]);
	}

	return 0;
}