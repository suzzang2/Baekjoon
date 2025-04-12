#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dy[4] = {0, 1, 0, -1};
int dir;

// 반시계 방향 회전
void turn() {
    dir = (dir + 3) % 4; // 반시계로 90도
}

// 앞 칸 좌표 반환
pair<int, int> checkFront(int x, int y) {
    return {x + dx[dir], y + dy[dir]};
}

// 뒤 칸 좌표 반환
pair<int, int> checkBack(int x, int y) {
    int backDir = (dir + 2) % 4; // 뒤 방향
    return {x + dx[backDir], y + dy[backDir]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int N, M;
    cin >> N >> M;
    int x, y;
    cin >> x >> y >> dir;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    int cnt = 0;
    while (true) {
        // 1. 현재 칸 청소
        if (map[x][y] == 0) {
            map[x][y] = -1;
            cnt++;
        }

        bool moved = false;

        // 2. 주변 4칸 확인
        for (int i = 0; i < 4; ++i) {
            turn();
            pair<int, int> front = checkFront(x, y);
            int fx = front.first, fy = front.second;

            if (fx < 0 || fy < 0 || fx >= N || fy >= M) continue;

            if (map[fx][fy] == 0) {
                x = fx;
                y = fy;
                moved = true;
                break;
            }
        }

        if (moved) continue;

        // 3. 후진
        pair<int, int> back = checkBack(x, y);
        int bx = back.first, by = back.second;

        if (bx < 0 || by < 0 || bx >= N || by >= M || map[bx][by] == 1)
            break; // 벽이면 종료
        else {
            x = bx;
            y = by;
        }
    }

    cout << cnt << "\n";
    return 0;
}
