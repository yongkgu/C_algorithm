#include<stdio.h>
#include<stdlib.h>


#define MAX_ELEMENT 100  

typedef struct
{
	int heap[MAX_ELEMENT];  //�迭 ũ�� 100
	int heap_size;  //�ε��� ��

}HeapType;

void init(HeapType *h){

	h->heap_size = 0; // �ε��� �� �ʱ�ȭ
}

void upHeap(HeapType *h) {
	
	int i = h->heap_size;  //�ε��� ũ�� i�� ����
	int key = h->heap[i];  //Ű���� ����� ���� Ű���ٰ� �־���

	while ((i != 1) && (key < h->heap[i / 2])) {  //��Ʈ�� �ƴϸ鼭, �θ� ��庸�� ������ ����
		h->heap[i] = h->heap[i / 2]; //�θ��带 �ڽĳ�忡 ����
		i /= 2;
	}
	//������ �������� ���ϸ� Ż���ϰ� �ǹǷ�  i���� ������ ���ҳ���� �θ��忡 ��ġ
	h->heap[i] = key;  //(���� ����)��忡 Ű�� �־��ֱ� 

}
void downHeap(HeapType *h) {  
	int temp = h->heap[1]; // ���� ��Ʈ���� �������̿��� ��(���� ū)�� temp�� ����
	int parent = 1, child = 2; //�θ� 1, �ڽ� 2 �ʱ�ȭ

	while (child <= h->heap_size) { //�ڽ��ε��� ���� ���� �ε����� ���ų� ũ�� ���� --> �ڽĳ�尡 ���� ũ�⺸��ũ�� ���̻� ������ ���� ���� ������

		if (child < h->heap_size && h->heap[child] > h->heap[child+1]  //���� �� ���� ���� �̵��ϱ� ���� 
			child++; //�ڽĳ�� 1���� (������ �ڽ����� �̵�)  �� if���� �������� ������ �ަU �ڽ����� �̵�
		if (temp <= h->heap[child]) //temp���� �ڽĳ�庸�� ������ ���̻� �̵����� �ʰ� Ż��
			break;

		h->heap[parent] = h->heap[child]; //���� (�ڽĳ�带 �θ���� = ���� ���� ����)
		parent = child; //child�� �ڽĳ�� ��ġ�� �� ���̱� ������ �� child�� �����ݺ��� �θ���
		child *= 2; //child�� �ڽĳ�忡 ��ġ
	}

	//�ݺ�
	h->heap[parent] = temp;
}

void insertItem(HeapType *h, int key) {

	h->heap_size += 1;  //�ε��� ���� (1���� ����)
	h->heap[h->heap_size] = key;  // �迭 �ε����� Ű �� �ֱ�
	upHeap(h); //��ġ �˻�
}

int removeMin(HeapType *h) {

	int key = h->heap[1]; //��Ʈ����� �����Ͱ��� Ű���� ����
	h->heap[1] = h->heap[h->heap_size]; //���� �ܺγ�� ��(������ ��)�� ��Ʈ ��忡 ����
	h->heap_size -= 1; //������ ��� ���� ������ ����
	downHeap(h); //��Ʈ������ �������鼭 ������ �´� �����Ͱ� �����ϱ�

	return key;  //(ó���� �ִ� ��Ʈ���)Ű �� ��ȯ 
}

void printHeap(HeapType *h) {
	for (int i = 1; i <= h->heap_size; i++) { //1���� �����������
		printf("[%d] ", h->heap[i]); //������ ���
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
		list[i] = removeMin(&heap); //���� ������ ����������
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