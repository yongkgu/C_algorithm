#include<stdio.h>
#include<stdlib.h>

typedef struct {

	int heap[100]; //�迭
	int heap_size; //�ε���

}HeapType;

void init(HeapType* h) {

	h->heap_size = 0; //�ε��� �ʱ�ȭ
}
void downHeap(HeapType *h) { //��Ʈ��忡 �ִ� �� ���ڸ� ã���ϱ�

	int temp = h->heap[1];  //��Ʈ �� �־����
	int parent = 1, child = 2; //��Ʈ���� ����ϱ� ���� 1,2�� ���� �ʱ�ȭ

	while (child <= h->heap_size) { //�ڽ� �ε����� ���� ũ�⺸�� �۰ų� ���� ��� ����

		if (child < h->heap_size && h->heap[child] < h->heap[child + 1]) //�������� ������� ��� ���� && �����ʳ�尡 �� ũ�� �����ʳ��� �̵�
			child++;
		if (temp >= h->heap[child])  //�ڽİ��� �θ�(����)���� �۰ų� ���� ��� ���� Ż��
			break;
		h->heap[parent] = h->heap[child]; //�ڽİ��� �θ𰪿� �־��ֱ� (����1)
		parent = child; //�ڽ��ε����� ���� �θ��ε���
		child *= 2;  //�ڽ��ε����� �̵�

	}

	h->heap[parent] = temp; //�ʱⰪ �θ���ġ�� �ֱ�(���̻� �θ𺸴� ū �ڽ��� �����Ƿ�) (����2)


}

void upHeap(HeapType *h) {

	int i = h->heap_size;  //i = �ε���
	int key = h->heap[i];  //Ű���� ���� ������ ��

	while ((i != 1) && (key > h->heap[i / 2])) { //��Ʈ��尡 �ƴϸ鼭 �θ��庸�� ũ�� ��ȯ 

		h->heap[i] = h->heap[i / 2]; //�θ���ġ�� �ڽ���ġ�� ���� (���� 1)
		i = i / 2; //�θ���ġ�� �̵�
		
	}

	h->heap[i] = key; //�̵� �� ��ġ�� Ű�� �ֱ� (���� 2)

}

void insertHeap(HeapType *h, int key) {  

	h->heap_size += 1;  //�ε��� +1
	h->heap[h->heap_size] = key; //Ű�� ���� �ε����� ����
	upHeap(h); //���� �ö󰡸鼭 �ڸ� ã��

}

int removeHeap(HeapType *h) {

	int key = h->heap[1];				//���� ū�� Ű���� ����
	h->heap[1] = h->heap[h->heap_size]; //���� ������ �� ��Ʈ�� ����
	h->heap_size -= 1;					 //������ ���� ����

	downHeap(h);

	return key;
}

void printHeap(HeapType *h) {

	for (int i = 1; i <= h->heap_size; i++) {  //0���� ����ΰ� 1������ ���� ũ�⸸ŭ
		printf(" %d", h->heap[i]);
	}
	printf("\n");
}

int main() {

	HeapType h;

	init(&h);  //�ʱ�ȭ

	int key;
	char op;

	for (int i = 0; i < 100; i++) {
		scanf("%c", &op);
		getchar();
		switch (op) {
		case('i'):
			scanf("%d", &key);
			getchar();
			insertHeap(&h, key);   //����
			printf("0\n");
			break;
		case('d'):
			printf("%d", removeHeap(&h)); //���� �� ������ ��ȯ
			printf("\n");
			break;
		case('p'):
			printHeap(&h); //����Ʈ
			break;
		case('q'):  //����
			return 0;

		}
	}
	return 0;
}