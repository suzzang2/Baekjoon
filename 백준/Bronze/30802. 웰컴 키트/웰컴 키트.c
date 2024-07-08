#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int n; scanf("%d", &n);
    
    int arr[6];
    for(int i=0; i<6; i++)
        scanf("%d", &arr[i]);
    
    int t, p; scanf("%d %d", &t, &p);
    
    int tshirts=0, pens=0, pen=0;
    //티셔츠 계산
    for(int i=0; i<6; i++){
        int quotient = arr[i]/t;
        int remain = arr[i]%t;
        
        if(remain == 0) //딱 나누어 떨어지면
            tshirts += quotient;
        else
            tshirts += (quotient+1);
    }
    //펜 계산
    pens = n/p;
    pen = n-pens*p;
    
    //출력부
    printf("%d\n%d %d\n", tshirts, pens, pen);
    
    return 0;
}
