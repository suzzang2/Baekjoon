#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    scanf("%d", &N);
    
    int arr[1001];
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);

    int dp[1001];
    for(int i = 1; i<=N; i++) dp[i] = arr[i];

    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    sort(dp, dp+N+1);
    printf("%d",dp[N]);

    return 0;
}
