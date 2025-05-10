#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = i + 1;

    vector<int> result;
    int idx = 0;

    while (!arr.empty()) {
        idx = (idx + k - 1) % arr.size();  // 요세푸스 핵심
        result.push_back(arr[idx]);
        arr.erase(arr.begin() + idx);     // 해당 위치 제거
    }

    cout << "<";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << ">\n";

    return 0;
}
