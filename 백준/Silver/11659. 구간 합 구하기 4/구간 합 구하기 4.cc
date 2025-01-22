#include <iostream>
#include <algorithm> // max 함수 사용을 위한 헤더 포함
using namespace std;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   int N, M;
   cin >> N >> M;

   int Sum[100001] = {};

   for (int i=1; i<=N; i++){
      int temp;
      cin >> temp;
      Sum[i] = Sum[i-1] + temp;
   }

   for (int i=0; i<M; i++){
      int start, end;
      cin >> start >> end;
      cout << Sum[end] - Sum[start-1] << "\n";
   }

   return 0;
}