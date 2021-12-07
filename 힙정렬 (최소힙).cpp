#include<stdio.h>
#include<stdlib.h>


#define MAX_ELEMENT 100  

typedef struct
{
	int heap[MAX_ELEMENT];  //배열 크기 100
	int heap_size;  //인덱스 값

}HeapType;

void init(HeapType *h){

	h->heap_size = 0; // 인덱스 값 초기화
}

void upHeap(HeapType *h) {
	
	int i = h->heap_size;  //인덱스 크기 i에 저장
	int key = h->heap[i];  //키값이 저장된 힙을 키에다가 넣어줌

	while ((i != 1) && (key < h->heap[i / 2])) {  //루트가 아니면서, 부모 노드보다 작으면 스왑
		h->heap[i] = h->heap[i / 2]; //부모노드를 자식노드에 삽입
		i /= 2;
	}
	//조건을 만족하지 못하면 탈출하게 되므로  i값은 마지막 스왑노드의 부모노드에 위치
	h->heap[i] = key;  //(가장 상위)노드에 키값 넣어주기 

}
void downHeap(HeapType *h) {  
	int temp = h->heap[1]; // 현재 루트노드는 마지막이였던 값(가장 큰)을 temp에 저장
	int parent = 1, child = 2; //부모 1, 자식 2 초기화

	while (child <= h->heap_size) { //자식인덱스 보다 힙의 인덱스가 같거나 크면 실행 --> 자식노드가 힙의 크기보다크면 더이상 내려갈 곳이 없기 때문에

		if (child < h->heap_size && h->heap[child] > h->heap[child+1]  //값이 더 작은 노드로 이동하기 위해 
			child++; //자식노드 1증가 (오른쪽 자식으로 이동)  위 if문이 만족하지 않으면 왼쪾 자식으로 이동
		if (temp <= h->heap[child]) //temp값이 자식노드보다 작으면 더이상 이동하지 않고 탈출
			break;

		h->heap[parent] = h->heap[child]; //스왑 (자식노드를 부모노드로 = 작은 값을 위로)
		parent = child; //child가 자식노드 위치로 갈 것이기 때문에 현 child는 다음반복의 부모노드
		child *= 2; //child는 자식노드에 위치
	}

	//반복
	h->heap[parent] = temp;
}

void insertItem(HeapType *h, int key) {

	h->heap_size += 1;  //인덱스 증가 (1부터 시작)
	h->heap[h->heap_size] = key;  // 배열 인덱스에 키 값 넣기
	upHeap(h); //위치 검사
}

int removeMin(HeapType *h) {

	int key = h->heap[1]; //루트노드의 데이터값을 키값에 저장
	h->heap[1] = h->heap[h->heap_size]; //힙의 외부노드 값(마지막 값)을 루트 노드에 저장
	h->heap_size -= 1; //마지막 노드 공간 데이터 삭제
	downHeap(h); //루트노드부터 내려가면서 순위에 맞는 데이터값 저장하기

	return key;  //(처음에 있던 루트노드)키 값 반환 
}

void printHeap(HeapType *h) {
	for (int i = 1; i <= h->heap_size; i++) { //1부터 힙사이즈까지
		printf("[%d] ", h->heap[i]); //데이터 출력
	}
	printf("\n");
}

void heapSort(HeapType *h, int list[]) {
	HeapType heap;
	
	init(&heap);

	for (int i = 1; i <= h->heap_size; i++) {
		heap.heap[i] = h->heap[i];
		heap.heap_size++;
	}

	for (int i = 1; i <= h->heap_size; i++) {
		list[i] = removeMin(&heap); //작은 값부터 순차적으로
	}
}

void printArray(int list[], int n) {

	for (int i = 1; i <= n; i++)
		printf("[%d] ", list[i]);
	printf("\n");
}
void inPlaceHeapSort(HeapType *h) {
	int size = h->heap_size;
	int key;

	for (int i = 0; i < size; i++) {
		key = removeMin(h);
		h->heap[h->heap_size + 1] = key;
	}

}
void main() {


	HeapType heap;
	int list[MAX_ELEMENT] = { 0 };


	init(&heap);

	insertItem(&heap, 5);
	insertItem(&heap, 3);
	insertItem(&heap, 7);
	insertItem(&heap, 4);
	insertItem(&heap, 1);
	
	printHeap(&heap);
	//heapSort(&heap, list);
	//printArray(list, heap.heap_size);
	
	//printf("%d\n", removeMin(&heap));

	//inPlaceHeapSort(&heap);
	//for (int i = 1; heap.heap[i] > 0; i++)
		//printf("[%d] ", heap.heap[i]);

}