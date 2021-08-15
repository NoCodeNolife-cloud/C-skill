#include <iostream>

int main() {
    int num = 10;
    char char_num = 'a';
    double double_num = 3.14;
    float float_num = 254.23;
    printf("%d\t\t%d\n", num, sizeof(num));
    printf("%c\t\t%d\n", char_num, sizeof(char_num));
    printf("%f\t%d\n", double_num, sizeof(double_num));
    printf("%f\t%d\n", float_num, sizeof(float_num));
    return 0;
}
