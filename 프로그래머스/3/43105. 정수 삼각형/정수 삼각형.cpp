#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            dp[i][j] = triangle[i][j]; //각 자리의 수로 초기화
        }
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0){            //맨 왼쪽일 때
                dp[i][j] = dp[i-1][0] + triangle[i][j]; continue;
            }
            if(j==i){            //맨 오른쪽일 때
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]; continue;
            }
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    // //dp 출력
    // for(vector<int> row : dp){
    //     for(int num : row){
    //         cout << num << ' ';
    //     }
    //     cout << '\n';
    // }
    //맨 아랫줄에서 max 구하기
    int max = 0;
    for(int i=0; i<n; i++){
        if(dp[n-1][i] > max) max = dp[n-1][i];
    }
    
    return max;
}