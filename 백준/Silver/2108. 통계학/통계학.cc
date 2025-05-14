#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main(void){
   int n; cin >> n;
   vector<int> arr(8002, 0);
   vector<int> arr4Ctr;
   double sum = 0;
   int minVal = 9999; int maxVal = -9999;
   for(int i=0; i<n; ++i){
      int k; cin >> k;
      arr[k+4000]++; arr4Ctr.push_back(k);
      sum += k;
      minVal = min(minVal, k); maxVal = max(maxVal, k);
   }
   sort(arr4Ctr.begin(), arr4Ctr.end());

   int modeFreq = 0;
   vector<int> modes;
   for(int i = minVal + 4000; i <= maxVal + 4000; ++i){
      if(arr[i] > 0){
         if(arr[i] > modeFreq){
               modeFreq = arr[i];
               modes.clear();
               modes.push_back(i - 4000);
         } else if(arr[i] == modeFreq){
               modes.push_back(i - 4000);
         }
      }
   }

int modeResult = (modes.size() == 1) ? modes[0] : modes[1];

   int avg = round(sum/n);
   cout << avg << "\n";

   cout << arr4Ctr[(n-1)/2] << "\n"; 
   cout << modeResult << "\n";
   cout << maxVal-minVal << "\n";

   return 0;
}