#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

void makeCases(string key, int depth, vector<string>& fields, unordered_map<string, vector<int>>& infoMap, int score) {
    //4개 조합이 모두 완성되면 push하고 종료
    if (depth == 4) {
        infoMap[key].push_back(score);
        return;
    }

    //원래 특성 쓰거나, '-' 쓰거나 두가지 경우를 재귀로
    makeCases(key + "-", depth + 1, fields, infoMap, score);
    makeCases(key + fields[depth], depth + 1, fields, infoMap, score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    unordered_map<string, vector<int>> map;
    vector<int> result;
    
    for(string line : info){
        istringstream ss(line);
        vector<string> fields(5);
        ss >> fields[0] >> fields[1] >> fields[2] >> fields[3] >> fields[4];
        int score = stoi(fields[4]);
        fields.pop_back(); // key 조합 만드느데 쓰이면 안되기 때문에 제외
        makeCases("", 0, fields, map, score);
    }
    //이거 끝나면 이제 map 조합들이 완성된 상태이다.
    //점수 배열을 내림차순으로 정렬(오름차순??)
    for(auto& [key, arr] : map) {
        sort(arr.begin(), arr.end());
    }

    //이제 query 조건을 만족하는 것들 개수 찾기
    for(int i=0; i<query.size(); ++i){
        istringstream ss(query[i]);
        vector<string> fields(8);
        //0, 2, 4, 6, 7(점수)에 값이 들어감
        ss >> fields[0] >> fields[1] >> fields[2] >> fields[3] >> fields[4] >> fields[5] >> fields[6] >> fields[7];
        string key = fields[0]+fields[2]+fields[4]+fields[6];

        vector<int> scores = map[key];
        auto it = lower_bound(scores.begin(), scores.end(), stoi(fields[7]));
        int cnt = scores.end() - it;
        result.push_back(cnt);
    }

    return result;
}