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
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++)
            arr[i][j] = line[j - 1] - '0';
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    dp[1][1] = 1; // 시작점 거리 1

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                if (!visited[nx][ny] && arr[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    dp[nx][ny] = dp[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << dp[N][M] << '\n'; // 도착 지점의 거리 출력

    return 0;
}
