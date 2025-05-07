#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toString(int time){
    if(0<=time && time<10) return "0"+to_string(time);
    else return to_string(time);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    //모두 파싱
    int cur = stoi(pos.substr(0,2)+pos.substr(3,2));
    int opS = stoi(op_start.substr(0,2)+op_start.substr(3,2)); 
    int opE = stoi(op_end.substr(0,2)+op_end.substr(3,2));
    int video = stoi(video_len.substr(0,2)+video_len.substr(3,2));

    int i=1;
    for(string command: commands){
        cout << i << "번째) ";
        //일단 오프닝 중이면 op_end로 이동
        if(opS<=cur && cur<=opE) {
            cur = opE;
            cout << "오프닝 끝으로 이동\n";
        }
        if(command == "next"){
            //10초 뒤가 비디오 시간을 넘어가면 그냥 비디오 시간으로
            if(cur+10 >= video) cur = video;
            else {
                //50이상이면 특수처리   
                if(cur%100 >= 50) cur += 50;
                else cur += 10;
            }
        } else{ //"prev"
            //10초 전이 00분00초 이전이면 그냥 00분00초로
            if(cur-10 <= 0) cur = 0;
            else {
                //10미만이면 특수처리
                if(cur%100 < 10) cur -= 50;
                else cur -= 10;
            }
        }
        //시간 형태 맞춰주기
        if(cur%100 >= 60) cur += 40;
        cout << cur << "\n";
        i++;
        if(cur>video) cur = video;
    }
    if(opS<=cur && cur<=opE) cur = opE;
    cout << "최종 위치: " << cur << "\n";
    
    //RETURN: 사용자의 입력이 모두 끝난 후 동영상의 위치 "mm:ss" 형식
    int hour = cur/100; int min = cur%100;
    return toString(hour)+":"+toString(min);
}