#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//SIZE = 15

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
		scanf("%d",&d->dict[i].key);
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

void printDict(DictType *d) {
	printf("key Value \n================\n");
	for (int i = 0; i < d->size; i++) {  //remove �� ���¸� ��� size�� ����
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
	printf("�˻��� Ű���� �Է� : ");
	scanf("%d", &key);
	int index = findElement(&d, key);
	if (index == -1)
		printf("����\n\n");
	else
		printf("location : %d  key : %d value :", index+1, key);

		printf("%s", d.dict[index].value);

		printf("\n������ Ű�� �Է� : ");
		scanf("%d", &key);
		element item = removeElem(&d, key);
		printDict(&d);

	return 0;
}


