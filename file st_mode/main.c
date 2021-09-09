#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    struct stat state;
    char *type, *readok;

    int fd=open("./test.txt",O_RDWR,S_IRUSR);

    if(fd==-1){
        exit(-1);
    }
    stat(fd, &state);

    if (S_ISREG(state.st_mode)) {
        type = "regular";
    } else if (S_ISDIR(state.st_mode)) {
        type = "directory";
    } else {
        type = "other";
    }
    if ((state.st_mode & S_IRUSR)) {
        readok = "yes";
    } else {
        readok = "no";
    }
    printf("type:%s,read:%s\n", type, readok);
    return 0;
}
