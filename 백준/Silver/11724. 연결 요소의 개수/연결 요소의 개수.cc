#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n+1);
    while(m--){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool> visited(n+1, false);
    queue<int> Q;
    int cnt = 0;
    int order = 0;
    while(order < n){
        order++;
        // cout << "현재 order: " << order << "\n";
        if(visited[order]) continue;
        cnt++;
        Q.push(order);
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            if(!visited[cur]){
                visited[cur] = true;
                for(int edge: edges[cur]) Q.push(edge);
            }
        }
    }
    cout << cnt;
    return 0;
}
