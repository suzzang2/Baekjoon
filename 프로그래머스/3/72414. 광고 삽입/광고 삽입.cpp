#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int toSeconds(const string& time) {
   int h = stoi(time.substr(0, 2));
   int m = stoi(time.substr(3, 2));
   int s = stoi(time.substr(6, 2));
   return h * 3600 + m * 60 + s;
}
string toTime(int totalSec) {
   int h = totalSec / 3600;
   int m = (totalSec % 3600) / 60;
   int s = totalSec % 60;
   return (h < 10 ? "0" : "") + to_string(h) + ":" +
          (m < 10 ? "0" : "") + to_string(m) + ":" +
          (s < 10 ? "0" : "") + to_string(s);
}


string solution(string play_time, string adv_time, vector<string> logs) {
   int playSec = toSeconds(play_time);
   int advSec = toSeconds(adv_time);
   
   vector<long long> timeline(playSec + 2, 0); // 초 단위 시청자 수

   // 시청자 구간 기록
   for (const string& log : logs) {
       int start = toSeconds(log.substr(0, 8));
       int end = toSeconds(log.substr(9, 8));
       timeline[start]++;
       timeline[end]--;
   }

   // 누적 시청자 수 계산 (1초 단위)
   for (int i = 1; i <= playSec; i++) {
       timeline[i] += timeline[i - 1];
   }

   // 누적 시청 시간 계산 (누적합 2단계)
   for (int i = 1; i <= playSec; i++) {
       timeline[i] += timeline[i - 1];
   }

   // 광고를 삽입할 최적 시간 찾기
   long long maxView = timeline[advSec - 1];
   int maxStart = 0;

   for (int i = advSec; i <= playSec; i++) {
       long long currentView = timeline[i] - timeline[i - advSec];
       if (currentView > maxView) {
           maxView = currentView;
           maxStart = i - advSec + 1;
       }
   }
   cout << toTime(maxStart) ;
   return toTime(maxStart);
}
