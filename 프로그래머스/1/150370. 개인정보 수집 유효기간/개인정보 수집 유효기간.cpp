#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

string parseDate(int year, int month, int day){
   string sYear, sMonth, sDay;
   sYear = to_string(year);
   if(month < 10) sMonth = "0"+to_string(month);
   else sMonth = to_string(month);
   if(day < 10) sDay = "0"+to_string(day);
   else sDay = to_string(day);
   return sYear+sMonth+sDay;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
   //오늘 날짜 파싱
   today = today.substr(0,4)+today.substr(5,2)+today.substr(8,2);
   cout << "Today : " << today << endl;
   //terms 파싱
   unordered_map<string,int> termMap;
   for(string str: terms) termMap[str.substr(0,1)] = stoi(str.substr(2));
   // for(auto& it: termMap) cout << it.first << " | " << it.second << "\n";

   vector<int> answer;
   for(int i=0; i<privacies.size(); ++i){
      int pYear = stoi(privacies[i].substr(0,4));
      int pMonth = stoi(privacies[i].substr(5,2));
      int pDay = stoi(privacies[i].substr(8,2));
      string type = privacies[i].substr(11);
      //얼마나 더해지는지 정리
      int addYear = termMap[type]/12;
      int addMonth = termMap[type] - addYear*12;
      pYear += addYear; pMonth += addMonth;
      if(pMonth > 12){
         int temp = pMonth/12;
         pMonth -= temp*12;
         pYear += temp;
      }
      pDay--;
      //예외처리
      if(pDay==0) { pDay = 28; pMonth--; }
      string result = parseDate(pYear, pMonth, pDay);
      cout << "Expire: " << result << endl;
      if(today > result) answer.push_back(i+1); 
   }

   //Return: 파기해야 할 개인정보의 번호 배열(오름차순)
   return answer;
}