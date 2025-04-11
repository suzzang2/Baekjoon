#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    int count = 1;

    // <풀이>
    // 두번째 수의 일이자리수가 짝수이면 2로 나누고, 1이면 1을 제거해준다. 이걸 반복해서.. 종료조건 언제??
    while(true){
        if(b%2 == 0){ //짝수이면
            if(b == 0){ //0이면
                cout << -1;
                return 0;
            }
            b /= 2;
        }
        else if(b%10 == 1) //1로 끝나면
            b = (b-1)/10;
        else if(b == 1) //1이면
            continue; //a도 1이어서 같을 수도 있으니까... 함부로 종료 X
        else{ //1이 아닌 홀수로 끝나면
            cout << -1;
            return 0;
        }
        count++;
        //종료조건
        if(a == b){
            cout << count;
            break;
        }
    }
    

    return 0;
}
