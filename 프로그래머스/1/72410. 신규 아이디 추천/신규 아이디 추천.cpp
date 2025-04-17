#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//2단계를 식별하기 위한 함수
bool checkChar(char c){
    if(c<'a' || c>'z'){ //알파벳 소문자가 아니면
        if(c<'0' || c>'9'){ //숫자가 아니면  
            if(!(c=='-' || c=='_' || c=='.')) //빼기, 밑줄, 마침표 중 하나라도 해당되지 않으면
                return false; //모두 아닌 것이므로 false 반환
        }
    }
    return true;
}

string change(string new_id){
    //1) 모든 대문자를 소문자로 치환
    for(int i=0; i<new_id.length(); ++i){
        if(new_id[i]>='A' && new_id[i]<='Z') //대문자이면
            new_id[i] = new_id[i] + ('a'-'A'); //32만큼 더해서 소문자로 변환
    }
    cout << "1단계 후) " << new_id << '\n';
    //2) 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
    for(int i=0; i<new_id.length(); ++i){
        if(!checkChar(new_id[i])){ //해당되지 않는 문자이면
            new_id.erase(i, 1); --i; //Q. 근데 여기서 맨앞문자 지워지면 i가 -1이 될 수도 있다..<<큰 문제인가?
        }
    }
    cout << "2단계 후) " << new_id << '\n';
    //3) 마침표(.)가 2개 이상 연속된 부분을 하나로 치환('..'->'.')
    int i=0;
    while (i < new_id.length() - 1) { // i+1 접근하므로 끝 직전까지만
        if (new_id[i] == '.' && new_id[i + 1] == '.') {
            new_id.erase(i, 1); // 하나 지우고 다시 같은 위치 검사
            // i 그대로
        } else {
            ++i;
        }
    }
    cout << "3단계 후) " << new_id << '\n';
    //4) 마침표(.)가 처음이나 끝에 위치한다면 제거
    if(new_id[0] == '.') new_id.erase(0, 1);
    if(new_id[new_id.length()-1] == '.') new_id.erase(new_id.length()-1, 1);
    cout << "4단계 후) " << new_id << '\n';
    //5) 빈 문자열이라면, "a"를 대입
    if(new_id.empty())
        new_id = "a";
    //6) 길이가 16자 이상이라면, 첫 15자를 제외한(16번째부터) 나머지를 모두 제거
    if(new_id.length()>=16){
        new_id.erase(15); //16번째부터 끝.까.지 삭제
    }
    cout << "5단계 후) " << new_id << '\n';
    //7) 2자 이하이면, 길이가 3이 될 때까지 마지막 문자를 반복해서 끝에 붙임
    if(new_id.length()<=2){
        int c = new_id[new_id.length()-1];
        while(new_id.length()<3)
            new_id.push_back(c);
    }
    cout << "6단계 후) " << new_id << '\n';
    return new_id;
}

string solution(string new_id) {
    while (true) {
        string changed = change(new_id);  // 변형된 결과
        if (new_id == changed)  // 같으면 멈춤
            break;
        new_id = changed;  // 다르면 계속 업데이트
    }
    return new_id;
}