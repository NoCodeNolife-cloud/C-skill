#include <csapp.h>

int main() {
    int uid;
    int fd=open("test.txt",O_RDWR);

    uid=fcntl(fd,F_SETOWN,1000);

    uid=fcntl(fd,F_GETOWN);

    printf("uid=%d\n",uid);

    close(fd);
    return 0;
}
