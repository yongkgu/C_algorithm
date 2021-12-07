#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define MAX_SIZE 15
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
	int i = left;  //���ʺκ�
	int j = mid + 1; //������ �κ�

	int k = left;   //���ο� �迭�� ���ʺ��� ����
	
	int l;

	//���ʺκа� ������ �κ��� ���ϸ鼭 ���ο� �迭�� ����
	while (i <= mid && j <= right)  //���ʰ� �������� �񱳰����� ���
	{
		if (list[i] <= list[j])  //������ ���� ���̶�� ���ʰ��� ����
			sorted[k++] = list[i++]; //�����Ͽ����� ���ʺκ� ��ĭ �̵�
		else  //�������� ���� ���̶�� ������ ���� ����
			sorted[k++] = list[j++]; //�����Ͽ����� �����ʺκ� ��ĭ �̵�
	}
	
	if (i > mid) //���� ������ ����ٸ�
		for (l = j; l <= right; l++)  //�����ִ� ������ ���� �迭�� ����
			sorted[k++] = list[l];
	else		//���� �������� ����ٸ�
		for (l = i; l <= mid; l++)	  //�����ִ� ���� ���� �迭�� ����
			sorted[k++] = list[l];     


	for (l = left; l <= right; l++)   //���ĵ� �迭�� �����ϱ� ���� ���� �迭�� ����
		list[l] = sorted[l];
	

		
}

void merge_sort(int list[], int left, int right) //�迭, ���ʿ��� �ε���,�����ʿ��� �ε���
{
	int mid;

	if (left < right) //���� �� �� ������
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

	//�Է�
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = rand() % 100;
		for (int j = 0; j < i; j++)   //�����Լ� �ߺ� ����
			if (list[i] == list[j])
				i--;
	}

	//���
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
