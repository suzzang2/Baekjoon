#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    set<int> S;
    while(n--){
        string act; int num;
        cin >> act;
        if(!(act=="all" || act=="empty")) cin >> num;
        if(act=="add"){
            S.insert(num);
        } else if(act=="remove"){
            S.erase(num);
        }else if(act=="check"){
            if(S.find(num)==S.end()) cout << "0\n";
            else cout << "1\n";
        }else if(act=="toggle"){
            if(S.find(num)==S.end()) S.insert(num);
            else S.erase(num);
        }else if(act=="all"){
            S = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        }else if(act=="empty"){
            S.clear();
        }
    }

    return 0;
}