#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <cstdio>

//error handle function
static void display_err(const char *on_what) {
    perror(on_what);
    exit(1);
}

int main() {
    sockaddr_un addr_UNIX;
    const char path[] = "/tmp/local";

    int sock_UNIX = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock_UNIX == -1) {
        display_err("socket()");
    }

    unlink(path);

    memset(&addr_UNIX, 0, sizeof(addr_UNIX));

    addr_UNIX.sun_family = AF_LOCAL;
    strcpy(addr_UNIX.sun_path, path);
    int len_UNIX = sizeof(sockaddr_un);

    int error = bind(sock_UNIX, (sockaddr *) &addr_UNIX, len_UNIX);
    if (error == -1) {
        display_err("bind()");
    }

    close(sock_UNIX);
    unlink(path);

    return 0;
}