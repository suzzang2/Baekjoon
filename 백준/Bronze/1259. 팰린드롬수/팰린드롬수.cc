#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main() {
   // 줄바꿈을 기준으로 벡터에 문자열 입력받기, 0을 입력받으면 종료
   vector<string> vec;
   while (true) {
      string str;
      getline(cin, str);
      if (str == "0") break;
      vec.push_back(str);
   }

   // 벡터 길이
   int vecLen = vec.size();

   // 팰린드롬 확인
   for (int i = 0; i < vecLen; i++) {
      string currentStr = vec[i];  // 현재 문자열
      int strlen = currentStr.length();
      bool check = true;  // 각 문자열마다 팰린드롬을 체크할 때마다 초기화

      // 홀수, 짝수를 나눠서 검사
      if (strlen % 2 != 0) {
         // 1) 홀수일 때
         for (int j = 0; j < (strlen - 1) / 2; j++) {
            if (currentStr[j] != currentStr[strlen - (j + 1)]) {
               check = false;
               break;  // 한 번이라도 다르면 더 이상 비교할 필요 없음
            }
         }
      } else {
         // 2) 짝수일 때
         for (int j = 0; j < strlen / 2; j++) {
            if (currentStr[j] != currentStr[strlen - (j + 1)]) {
               check = false;
               break;  // 한 번이라도 다르면 더 이상 비교할 필요 없음
            }
         }
      }

      // 결과 출력
      if (check) {
         cout << "yes" << endl;
      } else {
         cout << "no" << endl;
      }
   }

   return 0;
}
