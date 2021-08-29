#include <csapp.h>

int main() {
    int flags=-1;
    char buf[]="FCNTL";
    int fd=open("test.txt",O_RDWR);
    flags=fcntl(fd,F_GETFL,0);/*获得文件状态*/

    flags=flags|O_APPEND;/*增加状态为可追加*/
    flags=fcntl(fd,F_SETFL,flags);/*将状态写入*/
    if(flags<0){/*错误发生*/
        printf("failure to use fcntl\n");
        return -1;
    }
    write(fd,buf,strlen(buf));/*向文件中写入字符串*/
    close(fd);
    return 0;
}
