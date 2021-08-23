#include <stdio.h>

void mergeSort(int *vec, int left, int middle, int right) {
    int temp[right-left+1];
    int index = 0;
    int i = left, j = middle + 1;
    while (i <= middle && j <= right) {
        if (vec[i] < vec[j]) {
            temp[index++] = vec[i++];
        } else {
            temp[index++] = vec[j++];
        }
    }
    while (i <= middle) {
        temp[index++] = vec[i++];
    }
    while (j <= right) {
        temp[index++] = vec[j++];
    }
    for (int i = 0; i < sizeof(temp) / sizeof(temp[0]); i++) {
        vec[left + i] = temp[i];
    }
}

void merge(int *vec, int left, int right) {
    if (left == right) {
        return;
    }
    int middle = (left + right) / 2;
    merge(vec, left, middle);
    merge(vec, middle + 1, right);
    mergeSort(vec, left, middle, right);
}

int main() {
    int vec[] = {15, 35, 48, 75, 96, 51, 32, 39, 43, 67, 16};
    merge(vec, 0, sizeof(vec) / sizeof(vec[0])-1);
    for(int i=0;i<sizeof(vec)/sizeof(vec[0]);i++){
        printf("%d ",vec[i]);
    }
    return 0;
}
