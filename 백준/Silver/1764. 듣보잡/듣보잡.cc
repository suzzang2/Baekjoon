#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(void){
     ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int n, m; cin >> n >> m;
      map<string, int> M;
      int cnt = 0;
      while(n--){
         string str; cin >> str;
         M[str]++;
      }
      while(m--){
         string str; cin >> str;
         M[str]++;
         if(M[str]==2) cnt++;
      }
      cout << cnt << "\n";
      for(auto &it: M){
         if(it.second == 2) cout << it.first << "\n";
      }

   return 0;
}