#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int digit = storey % 10;
        int next = (storey / 10) % 10;

        if (digit > 5) {
            answer += 10 - digit;
            storey += 10; // 올림 처리
        } else if (digit < 5) {
            answer += digit;
        } else { // digit == 5
            if (next >= 5) {
                answer += 10 - digit;
                storey += 10;
            } else {
                answer += digit;
            }
        }

        storey /= 10;
    }

    return answer;
}
