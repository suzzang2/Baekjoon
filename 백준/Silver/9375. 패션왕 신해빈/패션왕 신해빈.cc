#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void){
     ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int n; cin >> n;
      while(n--){
         map<string, int> M;
         int m; cin >> m;
         while(m--){
            string name; string type;
            cin >> name >> type;
            M[type]++;
         }
         // cout << "\n\n\n";
         int cnt = 1;
         for(auto& it: M){
            // cout << it.first << " " << it.second << "\n";
            cnt *= it.second+1;
         }
         cout << cnt-1 << "\n";
      }
   
   return 0;
}