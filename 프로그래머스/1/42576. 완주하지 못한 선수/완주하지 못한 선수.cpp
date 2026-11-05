#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    //알파벳 순으로 두 개의 벡터 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int num = completion.size();
    if(num == 0) return participant[0];
    for(int i=0; i<num; i++){
        if(i == num-1) return participant[num];
        if(participant[i]!=completion[i]){
            cout << participant[i] << completion[i];
            return participant[i];
        }
    }
    
    string answer;
    return answer;
}