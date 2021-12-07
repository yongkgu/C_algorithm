/*
	줄 세우기 문제
		n명의 학생들을 키 순서대로 줄을 새워라
		단, 정보는 두 학생의 비교 정보만 얻을 수 있다.
		ex) a < b
		    b > c

			비교하지않으면 순서는 고려하지 않는다.
	
	게임 개발 문제
	개발에 걸리는 최소 시간 (가중치) 
	경로를 각각 출력하라
	*/

#include<iostream>
#include<vector>
#include<queue>

#define MAX 10 //최대 정점

using namespace std; //(홍)길동아

int n, inDegree[MAX],weight[MAX]; //정점의 갯수 , 집입차수 배열
vector<int>  a[MAX]; //그래프

void topologySort() {
	int result[MAX]; //결과 배열
	queue<int>  q;  //큐

					//진입 차수가 0인 노드를 큐에 삽입한다.
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			result[i] = weight[i]; //결과가 가중치니까
			q.push(i);
		}
	}

	//정렬이 완전히 수행 되려면 정확히 n개의 노드를 방문해야 함
	for (int i = 1; i <= n; i++)
	{
		//n개를 방문하기 전에 큐가 비면 사이클이 발생했다는 뜻.
		if (q.empty()) {
			printf("사이클 발생\n");
			return;
		}

		int x = q.front(); //선입선출

		q.pop(); //저장했으니 front 버리고

		result[i] = x; //결과배열에 저장

		for (int j = 0; j < a[x].size(); j++) //빼낸 정점이 가리키던 곳 모두 제거
		{
			int y = a[x][j];
			result[y] = max(result[y], result[x] + weight[y]); //둘 중 더 큰 값으로 갱신(반드시 거쳐야 하므로 큰 값이 되어야 함)
			//새롭게 진입차수가 0이된 정점을 큐에 삽입한다.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ->", result[i]);
	}

}

//메인 함수는 문제 조건에 맞게 다시 구현할 것.
void main()
{
	n = 7;
	a[1].push_back(2); //1은 2를 가리킨다
	inDegree[2]++;  //2의 진입차수 증가

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