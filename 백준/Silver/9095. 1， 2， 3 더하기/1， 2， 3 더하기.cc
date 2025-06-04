#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int t; cin >> t;
   while(t--){
    int n; cin >> n;
    vector<int> dp;
    dp.push_back(0); 
    dp.push_back(1); 
    dp.push_back(2); 
    dp.push_back(4);
    if(n<=3){ cout << dp[n] << "\n"; continue; }
    for(int i=4; i<=n; ++i){
        dp.push_back(dp[i-1]+dp[i-2]+dp[i-3]);
    }
    cout << dp[n] << "\n";
   }

   return 0;
}