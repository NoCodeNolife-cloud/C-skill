#include <csapp.h>
#define K 1024
#define WRITELEN (128*K)

int main() {
    int result=-1;
    int fd[2],nbytes;
    pid_t pid;
    char string[WRITELEN]="你好，管道";
    char readbuffer[10*K];
    int *write_fd=&fd[1];
    int *read_fd=&fd[0];

    result=pipe(fd);
    if(-1==result){
        printf("建立管道失败\n");
        return -1;
    }

    pid=fork();
    if(-1==pid){
        printf("fork进程失败\n");
        return -1;
    }

    if(0==pid){
        int write_size=WRITELEN;
        result=0;
        close(*read_fd);
        while(write_size>=0){
            result=write(*write_fd,string,write_size);
            if(result>0){
                write_size-=result;
                printf("写入%d个数据，剩余%d个数据\n",result,write_size);
            }else{
                sleep(10);
            }
        }
        return 0;
    }else{
        close(*write_fd);
        while(1){
            nbytes=read(*read_fd,readbuffer,sizeof(readbuffer));
            if(nbytes<=0){
                printf("没有数据写入了\n");
                break;
            }
            printf("接收到%d个数据，内容为：%s\n",nbytes,readbuffer);
        }
    }
    return 0;
}
