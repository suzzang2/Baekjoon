#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main(void){
   int n; cin >> n;
   vector<vector<int>> data(200002);
   while(n--) {
      int n; int x, y;
      cin >> x >> y;
      data[x+100000].push_back(y);
   }

   for(int i=0; i<=200000; ++i){
      if(data[i].size()==0) continue;
      sort(data[i].begin(), data[i].end());
      for(int y: data[i]) cout << i-100000 << " " << y << "\n";
   }
   return 0;
}