#include <string>  
#include <vector>  
#include <iostream>  
#include <queue>  
using namespace std;  
  
int inde[1000005];  
int outde[1000005];  
vector<vector<int>> path(1000005);  
int t8=0,t1=0,t0=0;  
  
//그래프 단위로 실행될 함수
void check(int start){  
	queue<int> q;  
	q.push(start);  // 지금 케이스에서는 3, 1이 들어감
	bool isvisted = false;   //시작점을 방문 했는지
	while(!q.empty()){  
		int now = q.front();  
		q.pop();  
		if(now == start && isvisted){  //처음으로 돌아왔으면 -> 도넛모양
			t0++;  
			return;  
		}  
  
		if(path[now].size() >= 2){   //해당 node에 연결된 edge가 2개 이상이면 -> 8자 모양
			t8++;  
			return;  
		}  
  
		for(int i=0; i< path[now].size(); i++){  
			q.push(path[now][i]);  //bfs로, 다음 node로 이동
		}	  
		isvisted = true;  
	}  
	t1++;  //둘 다 아니면 -> 막대 모양
	return;  
}  
  
  
vector<int> solution(vector<vector<int>> edges) {  
	vector<int> answer;  
  
   //전역 배열들 초기화
	for(int i=0; i<edges.size(); i++){  
		inde[edges[i][1]]++;  //각 node에 몇 개 들어오는지(Just 개수)
		outde[edges[i][0]]++;  // 각 node에서 몇 개 나가는지(just 개수)
		path[edges[i][0]].push_back(edges[i][1]);  //각 node에 연결된 node로 edge 재정리
	}  
   //루트 노드 구하기
	for(int i=1; i<1000005; i++){  
		if(inde[i] == 0 && outde[i] >=2){  
			answer.push_back(i);  
		}  
	}  
  
	vector<int> start = path[answer[0]];  //루트 노드에 연결된 노드들

	for(int i=0; i<start.size(); i++){  
		check(start[i]);  // 각각의 그래프에 하나씩 뻗어나가기 때문에, 이렇게 해주면 모든 그래프들에 한번씩 check()가 실행되는 것이다. 
	}  

	answer.push_back(t0);  
	answer.push_back(t1);  
	answer.push_back(t8);  
	return answer;  
}