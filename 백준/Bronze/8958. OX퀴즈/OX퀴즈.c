#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    getchar();  // scanf 후 남아있는 개행 문자를 제거

    for (int i = 0; i < n; i++) {
        char str[100];
        int count = 0;
        int score = 0;

        if (fgets(str, sizeof(str), stdin) != NULL) {
            int len = (int)strlen(str);

            for (int j = 0; j < len; j++) {
                if (str[j] == 'O') {
                    count++;
                } else {
                    count = 0; // 초기화
                }

                score += count;
            }

            printf("%d\n", score);
        }
    }

    return 0;
}
