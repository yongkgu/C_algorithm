#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ELEMENT 100

struct Heap
{
	int H[MAX_ELEMENT];
	int n;
}_Heap;

void downHeap(int i) {
	if (i * 2 > _Heap.n) return; //���� �ڽ��� ����
	if (_Heap.H[i] < _Heap.H[i * 2] || _Heap.H[i] < _Heap.H[i * 2 + 1]) //���� �ڽĳ�庸�� �۰ų� �Ǵ� ������ �ڽĺ��� ���� ���
	{
		if (_Heap.H[i * 2] > _Heap.H[i * 2 + 1]) //���ʳ�尡 ������ ��庸�� ū ���
		{
			int temp;
			//����
			temp = _Heap.H[i];
			_Heap.H[i] = _Heap.H[i * 2];
			_Heap.H[i * 2] = temp;
			//���
			downHeap(i * 2);
		}
		else { //�������� ū ���
			int temp;
			//����
			temp = _Heap.H[i];
			_Heap.H[i] = _Heap.H[i * 2 + 1];
			_Heap.H[i * 2 + 1] = temp;
			//���
			downHeap(i * 2 + 1);
		}
	}
	else
		return;
	
}
void buildHeap() {
	for (int i = _Heap.n / 2; i >= 1; i--) {
		downHeap(i);
	}
}

void rBuildHeap(int i) { //���ýú��� (�迭������ �̿밡��)
	if (i > _Heap.n)
		return;
	if (i * 2 <= _Heap.n) //���� �ڽ��� ������ ���ȣ��
		rBuildHeap(2 * i);
	if (i * 2+1 <= _Heap.n) //������ �ڽ��� ������ ���ȣ��
		rBuildHeap(2 * i+1);

	downHeap(i); //���ȣ��
}
int removeMax() {
	int key = _Heap.H[1];
	_Heap.H[1] = _Heap.H[_Heap.n--];
	downHeap(1);
	return key;
}
void inPlaceHeapSort() {
	int size = _Heap.n;
	int key;
	for (int i = 1; i < size; i++) {
		key = removeMax();
		_Heap.H[_Heap.n+1] = key;
	}
}
void printHeap() {
	for (int i = 1; i <= _Heap.n; i++) {
		printf("[%d] ", _Heap.H[i]);
	
	}
	printf("\n");
}
void printArray() {
	for (int i = 1;_Heap.H[i]> 0; i++) { //�ǹ� ���� ���� ���ö����� ����ض�
		printf("[%d] ", _Heap.H[i]);
		
	}
	printf("\n");
}
void main() {

	_Heap.n = 0; //�ʱ�ȭ

	srand(time(NULL));

	printf("�Է��� ������ ����");
	scanf("%d", &_Heap.n);   //�� ������ �Է�

	for (int i = 1; i <= _Heap.n; i++) {  //������
		_Heap.H[i] = rand()%100;
	}

	buildHeap();
	printHeap();

	inPlaceHeapSort(); //������������ ���ڸ� ����
	printArray();
}