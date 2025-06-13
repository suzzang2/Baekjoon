#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int next, vector<bool>& visited, vector<vector<int>>& edges){
    if(visited[next]) return;
    cout << next << " ";
    visited[next] = true;
    for(int edge: edges[next]){
        dfs(edge, visited, edges);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, v; cin >> n >> m >> v;
    vector<vector<int>> edges(n+1);
    while(m--){
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(vector<int>& arr: edges){ //실제 값을 변경하기 위해서 주소값을 받아야함!!!
        sort(arr.begin(), arr.end());
    }

    //DFS
    vector<bool> visited1(n+1, false);
    dfs(v, visited1, edges);

    cout << "\n";
    //BFS
    queue<int> Q;
    vector<bool> visited2(n+1, false);
    Q.push(v); 
    while(!Q.empty()){
        int cur = Q.front(); 
        Q.pop();
        if(!visited2[cur]){
            cout << cur << " ";
            visited2[cur] = true;
            for(int next: edges[cur]) Q.push(next);
        }
    }

    return 0;
}
