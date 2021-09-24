#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include <signal.h>

#define PORT 8888//listening port address
static int s;
static struct iovec *vs = NULL, *vc = NULL;

void sig_proccess(int signo) {
    printf("Catch a exit signal\n");

    free(vc);
    free(vs);
    _exit(0);
}

void sig_pipe(int sign) {
    printf("Catch a SIGPIPE signal\n");
    //release resource
    free(vc);
    free(vs);
    _exit(0);
}

void sig_process_client(int signo) {//client signal handle callback function
    printf("Catch a exit signal\n");//print information
    close(s);//close socket file
    exit(0);//exit progress
}

void process_conn_client(int s) {
    char buffer[30];
    ssize_t size = 0;

    struct iovec *v = (struct iovec *) malloc(3 * sizeof(struct iovec));
    if (!v) {
        printf("No enough memory\n");
        return;
    }

    vc = v;

    v[0].iov_base = buffer;
    v[1].iov_base = buffer + 10;
    v[2].iov_base = buffer + 20;
    v[0].iov_len = v[1].iov_len = v[2].iov_len = 10;

    int i = 0;
    while (true) {
        size = read(0, v[0].iov_base, 10);
        if (size > 0) {
            v[0].iov_len = size;
            writev(s, v, 1);
            v[0].iov_len = v[1].iov_len = v[2].iov_len = 10;
            size = readv(s, v, 3);
            for (i = 0; i < 3; i++) {
                if (v[i].iov_len > 0) {
                    write(1, v[i].iov_base, v[i].iov_len);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;//server structure of address
    int err;//return value

    if (argc == 1) {
        printf("PLS input server addr\n");
        return 0;
    }
    signal(SIGINT, sig_proccess);//mount sigint signal, the handle function is sig_precess
    signal(SIGPIPE, sig_pipe);//mount sigpipe signal, the handle function is sig_pipe

    s = socket(AF_INET, SOCK_STREAM, 0);//establish a string socket
    if (s < 0) {//error establish the socket
        printf("socket error\n");
        return -1;
    }

    //set the service address
    bzero(&server_addr, sizeof(server_addr));//clear service address
    server_addr.sin_family = AF_INET;//set the protocol to AF_INET
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//IP address is local address in anywhere

    server_addr.sin_port = htons(PORT);//set the service port 8888

    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);//Converts the IP address entered as a string to an integer

    connect(s, (struct sockaddr *) &server_addr, sizeof(struct sockaddr));//connect service

    process_conn_client(s);//client handle
    close(s);//close connect
}