#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
   int n; cin >> n;
   int ans = 1;
   while(ans<=n){
      int sum = 0;
      int temp = ans;
      while(temp>0){
         int k = temp%10;
         temp = (temp-k)/10;
         sum += k;
      }
      if(sum+ans == n){ cout << ans; return 0; }
      ans++;
   }
   cout << "0";
   return 0;
}