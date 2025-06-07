#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int calc(string expr) {
    int sum = 0;
    stringstream ss(expr);
    string token;
    while (getline(ss, token, '+')) {
        sum += stoi(token);
    }
    return sum;
}

int main() {
    string s;
    cin >> s;

    stringstream ss(s);
    string token;
    bool first = true;
    int result = 0;

    while (getline(ss, token, '-')) {
        int val = calc(token);
        if (first) {
            result += val;
            first = false;
        } else {
            result -= val;
        }
    }

    cout << result << '\n';
    return 0;
}
