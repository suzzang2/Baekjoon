#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // 중복 제거

    map<int, int> M;
    for(int i = 0; i < sorted.size(); ++i){
        M[sorted[i]] = i;
    }

    for(int i = 0; i < n; ++i){
        cout << M[arr[i]] << " ";
    }

    return 0;
}
