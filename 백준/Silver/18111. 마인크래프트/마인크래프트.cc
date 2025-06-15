#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> land(N, vector<int>(M));
    int maxH = 0, minH = 256;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> land[i][j];
            maxH = max(maxH, land[i][j]);
            minH = min(minH, land[i][j]);
        }
    }

    int resultTime = 1e9;
    int resultHeight = 0;

    // 0부터 256까지 모든 높이 시도
    for(int h = minH; h <= maxH; ++h) {
        int time = 0;
        int blocks = B;

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                int diff = land[i][j] - h;

                if(diff > 0) {
                    // 블록 제거
                    time += diff * 2;
                    blocks += diff;
                } else {
                    // 블록 추가
                    time += -diff * 1;
                    blocks += diff; // blocks -= (-diff)
                }
            }
        }

        if(blocks >= 0) {
            if(time < resultTime || (time == resultTime && h > resultHeight)) {
                resultTime = time;
                resultHeight = h;
            }
        }
    }

    cout << resultTime << " " << resultHeight << '\n';
    return 0;
}
