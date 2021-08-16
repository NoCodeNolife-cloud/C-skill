#include <stdio.h>

int main() {
    /**
     * float和double打印时，默认输出6位小数点
     */
    float float_num = 2.13;
    double double_num = 3.14159;
    printf("%.8f\n", float_num);
    printf("%.13f\n", float_num);
    printf("%.15lf\n", double_num);
    printf("%.17lf\n", double_num);
    return 0;
}
