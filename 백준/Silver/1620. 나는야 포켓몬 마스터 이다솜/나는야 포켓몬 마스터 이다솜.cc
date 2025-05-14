#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <map>
using namespace std;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int n,m; cin >> n >> m;
   map<string,int> byName;
   vector<string> byNum(n+1);
   for(int i=0; i<n; ++i){
      string str; cin >> str;
      byName[str] = i+1;
      byNum[i+1] = str;
   }
   for(int i=0; i<m; ++i){
      string str; cin >> str;
      if(str[0]>='0' && str[0]<='9') cout << byNum[stoi(str)] << "\n";
      else cout << byName[str] << "\n";
   }

   return 0;
}