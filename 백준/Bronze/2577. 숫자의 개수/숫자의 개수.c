#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    
    int total = a*b*c;

    //숫자를 문자열로 변환
    char str[20];
    sprintf(str, "%d", total);
    int num = (int)strlen(str); //몇자리수인지

    for (int k = 0; k < 10; k++) {
            int count = 0;
            for (int j = 0; j < num; j++) {
                if (str[j] - '0' == k) {
                    count++;
                }
            }
            printf("%d\n", count);
        }
    
    return 0;
}
