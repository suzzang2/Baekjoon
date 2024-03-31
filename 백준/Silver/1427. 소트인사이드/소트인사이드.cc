#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    
    int n;
    cin>>n;
    
    int arr[1000];
    
    int k=0, t=10, l, c=0;
    while(1){
        l = n%t;
        arr[k] = l; //분리한 거 배열에 앞부터 담아주기
        n -= l;
        c++; //자릿수 업데이트
        
        if(n == 0) //모두 빼주었으면
            break;
        
        n /= 10; //원래 숫자 업데이트
        k++; //배열 위치 업데이트
        
    }

    
    int temp;
    for(int i=0; i<c; i++){
        for(int j=0; j<c-1; j++){
            if(arr[j] < arr[j+1]){
                //swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i<c; i++)
        cout<<arr[i];
    
    
    return 0;
}
