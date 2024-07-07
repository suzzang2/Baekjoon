#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int numbers[5];

    scanf("%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]);

    int total=0;
    for(int i=0; i<5; i++){
        total += numbers[i]*numbers[i];
    }

    printf("%d", total%10);

    return 0;
}