#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t sent_fd(int fd,void*data,size_t bytes,int sendfd){
    msghdr msghdr_send;//send message
    iovec iov[1];//vector
    union{
        cmsghdr cm;
        char control[CMSG_SPACE(sizeof(int))];
    }control_un;
    cmsghdr*pcmsghdr=NULL;
    msghdr_send.msg_control=control_un.control;
    msghdr_send.msg_controllen=sizeof(control_un.control);

    pcmsghdr= CMSG_FIRSTHDR(&msghdr_send);
    pcmsghdr->cmsg_len= CMSG_LEN(sizeof(int));
    pcmsghdr->cmsg_level=SOL_SOCKET;
    pcmsghdr->cmsg_type=SCM_RIGHTS;
    *((int*) CMSG_DATA(pcmsghdr))=sendfd;

    msghdr_send.msg_name=NULL;
    msghdr_send.msg_controllen=0;

    iov[0].iov_base=data;
    iov[0].iov_len=bytes;
    msghdr_send.msg_iov=iov;
    msghdr_send.msg_iovlen=1;

    return (sendmsg(fd,&msghdr_send,0));
}

int main(int argc,char*argv[]){
    int fd;
    ssize_t n;

    if(argc!=4){
        printf("socketpair error\n");
    }
    if((fd=open(argv[2],atoi(argv[3])))<0){
        return 0;
    }
    if((n= sent_fd(atoi(argv[1]),(void*)"",1,fd))<0){
        return 0;
    }
    return 0;
}