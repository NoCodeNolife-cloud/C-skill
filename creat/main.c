#include <csapp.h>

int main() {
    printf("%d\n", creat("./file.txt", S_IRWXU));
    return 0;
}
