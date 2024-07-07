#include <stdio.h>

int main(int argc, const char * argv[]) {
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++) { // test case 만큼 반복
        int h, w, n;
        scanf("%d %d %d", &h, &w, &n);
        
        int floor, room;
        if (n % h == 0) {
            floor = h;
            room = n / h;
        } else {
            floor = n % h;
            room = n / h + 1;
        }

        printf("%d%02d\n", floor, room);
    }

    return 0;
}
