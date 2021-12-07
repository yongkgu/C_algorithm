#include<stdio.h>
#include<stdlib.h>
//이진탐색을 사용하면 O(logN) 선형탐색의 경우 O(N)
//삽입삭제가 드문 응용에서는 유용하다
//탐색이 빠르다

//선형탐색의 경우 KEY값과 I번째값을 비교해서 I값이 크면 오른쪽으로는 탐색할 필요없음.

//이진탐색을 구현해 보자

//재귀할 때마다 후보 항목들의 수가 반감
//배열로 구현하면 O(logn)   //연결리스트는 O(N) 아무런 이득이 없음

//분할통치 : 이등분된 두 개의 범위 양쪽을 모두 고려
//이진탐색 : 이등분된 두 개의 범위 한쪽만 고려 -> 효율적







typedef struct
{
	int key;
	char value[10];  //원소
}element;

typedef struct
{
	element dict[15];  //dictionary(사전)   //전체 사이즈
	int size;  //사전의 항목의 수
}DictType;

void init(DictType *d)  //항목 수 초기화
{
	d->size = 0;
}
void insertKey(DictType *d) {
	printf("키를 설정하세요\n");
	for (int i = 0; i < 15; i++) {
		scanf("%d", &d->dict[i].key);
	}
}

void insertValue(DictType *d) {

	printf("이름을 입력하세요\n");
	for (int i = 0; i < 15; i++) {
		scanf("%s", d->dict[i].value);
		getchar();
		d->size++;  //사전 원소 수 증가
	}

}
void makeDict(DictType* d)
{
	insertKey(d);
	insertValue(d);
}
void insertionSort(DictType *d) {
	int i, j;

	element item;

	for (i = 1; i < d->size; i++) {
		item = d->dict[i];
		for (j = i - 1; j >= 0 && d->dict[j].key > item.key; j--) {
			d->dict[j + 1] = d->dict[j];
		}
		d->dict[j + 1] = item;
	}
}

/*
element removeElem(DictType *d, int key) {   //다시 구현해 볼 것
	int index = findElement(d, key);
	element item = d->dict[index];
	element error;
	if (index == -1) {
		printf("삭제할 원소가 없습니다\n");
		return error;
	}
	else
	{

		//배열 재구성
		for (int i = index; i < d->size - 1; i++) {
			d->dict[i] = d->dict[i + 1]; //왼쪽으로 쉬프트
		}
		d->size--;
		return item;
	}

}
*/

int rFindElement(DictType *d,int key,int left,int right){ //재귀적
	int mid;

	if (left <= right)
	{
		mid = (left + right) / 2;

		if (key == d->dict[mid].key)
			return mid;
		else if (key < d->dict[mid].key)
			return rFindElement(d, key, left, mid - 1);
		else
			return rFindElement(d, key, mid + 1, right);
	}
	return -1;
	
}
int FindElement(DictType *d, int key) {  //비 재귀적
	int left = 0, right = 15 - 1;
	

	while (left <= right) {
		int mid = (left + right) / 2;
		if (key == d->dict[mid].key)
			return mid;
		else if (key < d->dict[mid].key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;

}
void printDict(DictType *d) {
	printf("key Value \n================\n");
	for (int i = 0; i < d->size; i++) {  //remove 된 상태를 고려 size를 쓴다
		printf("%d :%s  \n", d->dict[i].key, d->dict[i].value);
	}
}
int main() {

	DictType d;
	init(&d);
	makeDict(&d);
	printDict(&d);
	insertionSort(&d);
	printDict(&d);



	
	int key;
	printf("검색할 키값을 입력 : ");
	scanf("%d", &key);
	int index = rFindElement(&d, key,0,14);
	if (index == -1)
		printf("실패\n\n");
	else
		printf("location : %d  key : %d value :", index + 1, key);

	printf("%s\n", d.dict[index].value);



	
	
	return 0;
}



