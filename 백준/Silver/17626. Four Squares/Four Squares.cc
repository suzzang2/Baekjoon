#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    q.push(0);
    visited[0] = true;
    
    int steps = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        // 현재 레벨의 모든 노드 처리
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();
            
            // 완전제곱수들을 더해보기
            for (int j = 1; j * j <= n; j++) {
                int next = current + j * j;
                
                if (next == n) {
                    cout << steps + 1 << endl;
                    return 0;
                }
                
                if (next < n && !visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        steps++;
    }
    
    return 0;
}