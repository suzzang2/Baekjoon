#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    sort(A.begin(), A.end());

    int m; cin >> m;
    while (m--) {
        int k; cin >> k;
        cout << binary_search(A.begin(), A.end(), k) << "\n";
    }

    return 0;
}
