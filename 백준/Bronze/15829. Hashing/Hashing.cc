#include <iostream>
#include <string>

using namespace std;

const int MOD = 1234567891;

int main() {
    int n;
    string str;
    cin >> n >> str;

    long long sum = 0;
    long long power = 1;

    for(int i = 0; i < n; ++i) {
        int num = str[i] - 'a' + 1;
        sum = (sum + num * power) % MOD;
        power = (power * 31) % MOD;
    }

    cout << sum;
    return 0;
}
