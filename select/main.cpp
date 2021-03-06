#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set rd;
    struct timeval tv;
    int err;

    FD_ZERO(&rd);
    FD_SET(0, &rd);

    tv.tv_sec = 5;
    tv.tv_usec = 0;
    err = select(1, &rd, NULL, NULL, &tv);

    if (err == -1) {
        perror("select()");
    } else if (err) {
        printf("Data is availbale now.\n");
    } else {
        printf("No data within five second.\n");
    }
    return 0;
}