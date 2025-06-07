#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int m, n, k; cin >> m >> n >> k;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<bool>> farm(n, vector<bool>(m, false));
        
        while(k--) {
            int x, y; cin >> x >> y;
            farm[y][x] = true;
        }

        int cnt = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(farm[i][j] && !visited[i][j]) {
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while(!q.empty()) {
                        pair<int, int> cur = q.front(); q.pop();

                        for(int d = 0; d < 4; ++d) {
                            int ny = cur.first + dy[d];
                            int nx = cur.second + dx[d];

                            if(ny >= 0 && ny < n && nx >= 0 && nx < m) {
                                if(farm[ny][nx] && !visited[ny][nx]) {
                                    visited[ny][nx] = true;
                                    q.push({ny, nx});
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
