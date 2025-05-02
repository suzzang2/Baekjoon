#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = INT_MAX;
    int k = info.size();
    //첫 i개의 물건을 고려했을 때, B 도둑의 누적 흔적이 j일 때의 최소 A 도둑의 누적 흔적
    vector<vector<int>> dp(k + 1, vector<int>(m, INF)); 
    dp[0][0] = 0; //시작점

    for (int i = 0; i < k; ++i) { //물건 개수만큼 반복
        int a = info[i][0];
        int b = info[i][1];
        for (int j = 0; j < m; ++j) { //0부터 b가 버틸 수 있는 흔적까지
            if (dp[i][j] == INF) continue;
            // A 도둑이 훔치는 경우
            if (dp[i][j] + a < n)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a);
            // B 도둑이 훔치는 경우
            if (j + b < m)
                dp[i + 1][j + b] = min(dp[i + 1][j + b], dp[i][j]);
        }
    }

    int answer = INF;
    for (int j = 0; j < m; ++j) {
        answer = min(answer, dp[k][j]);
    }

    return (answer == INF) ? -1 : answer;
}