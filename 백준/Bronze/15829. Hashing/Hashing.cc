#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
   int n; string str;
   cin >> n; cin >> str;

   int sum=0;
   //알파벳을 숫자로 매핑
   for(int i=0; i<n; ++i){
      int num = str[i]-'a'+1;
      sum += num*pow(31,i);
   }
   cout << sum;
   return 0;
}