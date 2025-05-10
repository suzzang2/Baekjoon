#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>

using namespace std;


int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int n; cin >> n;
   vector<int> arr(20000002, 0);
   while(n--){
      int k; cin >> k;
      arr[k+10000000]++;
   }
   int m; cin >> m;
   while(m--){
      int k; cin >> k;
      cout << arr[k+10000000] << " ";
   }

   return 0;
}
