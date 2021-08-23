#include <stdio.h>

void selectSort(int *vec, int len) {
    for (int i = 0; i < len; i++) {
        int maxindex = i;
        for (int j = i + 1; j < len; j++) {
            if (vec[maxindex] < vec[j]) {
                maxindex = j;
            }
        }
        int temp = vec[i];
        vec[i] = vec[maxindex];
        vec[maxindex] = temp;
    }
}

int main() {
    int vec[] = {15, 95, 35, 75, 85, 65, 45, 25, 19, 37, 46, 28};
    int len = sizeof(vec) / sizeof(vec[0]);
    selectSort(vec, len);
    for (int i = 0; i < sizeof(vec) / sizeof(vec[0]); i++) {
        printf("%d ", vec[i]);
    }
    return 0;
}
