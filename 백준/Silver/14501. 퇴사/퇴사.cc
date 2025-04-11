#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int,int>> arr(N+2);
    vector<int> dp(N+2);
    for(int i=1; i<=N; i++)
        cin >> arr[i].first >> arr[i].second;

    // <풀이>
    // 맨 뒤부터 누적 이익을 계산(포함 X/O 결정해가면서)
    int profit = 0;
    for(int i=N; i>=1; --i){
        if(i+arr[i].first > N+1){ // 일이 끝나는 날짜가 전체 기간을 넘어서면
            dp[i] = dp[i+1]; //그냥 다음날까지의 이익 물려받음
        }
        else{
            dp[i] = max(dp[i+1], dp[i+arr[i].first]+arr[i].second); //이 부분이 핵심...!!!!!
        }
    }

    cout << dp[1];

    return 0;
}
