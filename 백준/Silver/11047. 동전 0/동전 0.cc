#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main(void){
     ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int n, k; cin >> n >> k;
      vector<int> arr(n);
      for(int i=0; i<n; ++i) cin >> arr[i];

      int cnt = 0;
      for(int i=n-1; i>=0; --i){
         if(k<arr[i] || k<=0) continue;
         int q = k/arr[i];
         cnt += q;
         k -= q*arr[i];
      }
      cout << cnt;

   return 0;
}