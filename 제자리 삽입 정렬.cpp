#include<stdio.h>
#include<stdlib.h>


int main() {

	int *p, n, i, j, box;

	scanf("%d", &n);  //배열 크기 입력

	p = (int*)malloc((n)*sizeof(int)); //크기만큼 메모리 할당

	for (i = 0; i < n; i++) {  //배열 정보 입력
		scanf("%d", &p[i]);
	}

	for (i = 0; i < n-1; i++) {		// n-1까지
		j = i; //정렬된 곳 앞에서 부터 비교
		while (j >= 0 && p[j] > p[j + 1]) {	// 옆자리와 비교후 앞의 값이 크면 교환
			box = p[j];
			p[j] = p[j + 1];
			p[j + 1] = box;

			j--;  //뒤로 가면서 비교 연산, 0보다 작으면 루프 탈출
		}

	}

	for (i = 0; i < n; i++) {  //출력
		printf(" %d", p[i]);
	}

	free(p);	//메모리 반환

	return 0;
}