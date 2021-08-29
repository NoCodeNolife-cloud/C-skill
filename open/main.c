#include <csapp.h>

int main() {
    int fd = -1;
    char filename[] = "test.txt";
    fd = open(filename, O_RDWR);
    if (-1 == fd) {
        printf("Open file %s failure!, ds:%d\n", filename, fd);
    } else {
        printf("Open file %s success,fd:%d\n", filename, fd);
    }
    return 0;
}
