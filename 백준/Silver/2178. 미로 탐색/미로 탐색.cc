#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++)
            arr[i][j] = line[j - 1] - '0';
    }

    // 큐에 depth (단계)를 같이 저장
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 1}, 1}); // (좌표, depth)
    visited[1][1] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int x = cur.first.first;
        int y = cur.first.second;
        int depth = cur.second;

        if (x == N && y == M) {
            cout << depth << '\n'; // 도착하면 depth 출력
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                if (!visited[nx][ny] && arr[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, depth + 1});
                }
            }
        }
    }

    return 0;
}
