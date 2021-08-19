#include <stdio.h>

int main() {
    double num=3.141592653585421;
    printf("%.18f\n",num);
    printf("%18f\n",num);
    printf("%018f\n",num);
    printf("%-f\n",num);
    return 0;
}
