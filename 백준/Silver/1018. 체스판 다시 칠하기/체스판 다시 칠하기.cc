#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main(void){
   int n, m;
   cin >> n >> m; cin.ignore();
   vector<string> arr;
   for(int i=0; i<n; ++i){
      string str; getline(cin, str);
      arr.push_back(str);
   }
   int answer = 999999999;
   //오른쪽으로 이동해가면서
   for (int i = 0; i <= n - 8; ++i) {
      for (int j = 0; j <= m - 8; ++j) {
         int cnt1 = 0, cnt2 = 0;
         for (int x = 0; x < 8; ++x) {
               for (int y = 0; y < 8; ++y) {
                  char expected1 = ((x + y) % 2 == 0) ? 'W' : 'B'; // 시작 W
                  char expected2 = ((x + y) % 2 == 0) ? 'B' : 'W'; // 시작 B

                  if (arr[i + x][j + y] != expected1) cnt1++;
                  if (arr[i + x][j + y] != expected2) cnt2++;
               }
         }
         answer = min({answer, cnt1, cnt2});
      }
   }

   cout << answer;
   return 0;
}