#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
   int n; cin >> n;
   vector<vector<string>> arr(51);
   while(n--){
      string str; cin >> str;
      arr[str.length()].push_back(str);
   }
   for(vector<string> strs: arr){
      sort(strs.begin(), strs.end());
      if(strs.size()) {
         string bfr = "";
         for(string str: strs) {
            if(bfr == str) continue;
            cout << str << "\n";
            bfr = str;
         }
      }
   }

   return 0;
}