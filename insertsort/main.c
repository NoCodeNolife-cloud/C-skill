#include <stdio.h>

void insertSort(int *vec, int size) {
    for (int i = 1; i < size; i++) {
        int temp = vec[i];
        int j;
        for (j = i - 1; j >= 0 && vec[j] > temp; j--) {
            vec[j + 1] = vec[j];
        }
        vec[j + 1] = temp;
    }
}

void inser(int *vec,int size){
    for(int i=1;i<size;i++){
        int temp=vec[i];
        int j;
        for(j=i-1;j>=0&&vec[j]<temp;j--){
            vec[j+1]=vec[j];
        }
    }
}

int main() {
    int vec[] = {25, 45, 65, 85, 75, 95, 35, 15, 28, 46, 37, 19};
    insertSort(vec, sizeof(vec) / sizeof(vec[0]));
    for (int i = 0; i < sizeof(vec) / sizeof(vec[0]); i++) {
        printf("%d ", vec[i]);
    }
    return 0;
}
