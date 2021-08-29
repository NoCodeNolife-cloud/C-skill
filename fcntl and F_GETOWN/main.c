#include <csapp.h>

int main() {
    int uid;
    int fd = open("test.txt", O_RDWR);

    uid = fcntl(fd, F_GETOWN);
    printf("the SIG recv ID is %d\n", uid);

    close(fd);
    return 0;
}
