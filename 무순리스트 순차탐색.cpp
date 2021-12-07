#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//SIZE = 15

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
		scanf("%d",&d->dict[i].key);
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
int findElement(DictType *d, int key) {
	for (int i = 0; i < d->size; i++) {  
		if (key == d->dict[i].key)
			return i;
	}
	return -1;
}

element removeElem(DictType *d, int key) {
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

void printDict(DictType *d) {
	printf("key Value \n================\n");
	for (int i = 0; i < d->size; i++) {  //remove 된 상태를 고려 size를 쓴다
		printf("%d :%s  \n", d->dict[i].key,d->dict[i].value);
	}
}
int main() {

	DictType d;
	init (&d);
	srand(time(NULL));
	makeDict(&d);
	printDict(&d);

	int key;
	printf("검색할 키값을 입력 : ");
	scanf("%d", &key);
	int index = findElement(&d, key);
	if (index == -1)
		printf("실패\n\n");
	else
		printf("location : %d  key : %d value :", index+1, key);

		printf("%s", d.dict[index].value);

		printf("\n삭제할 키값 입력 : ");
		scanf("%d", &key);
		element item = removeElem(&d, key);
		printDict(&d);

	return 0;
}


