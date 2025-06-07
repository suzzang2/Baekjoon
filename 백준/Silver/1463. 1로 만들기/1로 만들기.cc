#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0); // dp[i] = i를 1로 만드는 데 필요한 최소 연산 횟수

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1; // 기본적으로 -1 연산을 했다고 가정

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
