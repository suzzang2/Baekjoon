#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n+1);
    int units = money.size(); //화폐 종류 수
    dp[0] = 1;
    for(int i=0; i<units; i++){ //화폐 단위(동전)
        for(int j=1; j<=n; j++){ //금액
            if(money[i]>j) continue; //동전 하나가 금액보다 크면 스킵
            dp[j] += dp[j-money[i]];
        }
    }
        
    return dp[n];
}