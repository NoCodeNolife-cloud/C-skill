#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdarg.h>

//!server ip
#define SERVER_IP     "127.0.0.1"
//!server bind port default
#define SERVER_PORT    11111

//macros for simple log
#define log_msg(level, fmt, ...)   do { fprintf(stderr,"[%s][%s %s - line:%d]" fmt"\n",level,__DATE__,__TIME__,__LINE__,##__VA_ARGS__);}while (0);

#define debug(fmt, ...)          log_msg("DEBUG",fmt,##__VA_ARGS__)
#define info(fmt, ...)           log_msg("INFO ",fmt,##__VA_ARGS__)
#define warn(fmt, ...)           log_msg("WARN ",fmt,##__VA_ARGS__)
#define error(fmt, ...)          log_msg("ERROR",fmt,##__VA_ARGS__)

//create an socket and liten at the specified port
int create_and_listen(const char *szIP, uint16_t nPort) {
    //socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        error("socket failed,errno=%d", errno);
        return -1;
    }

    //addr structure
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_addr.s_addr = inet_addr(szIP);
    sa.sin_port = htons(nPort);
    sa.sin_family = AF_INET;

    //rause the addr
    int rause = 1;
    int optlen = 4;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char *) &rause, optlen) == -1) {
        error("setsockopt failed,errno=%d", errno);
        close(server_fd);
        return -1;
    }

    //bind
    if (bind(server_fd, (struct sockaddr *) &sa, sizeof(sa)) == -1) {
        error("bind failed,errno=%d", errno);
        close(server_fd);
        return -1;
    }

    //listen
    if (listen(server_fd, 15) == -1) {
        error("listen failed,errno=%d", errno);
        close(server_fd);
        return -1;
    }

    info("create_and_listen end ,server_fd=%d", server_fd);

    return server_fd;
}

//handle client request
int doClient(int client_fd) {
    struct sockaddr_in client_sa;
    memset(&client_sa, 0, sizeof(client_sa));
    socklen_t socklen = 0;
    //getpeername
    if (getpeername(client_fd, (struct sockaddr *) &client_sa, &socklen) == -1) {
        error("getpeername failed,client_fd=%d,errno=%d", client_fd, errno);
        return -1;
    }
    char buf[1024] = {0};
    int read_size = 0;
    int send_size = 0;
    read_size = recv(client_fd, buf, sizeof(buf) - 1, 0);
    if (read_size < 0) {
        info("read failed,client_fd", client_fd);
    } else if (read_size == 0) {
        info("read EOF,client_fd", client_fd);
    } else {//size>0
        send_size = send(client_fd, buf, read_size, 0);
        if (send_size == read_size) {
            info("recv and echo msg success,msg=%s", buf);
        } else {
            error("send failed,read_size=%d,send_size=%d,msg=%s", read_size, send_size, buf);
        }
    }
    close(client_fd);
    return 0;
}

int main(int argc, char *argv[]) {
    const char *szIP = SERVER_IP;
    uint16_t nPort = SERVER_PORT;
    int server_fd = create_and_listen(szIP, nPort);
    if (server_fd < 0) {
        exit(0);
    }

    //main loop
    while (1) {
        struct sockaddr_in client_sa;
        socklen_t socklen = 0;
        int client_fd = accept(server_fd, (struct sockaddr *) &client_sa, &socklen);
        if (client_fd < 0) {
            error("accept failed ,client_fd=%d ,errno=%d", client_fd, errno);
            break;
        }
        info("accept from client, socket=%d,ip=%s,port=%d", client_fd,
             inet_ntoa(client_sa.sin_addr), ntohs(client_sa.sin_port));
        //handle the request 
        doClient(client_fd);
    }

    info("[main] end");
    //close
    close(server_fd);
    return 0;
}