#include<stdio.h>
#include<stdlib.h>

typedef struct {

	int heap[100]; //배열
	int heap_size; //인덱스

}HeapType;

void init(HeapType* h) {

	h->heap_size = 0; //인덱스 초기화
}
void downHeap(HeapType *h) { //루트노드에 있는 값 제자리 찾게하기

	int temp = h->heap[1];  //루트 값 넣어놓기
	int parent = 1, child = 2; //루트부터 출발하기 위해 1,2로 각각 초기화

	while (child <= h->heap_size) { //자식 인덱스가 힙의 크기보다 작거나 같을 경우 실행

		if (child < h->heap_size && h->heap[child] < h->heap[child + 1]) //오른쪽이 비어있을 경우 방지 && 오른쪽노드가 더 크면 오른쪽노드로 이동
			child++;
		if (temp >= h->heap[child])  //자식값이 부모값(현재)보다 작거나 같을 경우 루프 탈출
			break;
		h->heap[parent] = h->heap[child]; //자식값을 부모값에 넣어주기 (스왑1)
		parent = child; //자식인덱스가 이젠 부모인덱스
		child *= 2;  //자식인덱스로 이동

	}

	h->heap[parent] = temp; //초기값 부모위치에 넣기(더이상 부모보다 큰 자식이 없으므로) (스왑2)


}

void upHeap(HeapType *h) {

	int i = h->heap_size;  //i = 인덱스
	int key = h->heap[i];  //키값은 가장 마지막 값

	while ((i != 1) && (key > h->heap[i / 2])) { //루트노드가 아니면서 부모노드보다 크면 교환 

		h->heap[i] = h->heap[i / 2]; //부모위치를 자식위치에 삽입 (스왑 1)
		i = i / 2; //부모위치로 이동
		
	}

	h->heap[i] = key; //이동 된 위치에 키값 넣기 (스왑 2)

}

void insertHeap(HeapType *h, int key) {  

	h->heap_size += 1;  //인덱스 +1
	h->heap[h->heap_size] = key; //키값 현재 인덱스에 삽입
	upHeap(h); //위로 올라가면서 자리 찾기

}

int removeHeap(HeapType *h) {

	int key = h->heap[1];				//가장 큰값 키값에 저장
	h->heap[1] = h->heap[h->heap_size]; //가장 마지막 값 루트에 저장
	h->heap_size -= 1;					 //마지막 공간 삭제

	downHeap(h);

	return key;
}

void printHeap(HeapType *h) {

	for (int i = 1; i <= h->heap_size; i++) {  //0번은 비워두고 1번부터 힙의 크기만큼
		printf(" %d", h->heap[i]);
	}
	printf("\n");
}

int main() {

	HeapType h;

	init(&h);  //초기화

	int key;
	char op;

	for (int i = 0; i < 100; i++) {
		scanf("%c", &op);
		getchar();
		switch (op) {
		case('i'):
			scanf("%d", &key);
			getchar();
			insertHeap(&h, key);   //삽입
			printf("0\n");
			break;
		case('d'):
			printf("%d", removeHeap(&h)); //삭제 및 삭제값 반환
			printf("\n");
			break;
		case('p'):
			printHeap(&h); //프린트
			break;
		case('q'):  //종료
			return 0;

		}
	}
	return 0;
}