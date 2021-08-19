#include <stdio.h>

int main() {
    char* string="you are my sunshine";
    printf("%s\n",string);
    printf("%s\n","a");
    // printf("%s\n",'a'); invalid 字符串后接\0
    char ch='a';
    printf("%c\n",ch);
    putchar(ch);
    return 0;
}
