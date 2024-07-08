#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int a, b, c;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        
        //종료 검사
        if(a==0 && b==0 && c==0)
            return 0;
        
        if(pow(a,2)+pow(b,2) == pow(c,2))
            printf("right\n");
        else if(pow(a,2)+pow(c,2) == pow(b,2))
            printf("right\n");
        else if(pow(c,2)+pow(b,2) == pow(a,2))
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}
