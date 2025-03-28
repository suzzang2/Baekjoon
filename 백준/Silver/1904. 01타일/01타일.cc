#include <iostream>
#include <algorithm> 
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int arr[n+1];
    arr[1]=1;
    arr[2]=2;
    for(int i=3; i<n+1; i++){
        arr[i]=(arr[i-1]+arr[i-2])%15746;
    }
    cout<<arr[n];
    
    return 0;
}