#include<stdio.h>
#include<stdlib.h>
//����Ž���� ����ϸ� O(logN) ����Ž���� ��� O(N)
//���Ի����� �幮 ���뿡���� �����ϴ�
//Ž���� ������

//����Ž���� ��� KEY���� I��°���� ���ؼ� I���� ũ�� ���������δ� Ž���� �ʿ����.

//����Ž���� ������ ����

//����� ������ �ĺ� �׸���� ���� �ݰ�
//�迭�� �����ϸ� O(logn)   //���Ḯ��Ʈ�� O(N) �ƹ��� �̵��� ����

//������ġ : �̵�е� �� ���� ���� ������ ��� ���
//����Ž�� : �̵�е� �� ���� ���� ���ʸ� ��� -> ȿ����







typedef struct
{
	int key;
	char value[10];  //����
}element;

typedef struct
{
	element dict[15];  //dictionary(����)   //��ü ������
	int size;  //������ �׸��� ��
}DictType;

void init(DictType *d)  //�׸� �� �ʱ�ȭ
{
	d->size = 0;
}
void insertKey(DictType *d) {
	printf("Ű�� �����ϼ���\n");
	for (int i = 0; i < 15; i++) {
		scanf("%d", &d->dict[i].key);
	}
}

void insertValue(DictType *d) {

	printf("�̸��� �Է��ϼ���\n");
	for (int i = 0; i < 15; i++) {
		scanf("%s", d->dict[i].value);
		getchar();
		d->size++;  //���� ���� �� ����
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
element removeElem(DictType *d, int key) {   //�ٽ� ������ �� ��
	int index = findElement(d, key);
	element item = d->dict[index];
	element error;
	if (index == -1) {
		printf("������ ���Ұ� �����ϴ�\n");
		return error;
	}
	else
	{

		//�迭 �籸��
		for (int i = index; i < d->size - 1; i++) {
			d->dict[i] = d->dict[i + 1]; //�������� ����Ʈ
		}
		d->size--;
		return item;
	}

}
*/

int rFindElement(DictType *d,int key,int left,int right){ //�����
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
int FindElement(DictType *d, int key) {  //�� �����
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
	for (int i = 0; i < d->size; i++) {  //remove �� ���¸� ��� size�� ����
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
	printf("�˻��� Ű���� �Է� : ");
	scanf("%d", &key);
	int index = rFindElement(&d, key,0,14);
	if (index == -1)
		printf("����\n\n");
	else
		printf("location : %d  key : %d value :", index + 1, key);

	printf("%s\n", d.dict[index].value);



	
	
	return 0;
}



