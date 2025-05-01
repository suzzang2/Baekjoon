#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int row;
    if(num%w == 0) row = num/w;
    else row = num/w + 1;
    
    cout << "row: " << row << endl;

    int upperNum;
    int answer = 0;
    while(num <= n){
        cout << num << endl;
        int sum = 2*row*w + 1;
        cout << "sum: " << sum << "\n";
        num = sum - num;
        row++; answer++;
    }
 
    return answer;
}
