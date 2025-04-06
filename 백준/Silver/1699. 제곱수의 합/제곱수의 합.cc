#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int dp[100001];
    for(int i = 0; i <= N; i++) dp[i] = i; // 초기화-최악의 경우: 1^2을 i번 더하는 것

    for(int i = 1; i <= N; i++) // 1부터 N까지 1씩 증가하면서 반복.(하나씩 올라가면서 그 전의 수의 정답을 저장함)
    {
        for(int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1); //여기서 +1은 새로 추가되는 항을 의미함
        }
    }
    cout << dp[N];

    return 0;
}
