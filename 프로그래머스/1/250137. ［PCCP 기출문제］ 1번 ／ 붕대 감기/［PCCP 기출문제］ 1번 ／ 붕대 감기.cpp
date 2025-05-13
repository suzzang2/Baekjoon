#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int bTime = bandage[0];
    int secHP = bandage[1];
    int bonusHP = bandage[2];
    int curHP = health;
    int round = attacks[attacks.size()-1][0];
    vector<int> atks(round+1, 0);
    for(vector<int> attack: attacks) atks[attack[0]] = attack[1];

    int keep = 0;
    for(int i=1; i<=round; ++i){
        //공격 있으면
        if(atks[i]){
            curHP -= atks[i];
            keep = 0;
        } else {// 없으면
            curHP += secHP;
            keep++;
            if(keep==bTime){
                curHP += bonusHP;
                keep = 0;
            }
        }
        if(curHP>health) curHP = health;
        if(curHP<=0) return -1;
    }
    
    return curHP;
}