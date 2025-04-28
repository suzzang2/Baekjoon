#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

unordered_map<string, int> resultMap;
int maxWin = 0;
vector<int> result;

// A팀, B팀 주사위로 각각 주사위 굴려서 승리횟수 계산
void simulate(vector<vector<int>>& dice, vector<int>& aDice, vector<int>& bDice) {
   int m = dice.size() / 2; // 한 명당 주사위 개수

   // A팀 모든 합 저장
   vector<int> aSums;
   vector<int> aCurrent;
   auto dfsA = [&](auto self, int depth) -> void {
       if (depth == m) {
           int sum = 0;
           for (int num : aCurrent) sum += num;
           aSums.push_back(sum);
           return;
       }
       for (int i = 0; i < 6; ++i) {
           aCurrent.push_back(dice[aDice[depth]][i]);
           self(self, depth + 1);
           aCurrent.pop_back();
       }
   };
   dfsA(dfsA, 0);

   // B팀 모든 합 저장
   vector<int> bSums;
   vector<int> bCurrent;
   auto dfsB = [&](auto self, int depth) -> void {
       if (depth == m) {
           int sum = 0;
           for (int num : bCurrent) sum += num;
           bSums.push_back(sum);
           return;
       }
       for (int i = 0; i < 6; ++i) {
           bCurrent.push_back(dice[bDice[depth]][i]);
           self(self, depth + 1);
           bCurrent.pop_back();
       }
   };
   dfsB(dfsB, 0);

   // 이제 A합 vs B합 비교
   sort(bSums.begin(), bSums.end()); 
   int win = 0;
    for (int a : aSums) {
        win += bSums.end() - upper_bound(bSums.begin(), bSums.end(), a);
    }
   //  cout << "A팀 승리 횟수: " << win << "번" << endl;

    if(maxWin < win){
      maxWin = win;
      result = bDice;
      for(int i=0; i<m; ++i)
         result[i]++;

    }
}
         


vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();

    vector<int> idx(n);
    for (int i = 0; i < n; ++i) idx[i] = i;

    vector<bool> select(n, false);
    fill(select.end() - n/2, select.end(), true);

    do {
      vector<int> aDice, bDice;
      for (int i = 0; i < n; ++i) {
          if (select[i]) aDice.push_back(idx[i]);
          else bDice.push_back(idx[i]);
      }
  
      // cout << "A: ";
      // for(int a : aDice) cout << a+1 << " "; // ✨
      // cout << "| B: ";
      // for(int b : bDice) cout << b+1 << " "; // ✨
      // cout << "\n";
  
      simulate(dice, aDice, bDice);
  
  } while (next_permutation(select.begin(), select.end()));

    return result;
}