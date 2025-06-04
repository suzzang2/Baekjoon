#include <vector>
#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> dp(n+1);
    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    for(int i=3; i<=n; ++i) dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    cout << dp[n];

    return 0;
}
