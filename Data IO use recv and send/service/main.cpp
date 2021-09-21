#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <signal.h>
#include <cstring>

#define PORT 8888//listening port address
#define BACKLOG 2//listening port length

void sig_proccess(int signo) {
    printf("Catch a exit signal\n");
    _exit(0);
}

void sig_pipe(int sign){
    printf("Catch a SIGPIPE signal\n");

    //release resource
}

void process_conn_server(int s) {
    ssize_t size = 0;
    char buffer[1024];//the data buffer
    while (true) {//cycle process
        size = recv(s, buffer, 1024, 0);//read data from the socket into the buffer

        if (size == 0) {//no data
            return;
        }
        //build the response character, which is the number of bytes received from the client
        sprintf(buffer, "%d bytes altogether\n", size);
        send(s, buffer, strlen(buffer) + 1, 0);//send to client
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
        sc = accept(ss, (struct sockaddr *) &client_addr, (socklen_t *)&addrlen);
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