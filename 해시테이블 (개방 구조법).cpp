#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//실습 :  KEY : 영단어 value : 한글의미 
// 해시테이블

#define TABLE_SIZE 13

typedef struct {
	char key[20];
	char value[100];

}Record;

void init_table(Record ht[])
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		ht[i].key[0] = ht[i].value[0] = NULL;  //비어있는 문자열로 초기화
	}
}
//문자열 키를 정수로 바꾸고 사이즈에 맞게끔 압축시키는 해시 함수
int transform(char* key) // -> INTERGER
{
	int number = 0;
	while (*key != NULL)
		number = number + *key++;
	return number;
}
int hash_function(char *key)  //DIVISOR
{
	return transform(key) % TABLE_SIZE;
}

int hash_function_prime(char *key)  //h'(k) DIVISOR
{
	//h'(k) = c - [k mod c]
	return 11 - (transform(key) % 11);
}


void insert_record(Record ht[], char *key, char *value)
{
	int i, hash_value;
	//해시주소 계산
	hash_value = i = hash_function(key); 
	//주소가 비어있는지 계산
	while (ht[i].key[0] != NULL)  //비어있지 않는 동안
	{
		//저장된 키와 삽입하려는 키가 동일한지??
		if (strcmp(ht[i].key, key) == 0)  //테이블의 키값과 삽입하려는 키값이 같으면
		{
			printf("[%s] 탐색키가 중복되었습니다.\n", key);
			return;
		}
		 //비어있지 않은데 키 값이 중복이 아니라면 i값을 증가시켜서 다음 버킷을 가르키도록 한다.
		
			i = (i + 1) % TABLE_SIZE; //인덱스 할당
			if (i == hash_value) { //한바퀴 돌아서 처음 i값이 되면 (증가된 주소가 시작주소로 되돌아 왔다면 빈 버킷이 없다.)
				printf("테이블이 가득찾습니다.\n");
				return;
			}
		
	}
	//빈칸을 찾았으면 삽입
	strcpy(ht[i].key, key);
	strcpy(ht[i].value, value);

}

void insert_record_qp(Record ht[], char *key, char *value) //2차 조사법
{
	int i, hash_value,inc = 0;  //inc 는 inc제곱 부분
	//해시주소 계산
	hash_value = i = hash_function(key);
	//주소가 비어있는지 계산
	while (ht[i].key[0] != NULL)  //비어있지 않는 동안
	{
		//저장된 키와 삽입하려는 키가 동일한지??
		if (strcmp(ht[i].key, key) == 0)  //테이블의 키값과 삽입하려는 키값이 같으면
		{
			printf("[%s] 탐색키가 중복되었습니다.\n", key);
			return;
		}

		//a[(h(k) + inc *inc) % mod M]
		i = (hash_value + inc * inc) % TABLE_SIZE; //인덱스 할당
		inc = inc + 1;

		if (i == hash_value) { //한바퀴 돌아서 처음 i값이 되면 (증가된 주소가 시작주소로 되돌아 왔다면 빈 버킷이 없다.)
			printf("테이블이 가득찾습니다.\n");
			return;
		}

	}
	//빈칸을 찾았으면 삽입
	strcpy(ht[i].key, key);
	strcpy(ht[i].value, value);

}


void insert_record_double(Record ht[], char *key, char *value)  //이중해시
{
	int i, hash_value;
	//해시주소 계산
	hash_value = i = hash_function(key);
	int inc = hash_function_prime(key);
	int j = 2;
	//주소가 비어있는지 계산
	while (ht[i].key[0] != NULL)  //비어있지 않는 동안
	{
		//저장된 키와 삽입하려는 키가 동일한지??
		if (strcmp(ht[i].key, key) == 0)  //테이블의 키값과 삽입하려는 키값이 같으면
		{
			printf("[%s] 탐색키가 중복되었습니다.\n", key);
			return;
		}
		//비어있지 않은데 키 값이 중복이 아니라면 i값을 증가시켜서 다음 버킷을 가르키도록 한다.

		i = (hash_value + inc) % TABLE_SIZE; //인덱스 할당
		inc = j*inc; //2차 충돌 시
		j++;

		if (i == hash_value) { //한바퀴 돌아서 처음 i값이 되면 (증가된 주소가 시작주소로 되돌아 왔다면 빈 버킷이 없다.)
			printf("테이블이 가득찾습니다.\n");
			return;
		}

	}
	//빈칸을 찾았으면 삽입
	strcpy(ht[i].key, key);
	strcpy(ht[i].value, value);

}
int search_record(Record ht[], char* key) //선형 조사
{
	int i, hash_value;
	hash_value = i = hash_function(key); //리턴되어지는 인덱스 값을 받아온다.

	while(ht[i].key[0] != NULL) //비어있지 않으면
	{
		//탐색하려는 키와 동일한지
		if (strcmp(ht[i].key, key) == 0) 
		{
			printf("[%8s] 탐색 성공. 인덱스 [%2d] %10s = %s.\n", key,i,ht[i].key,ht[i].value);
			return hash_value + i; //찾은 인덱스 리턴 (위치가 이동했을 수도 있으니 + i)
		}

		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) //증가된 주소가 시작주소로 되돌아 왔다면 빈 버킷이 없다.
			break;
	}
	printf("[%8s] 탐색 실패 \n", key);
	return NULL;
}
void print_table(Record ht[])
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%2d] %10s %s\n", i, ht[i].key, ht[i].value);
	}
	printf("\n");
}
void main()
{
	Record hash_table[TABLE_SIZE]; //선언
	//초기화
	init_table(hash_table);
	insert_record(hash_table, "do", "반 복");
	insert_record(hash_table, "for", "반 복");
	insert_record(hash_table, "if", "분 기");
	insert_record(hash_table, "case", "분 기");
	insert_record(hash_table, "else", "분 기");
	insert_record(hash_table, "return", "반 환");
	insert_record(hash_table, "function", "함 수");

	print_table(hash_table);

	search_record(hash_table, "return");
	search_record(hash_table, "function");
	search_record(hash_table, "class");


}
