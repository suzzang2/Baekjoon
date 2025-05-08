#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
   int a, b;
   cin >> a >> b;

   int a2 = a, b2 = b;
   int cDiv=max(a,b), cMul;
   //최대공약수
   while(1){
      if(a%cDiv==0 && b%cDiv==0) break;
      cDiv--;
   }
   //최소공배수
   while(1){
      if(a2 > b2) b2 += b;
      else if(a2 < b2) a2 += a;
      else { cMul = a2; break; }
   }
   printf("%d\n%d", cDiv, cMul);
}