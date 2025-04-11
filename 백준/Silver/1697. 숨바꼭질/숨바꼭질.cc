#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    const int MAX = 100001;
    vector<int> visited(MAX, 0); // 걸린 시간을 저장함

    queue<int> q;
    // 출발 지점으로 초기화
    q.push(N);
    visited[N] = 1; 

    ///BFS///
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        //동생을 찾았으면 종료
        if(cur == K){
            cout << visited[cur]-1;
            break;
        }

        // 이동할 수 있는 3가지 경우
        for(int next : {cur-1, cur+1, cur*2}){
            if(next<MAX && next>=0 && visited[next] == 0){ // 다음에 갈 곳을 방문하지 않았으면
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }

    return 0;
}
