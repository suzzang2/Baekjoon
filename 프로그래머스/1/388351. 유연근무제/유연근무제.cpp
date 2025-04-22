#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    //schedules와 timelogs의 길이는 같다.(직원 명 수)
    //day 6, 7은 영향 X
    int cnt = schedules.size(); //일단 직원 명 수로 초기화
    int satIdx = 6-startday; int sunIdx = 7-startday;
    if(satIdx == -1) satIdx = 6;
    for(int i=0; i<schedules.size(); ++i){
        for(int j=0; j<7; ++j){
            if(j==satIdx || j==sunIdx) continue; //토, 일이면 그냥 패스
            int limitTime = schedules[i]+10;
            if(limitTime%100 >= 60) //60분 올림을 넘으면
                limitTime += 40;
            if(limitTime < timelogs[i][j]){ //제 시간에 출근하지 않으면
                cnt--;
                break;
            }
        }
    }

    return cnt;
}