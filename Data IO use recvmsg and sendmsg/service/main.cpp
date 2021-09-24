#include <sys/uio.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888//listening port address
#define BACKLOG 2//listening port length
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

void process_conn_server(int s) {
    char buffer[30];
    ssize_t size = 0;
    struct msghdr msg;

    struct iovec *v = (struct iovec *) malloc(3 * sizeof(struct iovec));
    if (!v) {
        printf("Not enough memory\n");
        return;
    }

    vs = v;

    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_control = NULL;
    msg.msg_controllen = 0;
    msg.msg_iov = v;
    msg.msg_iovlen = 30;
    msg.msg_flags = 0;

    v[0].iov_base = buffer;
    v[1].iov_base = buffer + 10;
    v[2].iov_base = buffer + 20;

    v[0].iov_len = v[1].iov_len = v[2].iov_len = 10;

    while (true) {
        size = recvmsg(s, &msg, 0);
        if (size == 0) {
            return;
        }

        sprintf((char *) v[0].iov_base, "%d ", size);
        sprintf((char *) v[1].iov_base, "bytes alt");
        sprintf((char *) v[2].iov_base, "ogether\n");

        v[0].iov_len = strlen((char *) v[0].iov_base);
        v[1].iov_len = strlen((char *) v[1].iov_base);
        v[2].iov_len = strlen((char *) v[2].iov_base);
        sendmsg(s, &msg, 0);
    }
}

int main(int argc, char *argv[]) {
    int ss, sc;//ss is the socket descriptor of the server, and sc is the socket descriptor of the client
    struct sockaddr_in server_addr;//service address struct
    struct sockaddr_in client_addr;//client address struct
    int err;//error value
    pid_t pid;//fork the id
    signal(SIGINT, sig_proccess);//mount SIGINT signal, the handler function is sig_process
    signal(SIGPIPE, sig_proccess);//mount SIGPIPE signal, the handler function is is_pipe
    ss = socket(AF_INET, SOCK_STREAM, 0);//establish a string socket
    if (ss < 0) {//error
        printf("socket error\n");
        return -1;
    }

    //set service address
    bzero(&server_addr, sizeof(server_addr));//clear
    server_addr.sin_family = AF_INET;//protocol
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//local address
    server_addr.sin_port = htons(PORT);//service port
    err = bind(ss, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (err < 0) {//bind error
        printf("bind error\n");
        return -1;
    }
    err = listen(ss, BACKLOG);//set listening port
    if (err < 0) {//error
        printf("listen error\n");
        return -1;
    }

    while (true) {//main circle
        int addrlen = sizeof(struct sockaddr);//receive client connect
        sc = accept(ss, (struct sockaddr *) &client_addr, (socklen_t *) &addrlen);
        if (sc < 0) {//client connect error
            continue;//end of the circle
        }

        //estanblish a new progress to handle new connect
        pid = fork();//fork progress
        if (pid == 0) {//child progress
            close(ss);//close servise listening in child progress
            process_conn_server(sc);//deal with connect
        } else {
            close(sc);//close client connect in father progress
        }
    }
}