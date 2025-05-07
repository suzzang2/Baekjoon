#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
   //첫번째는 비동의, 두번째는 동의
   //Return: 검사자의 최종 성격 유형
   unordered_map<string, int> mmap = {
      {"AN", 0}, {"NA", 0}, {"CF", 0}, {"FC", 0}, {"RT", 0}, {"TR", 0}, {"MJ", 0}, {"JM", 0}
   };
   for(int i=0; i<survey.size(); ++i){
      int num = choices[i]-4;
      mmap[survey[i]] += num;
   }
   //최종 map 출력
   // for(auto& it: mmap) cout << it.first << " | " << it.second << "\n";
   // cout << "\n";
   //최종 계산
   unordered_map<string, int> result;
   result["RT"] = mmap["RT"]-mmap["TR"];
   result["CF"] = mmap["CF"]-mmap["FC"];
   result["JM"] = mmap["JM"]-mmap["MJ"];
   result["AN"] = mmap["AN"]-mmap["NA"];
   // for(auto& it: result) cout << it.first << " | " << it.second << "\n";
   // cout << "\n";
   
   string answer(4, ' ');  // 길이 4짜리 빈 문자열
   for (auto& it : result) {
       int loc;
       if (it.first == "RT") loc = 0;
       else if (it.first == "CF") loc = 1;
       else if (it.first == "JM") loc = 2;
       else if (it.first == "AN") loc = 3;
   
       if (it.second > 0)
           answer[loc] = it.first[1];
       else
           answer[loc] = it.first[0];
   }
   
   return answer;  // 이미 string
}