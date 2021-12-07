#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define MAX_SIZE 15
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
	int i = left;  //왼쪽부분
	int j = mid + 1; //오른쪽 부분

	int k = left;   //새로운 배열에 왼쪽부터 정렬
	
	int l;

	//왼쪽부분과 오른쪽 부분을 비교하면서 새로운 배열에 정렬
	while (i <= mid && j <= right)  //왼쪽과 오른쪽이 비교가능할 경우
	{
		if (list[i] <= list[j])  //왼쪽이 작은 값이라면 왼쪽값을 저장
			sorted[k++] = list[i++]; //저장하였으니 왼쪽부분 한칸 이동
		else  //오른쪽이 작은 값이라면 오른쪽 값을 저장
			sorted[k++] = list[j++]; //저장하였으니 오른쪽부분 한칸 이동
	}
	
	if (i > mid) //만약 왼쪽이 비었다면
		for (l = j; l <= right; l++)  //남아있는 오른쪽 값을 배열에 저장
			sorted[k++] = list[l];
	else		//만약 오른쪽이 비었다면
		for (l = i; l <= mid; l++)	  //남아있는 왼쪽 값을 배열에 저장
			sorted[k++] = list[l];     


	for (l = left; l <= right; l++)   //정렬된 배열을 리턴하기 위해 기존 배열에 삽입
		list[l] = sorted[l];
	

		
}

void merge_sort(int list[], int left, int right) //배열, 왼쪽원소 인덱스,오른쪽원소 인덱스
{
	int mid;

	if (left < right) //분할 할 수 있으면
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list,left,mid,right);
	}
}



void main() {

	int list[MAX_SIZE];
	srand(time(NULL));

	//입력
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = rand() % 100;
		for (int j = 0; j < i; j++)   //랜드함수 중복 제거
			if (list[i] == list[j])
				i--;
	}

	//출력
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("[%d] ", list[i]);
	}
	printf("\n\n");

	merge_sort(list, 0, MAX_SIZE - 1);
	
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("[%d] ", list[i]);
	}
	printf("\n\n");

}
