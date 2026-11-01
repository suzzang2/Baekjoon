#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<bool>> check(n+1, vector<bool>(m+1, false));
    //웅덩이 표시
    //Q. 웅덩이가 업는 경우?
    for(vector<int> row : puddles) check[row[1]][row[0]] = true;

    //맨 윗줄이면 무조건 1, but 웅덩이가 있으면 그 다음부터는 0
    //맨 왼쪽이면 무조건 1, but 웅덩이가 있으면 그 다음부터는 0
    dp[1][1] = 1;   // 집 시작값
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 and j==1) continue;
            if(check[i][j] == true) continue;
            dp[i][j] = (dp[i][j-1]+dp[i-1][j])%1000000007;
        }
    }
        
    return dp[n][m];
}