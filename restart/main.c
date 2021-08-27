#include <csapp.h>

sigjmp_buf buf;

static size_t sio_strlen(char s[]) {
    int i = 0;

    while (s[i] != '\0')
        ++i;
    return i;
}

ssize_t sio_puts(char s[]) /* Put string */
{
    return write(STDOUT_FILENO, s, sio_strlen(s)); //line:csapp:siostrlen
}

void handler(int sig) {
    siglongjmp(buf, 1);
}

int main() {
    if (!sigsetjmp(buf, 1)) {
        signal(SIGINT, handler);
        sio_puts("starting\n");
    } else {
        sio_puts("restarting\n");
    }
    while (1) {
        sleep(1);
        sio_puts("processing...\n");
    }
    exit(0);
}
