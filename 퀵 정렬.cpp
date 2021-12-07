#include<stdio.h>


//퀵 정렬 N*logN
//피벗(기준점)을 잡고 반으로 나누어 정렬
//가장 앞에 있는 수를 피벗값으로 설정 (가장 많이 하는 케이스)
//오른쪽으로 피벗보다 큰값 왼쪽으로 피벗보다 작은 값 찾기
// 큰 값과 작은 값을 교환한다 -> 피벗은 그대로  


//재귀함수 활용
//최악 시간 복잡도는 O[n**2]


int number = 10;
int data[10] = { 1,10,5,8,7,6,4,3,2,9 };


void quickSort(int *data,int start,int end){  

	if (start >= end) {  //원소가 1개인 경우
		return;
	}

	int key = start;  //키는 첫번째 원소 (key = pivot)
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {  //엇갈릴 때까지 반복

		while (data[i] <= data[key]) {  // 키 값보다 큰 값을 만날때가지 오른쪽으로 이동
			i++;
		}

		while (data[j] >= data[key] && j > start) { //키 값보다 작은 값을 만날 때까지 반복 // &&오버플로우 방지
			j--;
		}
		if (i > j) { //엇갈린 상태면 키 값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else { //엇갈리지 않았다면 큰 값과 작은 값을 교체한다.
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
		quickSort(data, start, j - 1);
		quickSort(data, j + 1, end);
	

}


int main() {

	quickSort(data, 0, number - 1);

	for (int i = 0; i < number; i++) {
		printf("%d ",data[i]);
	}


	return 0;
}

