#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include <signal.h>

#define PORT 8888//listening port address
static int s;

void sig_proccess(int signo) {
    printf("Catch a exit signal\n");
    _exit(0);
}

void sig_pipe(int signo) {
    printf("Catch a SIGPIPE signal\n");
}

void sig_process_client(int signo) {//client signal handle callback function
    printf("Catch a exit signal\n");//print information
    close(s);//close socket file
    exit(0);//exit progress
}

void process_conn_client(int s) {
    ssize_t size = 0;
    char buffer[1024];
    while (true) {
        size = read(0, buffer, 1024);
        if (size > 0) {
            send(s, buffer, size, 0);
            size = recv(s, buffer, 1024, 0);
            write(1, buffer, size);
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