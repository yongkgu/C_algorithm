#include<iostream>
#include<vector>
#include<queue>

#define MAX 10 //�ִ� ����

using namespace std; //(ȫ)�浿��

int n, inDegree[MAX]; //������ ���� , �������� �迭
vector<int>  a[MAX]; //�׷���

void topologySort() {
	int result[MAX]; //��� �迭
	queue<int>  q;  //ť

	//���� ������ 0�� ��带 ť�� �����Ѵ�.
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0) q.push(i);
	}

	//������ ������ ���� �Ƿ��� ��Ȯ�� n���� ��带 �湮�ؾ� ��
	for (int i = 1; i <= n; i++)
	{
		//n���� �湮�ϱ� ���� ť�� ��� ����Ŭ�� �߻��ߴٴ� ��.
		if (q.empty()) {
			printf("����Ŭ �߻�\n");
			return;
		}

		int x = q.front(); //���Լ���
		
		q.pop(); //���������� front ������
		
		result[i] = x; //����迭�� ����

		for (int j = 0; j < a[x].size(); j++) //���� ������ ����Ű�� �� ��� ����
		{
			int y = a[x][j];
			//���Ӱ� ���������� 0�̵� ������ ť�� �����Ѵ�.
			if (--inDegree[y] == 0) 
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ->", result[i]);
	}

}

void main()
{
	n = 7;
	a[1].push_back(2); //1�� 2�� ����Ų��
	inDegree[2]++;  //2�� �������� ����

	a[1].push_back(5);
	inDegree[5]++;
	
	a[2].push_back(3);
	inDegree[3]++;
	
	a[3].push_back(4);
	inDegree[4]++;
	
	a[4].push_back(6);
	inDegree[6]++;
	
	a[5].push_back(6);
	inDegree[6]++;
	
	a[6].push_back(7);
	inDegree[7]++;

	topologySort();
}