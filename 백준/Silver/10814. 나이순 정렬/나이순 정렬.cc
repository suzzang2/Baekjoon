#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main(void){
   int n; cin >> n;
   vector<vector<string>> data(201);
   while(n--) {
      int n; string str;
      cin >> n >> str;
      data[n].push_back(str);
   }

   for(int i=1; i<=200; ++i){
      if(data[i].size()==0) continue;
      for(string name: data[i]) cout << i << " " << name << "\n";
   }
   return 0;
}