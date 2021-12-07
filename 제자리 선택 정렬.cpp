#include<stdio.h>
#include<stdlib.h>


int main() {

	int *p,n, i, j,max,box,index;
	
	scanf("%d", &n); //크기 입력

	p = (int*)malloc(n * sizeof(int)); //메모리 할당

	for (i = 0; i < n; i++) {  //값 저장
		scanf("%d", &p[i]);
	}

	

	for (i = 0; i < n; i++) {
		
		max = p[n - i-1];  //마지막 값 

		for (j = 0; j < n - i; j++) {
			if (p[j] >= max) { // 최대값 보다 크거나 같으면
				max = p[j];    // max값 갱신	
				index = j;		//인덱스 값 갱신
			}
		}

		//swap해주기
		box = p[n-i-1];
		p[n-i-1] = p[index];
		p[index] = box;

	}
	
	for(i=0;i<n;i++)  //출력
		printf("%d ", p[i]);


	free(p);   //메모리 반환

	return 0;
}