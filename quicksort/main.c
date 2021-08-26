#include <stdio.h>

void quicksort(int *vec, int left, int right) {
    int temp_left = left;
    int temp_right = right;
    int middle = vec[(temp_left + temp_right) / 2];
    while (temp_left <= temp_right) {
        while (vec[temp_left] < middle) {
            temp_left++;
        }
        while (middle < vec[temp_right]) {
            temp_right--;
        }
        if (temp_left <= temp_right) {
            int temp = vec[temp_left];
            vec[temp_left] = vec[temp_right];
            vec[temp_right] = temp;
            temp_left++;
            temp_right--;
        }
    }
    if (temp_left == temp_right) {
        temp_left++;
    }
    if (temp_left < right) {
        quicksort(vec, temp_right + 1, right);
    }
    if (left < temp_right) {
        quicksort(vec, left, temp_left - 1);
    }
}

int main() {
    int vec[] = {25, 45, 65, 85, 75, 95, 35, 15, 19, 73, 46, 82};
    quicksort(vec, 0, 11);
    for (int i = 0; i < sizeof(vec) / sizeof(vec[0]); i++) {
        printf("%d ", vec[i]);
    }
    return 0;
}
