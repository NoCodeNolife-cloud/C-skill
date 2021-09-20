#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <string.h>
#include <cctype>

#define PORT 8888
void sys_err(const char * str)
{
    perror(str);
    exit(-1);
}

int main()
{
    //参数1：IPV4
    //参数2：流式协议
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket error");
        exit(-1);
    }

    //端口复用
    int opt = 1;
    int ret = setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    if(ret == -1)
    {
        sys_err("setsockopt error");
    }

    //bind绑定ip和端口
    struct sockaddr_in ser_addr;
    memset(&ser_addr,0,sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(PORT);
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ret = bind(sockfd,(struct sockaddr *)&ser_addr,sizeof(ser_addr));
    if(ret == -1)
    {
        sys_err("bind error");
    }

    //设置监听上限
    ret = listen(sockfd,128);
    if(ret == -1)
    {
        sys_err("listen error");
    }
    printf("accept connecting.....\n");

    struct sockaddr_in cli_addr;
    socklen_t cli_addr_len = sizeof(ser_addr);
    char str[BUFSIZ];
    memset(str,0,sizeof(str));

    char buf[1024];
    memset(buf,0,sizeof(buf));
    int rbytes = 0;
    int wbytes = 0;
    int i = 0;

    //阻塞等带客户端连接
    int connfd = accept(sockfd,(struct sockaddr *)&cli_addr,&cli_addr_len);
    if(connfd == -1)
    {
        sys_err("accept error");
    }

    while(1)
    {
        rbytes = read(connfd,buf,sizeof(buf));
        if(rbytes < 0)
        {
            sys_err("read error");
        }
        else if(rbytes == 0)
        {
            close(connfd);
            return 0;
        }
        else
        {
            for(i = 0;i<rbytes;i++)
            {
                buf[i] = toupper(buf[i]);
            }
        }

        write(STDOUT_FILENO,buf,rbytes);

        wbytes = write(connfd,buf,rbytes);

        sleep(1);
    }

    close(sockfd);
    return 0;
}
