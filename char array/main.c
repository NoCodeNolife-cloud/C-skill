#include <stdio.h>

int main() {
    char arr[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("%s", arr);

    printf("\n");

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%c", arr[i]);
    }
    return 0;
}
