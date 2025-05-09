#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main(void){
   int n; cin >> n;
   vector<bool> arr(2000002, false);
   while(n--){
      int k; cin >> k;
      arr[k+1000000] = true;
   }
   for(int i = 0; i <= 2000001; ++i)
      if(arr[i]) cout << i - 1000000 << "\n";

   return 0;
}
