#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // <풀이과정>
    // 1. 회의들을 '끝나는 시간'을 기준으로 오름차순 정렬한다.
    // 2. 그리디 알고리즘으로, 다음으로 가능한 회의 중 가장 빨리 끝나는 것을 선택한다.
    // 3. 위 과정을 반복하여 모든 회의들을 다 썼으면? 종료한다.

    int N;
    cin >> N;

    vector<pair<int, int>> meetings;
    for(int i=0; i<N; i++){
        int start, end;
        cin >> start >> end;
        meetings.push_back({start, end});
    }

    //끝나는 시간을 기준으로, 오름차순으로 정렬(끝나는 시간이 같으면 시작 시작 기준으로 추가 정렬)
    sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first; // 끝나는 시간이 같으면, 시작 시간 오름차순
        return a.second < b.second; // 끝나는 시간 오름차순
    });
    

    int count = 1;
    int curStart = meetings[0].first; int curEnd = meetings[0].second;
    for(int i=1; i<N; i++){
        if(meetings[i].first >= curEnd){
            curStart = meetings[i].first;
            curEnd = meetings[i].second;
            count++;
            // printf("(%d, %d)\n", meetings[i].first, meetings[i].second);
        }
    }
    cout << count;

    return 0;
}
