#include <stdio.h>

int main() {
    int num[4][5];
    for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
        for (int j = 0; j < sizeof(num[0]) / sizeof(num[0][0]); j++) {
            num[i][j] = i * j;
            printf("%d ", *(*(num + i) + j));
        }
        printf("\n");
    }

    return 0;
}
