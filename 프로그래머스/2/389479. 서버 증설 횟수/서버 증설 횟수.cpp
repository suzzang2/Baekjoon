#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
   // m : 만큼 늘어날 때마다 서버 1대 증설 필요(서버 당 사용자 수)
   // k : 서버의 운영 시간
   vector<int> servers(24, 0);
   int answer = 0;
   for(int i=0; i<24; ++i){
      int extraServer = players[i]/m;
      cout << i << " ~ " << i+1 << ") ";

      cout << "필요: " << extraServer << endl;
      if(extraServer > servers[i]){ //부족하면
         int moreServer = extraServer-servers[i];
         for(int j=i; j<i+k && j<24; ++j){ //서버 운영 시간만큼 증설 모두 반영
            servers[j] += moreServer;//증설 필요한 수만큼 다 더해줌(그 시간동안 유지)
         }
         answer += moreServer;
      }
      for(int n: servers) cout << n << " ";
      cout << "\n";
   }


   return answer;
}