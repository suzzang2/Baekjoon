#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 정렬 기준을 위한 비교 함수
bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n; // 숫자의 개수 입력
    vector<string> numbers(n);

    // 숫자 리스트 입력
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // 정렬 (문자열 비교 기준)
    sort(numbers.begin(), numbers.end(), compare);

    // 결과 연결
    string result = "";
    for (const string& num : numbers) {
        result += num;
    }

    // "0"으로 시작하는 경우 처리
    if (result[0] == '0') {
        result = "0";
    }

    cout << result << endl;
    return 0;
}
