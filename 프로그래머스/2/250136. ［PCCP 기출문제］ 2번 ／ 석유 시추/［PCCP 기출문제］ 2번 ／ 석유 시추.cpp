// #include <string>
// #include <vector>
// #include <iostream>
// #include <queue>

// using namespace std;
// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};

// int solution(vector<vector<int>> land) {
//     int n = land.size();
//     int m = land[0].size();
    
//     vector<vector<int>> arr(n, vector<int>(m,0));
//     for(int i=0; i<n; ++i){
//         for(int j=0; j<m; ++j) if(land[i][j]) arr[i][j] = 1;
//     }
//     //출력부
//     for(vector<int> v: arr){
//         for(int k: v) cout << k << " ";
//         cout << "\n";
//     }
    
//     vector<vector<bool>> visited(n, vector<bool>(m,false));
//     queue<pair<int,int>> q;

//     pair<int,int> start = {0,0};
//     q.push(start);
//     visited[start.first][start.second] = true;

//     while (!q.empty()) {
//         pair<int,int> cur = q.front();
//         int curX = cur.first; int curY = cur.second;
//         q.pop();
//         cout << "Visited-(" << curX+1 << " " << curY+1 << ")\n";

//         if(visited)
//         if(arr[cur.first][cur.second]){ //석유 있으면
            
//         } else{ //없으면
//             if(curX >= m-1){ //마지막 열이면
//                 q.push({0, })
//             }
//             q.push({curX+1,curY+1});
//         }
//     }
    
//     int answer = 0;
//     return answer;
// }
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> oilAmountByCol(m, 0); // 각 열마다 석유량 누적

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (land[i][j] == 1 && !visited[i][j]){
                // 새로운 석유 덩어리 탐색 시작
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;

                int size = 1; // 석유량
                set<int> colSet; // 이 덩어리가 지나간 열 번호들
                colSet.insert(j);

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int d = 0; d < 4; ++d){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (visited[nx][ny] || land[nx][ny] == 0) continue;

                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        size++;
                        colSet.insert(ny);
                    }
                }

                // 이 석유 덩어리가 걸쳐 있는 열들에 석유량 더해주기
                for (int col : colSet){
                    oilAmountByCol[col] += size;
                }
            }
        }
    }

    // 가장 많이 나온 석유량
    int answer = 0;
    for (int amount : oilAmountByCol){
        answer = max(answer, amount);
    }
    return answer;
}
