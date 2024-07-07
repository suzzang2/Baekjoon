#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    
    int first, second;
    
    first = a+b-c;
    //b가 a를 곱해주는 기준이 됨
    if(b<10){
        a *= 10;
    }
    else if(b<100){
        a *= 100;
    }
    else if(b<1000){
        a *= 1000;
    }
    else if(b==1000){
        a *= 10000;
    }
    second = a+b-c;
    
    printf("%d\n%d", first, second);

    return 0;
}
