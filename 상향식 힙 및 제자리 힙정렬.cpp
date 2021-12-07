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
	if (i * 2 > _Heap.n) return; //비교할 자식이 없음
	if (_Heap.H[i] < _Heap.H[i * 2] || _Heap.H[i] < _Heap.H[i * 2 + 1]) //왼쪽 자식노드보다 작거나 또는 오른쪽 자식보다 작은 경우
	{
		if (_Heap.H[i * 2] > _Heap.H[i * 2 + 1]) //왼쪽노드가 오른쪽 노드보다 큰 경우
		{
			int temp;
			//스왑
			temp = _Heap.H[i];
			_Heap.H[i] = _Heap.H[i * 2];
			_Heap.H[i * 2] = temp;
			//재귀
			downHeap(i * 2);
		}
		else { //오른쪽이 큰 경우
			int temp;
			//스왑
			temp = _Heap.H[i];
			_Heap.H[i] = _Heap.H[i * 2 + 1];
			_Heap.H[i * 2 + 1] = temp;
			//재귀
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

void rBuildHeap(int i) { //리컬시브한 (배열에서만 이용가능)
	if (i > _Heap.n)
		return;
	if (i * 2 <= _Heap.n) //왼쪽 자식이 있으면 재귀호출
		rBuildHeap(2 * i);
	if (i * 2+1 <= _Heap.n) //오른쪽 자식이 있으면 재귀호출
		rBuildHeap(2 * i+1);

	downHeap(i); //재귀호출
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
	for (int i = 1;_Heap.H[i]> 0; i++) { //의미 없는 값이 나올때까지 출력해라
		printf("[%d] ", _Heap.H[i]);
		
	}
	printf("\n");
}
void main() {

	_Heap.n = 0; //초기화

	srand(time(NULL));

	printf("입력할 원소의 개수");
	scanf("%d", &_Heap.n);   //힙 사이즈 입력

	for (int i = 1; i <= _Heap.n; i++) {  //힙생성
		_Heap.H[i] = rand()%100;
	}

	buildHeap();
	printHeap();

	inPlaceHeapSort(); //오름차순으로 제자리 정렬
	printArray();
}