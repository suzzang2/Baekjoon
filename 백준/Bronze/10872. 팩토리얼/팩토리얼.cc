#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int result = 1;
    while(n>0){
        result *= n;
        n--;
    }
    cout << result;

    return 0;
}
