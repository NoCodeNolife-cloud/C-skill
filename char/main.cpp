#include <iostream>

int main() {
    char char_num = 'a';
    printf("%d\n", char_num);/*字符本身*/
    printf("%c\n", char_num);/*ASCII码*/
    char char_uppercase_num = char_num - 32;/*ascii码大写在前*/-
            printf("%c\n", char_uppercase_num);
    char_num = '8';
    printf("%d\n", char_num - '0');
    char_num = 'A';
    printf("%c->%c\n", char_num, char_num + ' ');/*'A'+' '转成小写*/
    scanf("%d", &char_num);
    getchar();
    scanf("%d", &char_uppercase_num);
    printf("%d\n", char_num);
    printf("%d\n", char_uppercase_num);
    return 0;
}
