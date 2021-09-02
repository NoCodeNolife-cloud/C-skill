#include <csapp.h>

int main() {
    int result=-1;/*创建管道结果*/
    int fd[2],nbytes;/*文件描述符，字符个数*/
    pid_t pid;/*PID值*/
    char string[]="你好，管道";
    char readbuffer[80];
    /*文件描述符1用于写，文件描述符0用于读*/
    int *write_fd=&fd[1];/*写文件描述符*/
    int *read_fd=&fd[0];/*读文件描述符*/

    result=pipe(fd);/*建立管道*/
    if(-1==result){/*建立管道失败*/
        printf("建立管道失败\n");
        return -1;
    }

    pid=fork();/*分叉程序*/
    if(-1==pid){/*fork失败*/
        printf("fork进程失败\n");
        return -1;
    }

    if(0==pid){/*子进程*/
        close(*read_fd);/*关闭读端*/
        result= write(*write_fd,string,strlen(string));/*向管道写入字符*/

        return 0;/*子进程终止*/
    }else{/*父进程*/
        close(*write_fd);/*关闭写端*/
        nbytes=read(*read_fd,readbuffer,sizeof(readbuffer));/*从管道读取数值*/
        printf("接收到%d个数据，内容为:\"%s\"\n",nbytes,readbuffer);/*打印结果*/
    }
    return 0;
}
