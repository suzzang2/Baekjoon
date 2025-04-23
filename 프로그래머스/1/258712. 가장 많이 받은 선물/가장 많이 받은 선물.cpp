#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <numeric> 

using namespace std;
int solution(vector<string> friends, vector<string> gifts) {
   //1. 일단 문제처럼 표로 재정리
   int n = friends.size();
   //이름 배열 전처리
   unordered_map<string, int> names;
   for(int i=0; i<n; ++i)
      names[friends[i]] = i;

   vector<vector<int>> arr(n, vector<int>(n, 0));
   for(string gift: gifts){
      istringstream ss(gift);
      vector<string> temp(2);
      ss >> temp[0] >> temp[1];
      arr[names[temp[0]]][names[temp[1]]] += 1;
   }
   //2. 선물지수 계산
   vector<int> scores(n);
   for(int i=0; i<n; ++i){
      //(행-열)
      int row = 0; int column = 0;
      for(int j=0; j<n; ++j){
         row += arr[i][j];
         column += arr[j][i];
      }
      scores[i] = row - column;
      // cout << scores[i] << " ";
   }
   //3. 선물받기 계산
   int max = 0;
   for(int i=0; i<n; ++i){
      int cnt = 0;
      //먼저 서로의 선물 주고받기부터 비교
      for(int j=0; j<n; ++j){
         if(i==j) continue;
         int give = arr[i][j];
         int get = arr[j][i];
         if(give > get){
            // printf("(%d,%d)에서 %d | %d 여서 선물받음!\n", i, j, give, get);
            cnt++;
         } else if(give < get){

         } else{ //같거나 주고 받은 이력이 없을 때
            if(scores[i] > scores[j]) cnt++;
         }
      }
      cout << '\n';
      cout << cnt << " ";
      if(max < cnt)
         max = cnt;
   }
   cout << "\n---\n<result>\n";

   // for(int i=0; i<n; ++i){
   //    for(int j=0; j<n; ++j)
   //       cout << arr[i][j] << " ";
   //    cout << "\n";
   // }
   return max;
}