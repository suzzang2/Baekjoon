#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;


int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int n; cin>>n;
   deque<int> Q;
   while(n--){
      string str; cin >> str;
      if(str=="push"){
         int x; cin >> x;
         Q.push_back(x);
      } else if(str=="front"){
         if(Q.empty()) cout << "-1\n";
         else cout << Q.front() << "\n";
      } else if(str=="size"){
         cout << Q.size() << "\n";
      } else if(str=="empty"){
         cout << Q.empty() << "\n";
      } else if(str=="back"){
         if(Q.empty()) cout << "-1\n";
         else cout << Q.back() << "\n";
      } else if(str=="pop"){
         if(Q.empty()) cout << "-1\n";
         else{
            cout << Q.front() << "\n";
            Q.pop_front();
         } 
      }
   }

   return 0;
}
