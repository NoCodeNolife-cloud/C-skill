#include <csapp.h>

int main() {
    int *array, i, n;

    scanf("%d", &n);
    array = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    free(array);
    exit(0);
}
