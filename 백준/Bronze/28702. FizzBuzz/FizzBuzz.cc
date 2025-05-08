#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
   vector<string> arrs(3);
   int answer;
   for(int i=0; i<3; ++i) {
      cin >> arrs[i];
      if(arrs[i][0]-'A' <= 0) { answer = stoi(arrs[i])+3-i; break;}
   }
   if(answer%15 == 0) { cout<<"FizzBuzz"; return 0; }
   else if(answer%3 == 0) { cout<<"Fizz"; return 0; }
   else if(answer%5 == 0) { cout<<"Buzz"; return 0; }
   else { cout<<answer; return 0; }

   return 0;
}