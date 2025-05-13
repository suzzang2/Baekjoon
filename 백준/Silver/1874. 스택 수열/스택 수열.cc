#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main(void){
   int n; cin >> n;
   stack<int> S;
   vector<int> arr;
   for(int i=0; i<n; ++i){
      int k; cin >> k;
      arr.push_back(k);
   }

   int num = 1;
   int idx = 0;
   vector<char> result;
   while(true){
      //종료조건
      if(idx>=n) { break; }
      if(!S.empty()){ 
         if(arr[idx]==S.top()){
         S.pop();
         idx++;
         result.push_back('-');
         continue;
         }
         if(arr[idx]<S.top()){ cout << "NO\n"; return 0; }
      }

      if(num<=n){
         S.push(num);
         num++;
         result.push_back('+');
      }
   }

   for(char c: result) cout << c << "\n";

   return 0;
}