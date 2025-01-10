#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // 예외 처리: b가 0이거나 a == b일 때 조합 값은 1
    if (b == 0 || a == b)
        cout << 1 << endl;
    else {
        // 계산
        int child = 1, parent = 1;

        // child = a! / (a-b)!
        // parent = b!
        for (int i = 0; i < b; i++) {
            child *= a - i;     // a, a-1, a-2, ..., a-b+1
            parent *= i + 1;    // 1, 2, 3, ..., b
        }

        cout << child / parent << endl;
    }

    return 0;
}
