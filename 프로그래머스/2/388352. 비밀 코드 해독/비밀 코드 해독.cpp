#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int countCommonElements(const vector<int>& a, const vector<int>& b){
    unordered_set<int> setA(a.begin(), a.end());
    int cnt = 0;
    for(int num: b){
        if(setA.count(num)) cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<int> wholeSet(n);
    for(int i=0; i<n; ++i)
        wholeSet[i] = i + 1;

    vector<bool> select(n, false);
    fill(select.end() - 5, select.end(), true); // 마지막 5개만 true → 5개 선택

    int cnt = 0;

    do {
        vector<int> candidate;
        for (int i = 0; i < n; ++i) {
            if (select[i]) candidate.push_back(wholeSet[i]);
        }

        bool valid = true;
        for (int i = 0; i < ans.size(); ++i) {
            if (countCommonElements(candidate, q[i]) != ans[i]) {
                valid = false;
                break;
            }
        }

        if (valid) cnt++;
    } while (next_permutation(select.begin(), select.end()));

    return cnt;
}