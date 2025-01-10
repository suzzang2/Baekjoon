#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main() {
   //1 -> 666

   //2 -> 1666
   //6 -> 5666

   //7 -> 6661
   //15 -> 6669

   //16 -> 7666
   //18 -> 9666

   //19 -> 10666
   int n;
   cin >> n;

   //n번째 종말의 수를 발견할 때까지 반복
   int num=665;
   string target = "666";
   int trial = 0;
   while(1) {
      num++;
      //숫자를 문자열로 변환
      string numStr = to_string(num);

      if (numStr.find(target) != string::npos) { //포함되어 있으면, 즉 종말의 수를 발견하면
         trial++;
         if( n == trial )
            break;
      } 
   }  

   cout << num;
   return 0;
}