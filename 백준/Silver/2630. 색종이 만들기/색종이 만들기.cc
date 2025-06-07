#include <iostream>
#include <vector>

using namespace std;

void dfs(int x, int y, int size, const vector<vector<int>>& paper, int& B, int& W){
    int color = paper[y][x];
    bool same = true;

    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (paper[i][j] != color) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (color == 1) B++;
        else W++;
    } else {
        int half = size / 2;
        dfs(x, y, half, paper, B, W); // 좌상
        dfs(x + half, y, half, paper, B, W); // 우상
        dfs(x, y + half, half, paper, B, W); // 좌하
        dfs(x + half, y + half, half, paper, B, W); // 우하
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<vector<int>> paper(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            cin >> paper[i][j];
    }

    int W = 0, B = 0;
    dfs(0, 0, n, paper, B, W);
    cout << W << "\n" << B;

    return 0;
}
