#include <vector>
#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


   int t; cin >> t;
   for(int i=0; i<t; ++i){
      int num; cin >> num;
      vector<pair<int,int>> dp(num+1);
      dp[0].first = 1; dp[0].second = 0;
      if(num>=1){ 
         dp[1].first = 0; dp[1].second = 1;
      }
      for(int i=2; i<=num; ++i) {
         dp[i].first = dp[i-1].first+dp[i-2].first;
         dp[i].second = dp[i-1].second+dp[i-2].second;
      }
      cout << dp[num].first << " " << dp[num].second << "\n";
   }

    return 0;
}
