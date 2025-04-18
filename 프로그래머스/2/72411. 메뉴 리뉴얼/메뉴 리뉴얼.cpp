#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;



void combine(string& s, int start, string path, int r, vector<pair<string,int>>& comb) {
    if (path.length() == r) {
        //result 배열에 없으면 push_back 하고 count는 1로 초기화, 있으면 count++
        if(find_if(comb.begin(), comb.end(), [&](const pair<string,int>& p) { return p.first == path; }) == comb.end()) { //없으면
            
            comb.push_back({path, 1});
        } else {
            for (auto& p : comb) {
                if (p.first == path) { //있으면
                    p.second++;
                    break;
                }
            }
        }
        return;
    }
    for (int i = start; i < s.size(); ++i) {
        combine(s, i + 1, path + s[i], r, comb);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> result;
    int orderNum = orders.size();
    int courseNum = course.size();

    //일단 orders의 원소각각을 사전 순으로 정렬
    for(int i=0; i<orderNum; ++i)
        sort(orders[i].begin(), orders[i].end());

    for(int i=0; i<courseNum; ++i){
        //course 개수대로 조합 만들어서 리스트에 넣고, orders 순회하면서 개수 세기(없으면 create, 있으면 cnt++)
        vector<pair<string,int>> comb; //first: 코스메뉴문자열, second: 주문한 손님 명수 count
        for(int j=0; j<orderNum; ++j){
            combine(orders[j], 0, "", course[i], comb);
        }
        //comb 출력
        for (const auto& p : comb) {
           cout << p.first << " " << p.second << "\n";
        }
        for (const auto& p : comb) {
            //count가 최대인 것들의 index 찾기
            if (p.second >= 2) {
                //최대값 찾기
                int maxCount = 0;
                for (const auto& q : comb) {
                    if (q.second > maxCount) {
                        maxCount = q.second;
                    }
                }
                //최대값과 같은 것들 result에 추가
                if (p.second == maxCount) {
                    result.push_back(p.first);
                }
            }
        }
        // result 출력
        cout << course[i] << "개 조합 결과: ";
        for (const auto& str : result) {
            cout << str << " ";
        }
        cout << "\n";
    }
    
    // //포함되면 제거
    // for (int i = 0; i < result.size(); ++i) {
    //     for (int j = 0; j < result.size(); ++j) {
    //         if (i == j) continue;

    //         // result[i]의 모든 문자가 result[j] 안에 있으면 제거
    //         if (isSubset(result[i], result[j])) {
    //             result.erase(result.begin() + i);
    //             --i;
    //             break;
    //         }
    //     }
    // }
    //사전순으로 정렬
    sort(result.begin(), result.end());
    
    return result;
}

