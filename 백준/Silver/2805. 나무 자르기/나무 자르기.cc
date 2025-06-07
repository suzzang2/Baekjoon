#include <iostream>
#include <vector>

using namespace std;

bool isEnough(int height, vector<int>& trees, int &m) {
    long long total = 0;
    for (int tree : trees) {
        if (tree > height)
            total += (tree - height);
    }
    return total >= m; // 나무 총 길이가 M 이상인가?
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> trees(n);
    int high = 0;
    for(int i=0; i<n; ++i) {
        cin >> trees[i];
        if(high<trees[i]) high=trees[i];
    }

    int low = 0, result = 0;
    while (low <= high) {
        int mid = (low + high) / 2; // 속도 높이려고, 중간부터!
        if (isEnough(mid,trees,m)) { 
            result = mid;      
            low = mid + 1; //왼쪽 하나를 버리기
        } else {
            high = mid - 1; //오른쪽 하나를 버리기
        }
    }
    cout << result;

    return 0;
}
