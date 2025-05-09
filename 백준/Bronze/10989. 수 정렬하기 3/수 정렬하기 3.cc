#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
   int n; cin >> n;
   vector<int> arr(10001, 0);
   for(int i=0; i<n; ++i){
      int x; cin >> x; 
      arr[x]++;
   }
   for(int i=1; i<=10000; ++i){
      while(arr[i]>0){ 
         cout << i << "\n";
         arr[i]--;
      }
   }

   return 0;
}