#include <stdio.h>

void bubbleSort(int *vec, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int main() {
    int vec[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubbleSort(vec, sizeof(vec) / sizeof(vec[0]));
    for (int i = 0; i < 9; i++) {
        printf("%d", vec[i]);
    }
    return 0;
}
