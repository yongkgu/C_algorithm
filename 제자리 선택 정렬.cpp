#include<stdio.h>
#include<stdlib.h>


int main() {

	int *p,n, i, j,max,box,index;
	
	scanf("%d", &n); //ũ�� �Է�

	p = (int*)malloc(n * sizeof(int)); //�޸� �Ҵ�

	for (i = 0; i < n; i++) {  //�� ����
		scanf("%d", &p[i]);
	}

	

	for (i = 0; i < n; i++) {
		
		max = p[n - i-1];  //������ �� 

		for (j = 0; j < n - i; j++) {
			if (p[j] >= max) { // �ִ밪 ���� ũ�ų� ������
				max = p[j];    // max�� ����	
				index = j;		//�ε��� �� ����
			}
		}

		//swap���ֱ�
		box = p[n-i-1];
		p[n-i-1] = p[index];
		p[index] = box;

	}
	
	for(i=0;i<n;i++)  //���
		printf("%d ", p[i]);


	free(p);   //�޸� ��ȯ

	return 0;
}