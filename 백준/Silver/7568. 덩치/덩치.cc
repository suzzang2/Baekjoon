#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    
    int n;
    cin>>n;
    
    int arr[100][2];
    
    for(int i=0; i<n; i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    
    int comparr[100]={0}; //더 큰 덩치의 수
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][0]<arr[j][0] && arr[i][1]<arr[j][1]){
                //cout<<i<<"카운트"<<endl;
                comparr[i]++;
            }
        }
    }
    
    //cout<<"결과 : ";
    for(int i=0; i<n; i++)
        cout<<comparr[i]+1<<" ";
    
    return 0;
}
