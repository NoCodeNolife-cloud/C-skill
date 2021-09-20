#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8888
void sys_err(const char * str)
{
    perror(str);
    exit(-1);
}

int main()
{
    //socket建立通信
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket error");
        exit(-1);
    }

    //客户端与服务器建立连接
    struct sockaddr_in ser_addr;
    memset(&ser_addr,0,sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(PORT);
    inet_pton(AF_INET,"127.0.0.1",&ser_addr.sin_addr);
    int ret = connect(sockfd,(struct sockaddr *)&ser_addr,sizeof(ser_addr));
    if(ret == -1)
    {
        sys_err("connect error");
    }

    char buf[1024];
    memset(buf,0,sizeof(buf));
    int wbytes = 0;
    int rbytes = 0;

    while(1)
    {
        fgets(buf,sizeof(buf),stdin);

        wbytes = write(sockfd,buf,strlen(buf));
        if(wbytes < 0)
        {
            sys_err("read error");
        }
        else if(wbytes == 0)
        {
            close(sockfd);
            return 0;
        }

        rbytes = read(sockfd,buf,sizeof(buf));
        if(rbytes < 0)
        {
            sys_err("read error");
        }


        wbytes = write(STDOUT_FILENO,buf,rbytes);
        if(wbytes != rbytes)
        {
            sys_err("write error");
        }
    }

    close(sockfd);
    return 0;
}
