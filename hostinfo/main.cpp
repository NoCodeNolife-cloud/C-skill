#include <iostream>
#include <netdb.h>
#include <cstring>

const int MAXLINE = 1024;

int main() {
    char* argv="baidu.com";

    addrinfo *p, *listp, hints;
    char buf[MAXLINE];
    int rc, flags;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((rc = getaddrinfo(argv, nullptr, &hints, &listp)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
        exit(1);
    }

    flags = NI_NUMERICHOST;
    for (p = listp; p; p = p->ai_next) {
        getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
        printf("%s\n", buf);
    }

    freeaddrinfo(listp);

    exit(0);
}
