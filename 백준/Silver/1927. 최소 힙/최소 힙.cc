#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    map<long long, int> M; // 최소 힙처럼 동작
    while (n--) {
        long long num; cin >> num;
        if (num == 0) {
            if (M.empty()) {
                cout << "0\n";
            } else {
                auto it = M.begin(); // 최소값
                cout << it->first << "\n";
                if (--(it->second) == 0) {
                    M.erase(it);
                }
            }
        } else {
            M[num]++;
        }
    }
    
    return 0;
}
