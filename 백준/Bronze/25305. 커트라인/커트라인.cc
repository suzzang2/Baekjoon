#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    
    int n,k;
    cin>>n>>k;
    
    int arr[100000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    
    int i=0, j=0;
    int temp;
    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(arr[j] > arr[j+1]){
                //swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    cout<<arr[n-k];
    
    return 0;
}
