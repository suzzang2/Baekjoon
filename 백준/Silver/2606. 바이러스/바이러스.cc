#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void){
     ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int n; cin >> n;
      int k; cin >> k;
      vector<vector<int>> graph(n+1);
      while(k--){
         int a, b; cin >> a >> b;
         graph[a].push_back(b);
         graph[b].push_back(a);
      }

      //bfs?
      queue<int> q;
      q.push(1);
      vector<bool> visited(n+1, false);

      while(!q.empty()){
         int cur = q.front();
         q.pop();
         for(int next: graph[cur]){
            if(!visited[next]){
               q.push(next);
               visited[next] = true;
            }
         }
      }

      int cnt = 0;
      for(int i=2; i<visited.size(); ++i) {
         if(visited[i]) cnt++;
      }
      cout << cnt;
   
   return 0;
}