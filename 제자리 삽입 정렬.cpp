#include<stdio.h>
#include<stdlib.h>


int main() {

	int *p, n, i, j, box;

	scanf("%d", &n);  //�迭 ũ�� �Է�

	p = (int*)malloc((n)*sizeof(int)); //ũ�⸸ŭ �޸� �Ҵ�

	for (i = 0; i < n; i++) {  //�迭 ���� �Է�
		scanf("%d", &p[i]);
	}

	for (i = 0; i < n-1; i++) {		// n-1����
		j = i; //���ĵ� �� �տ��� ���� ��
		while (j >= 0 && p[j] > p[j + 1]) {	// ���ڸ��� ���� ���� ���� ũ�� ��ȯ
			box = p[j];
			p[j] = p[j + 1];
			p[j + 1] = box;

			j--;  //�ڷ� ���鼭 �� ����, 0���� ������ ���� Ż��
		}

	}

	for (i = 0; i < n; i++) {  //���
		printf(" %d", p[i]);
	}

	free(p);	//�޸� ��ȯ

	return 0;
}