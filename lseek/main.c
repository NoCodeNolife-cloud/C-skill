#include <csapp.h>

int main() {
    off_t offset=-1;

    int fd=-1;
    char filename[]="test.txt";
    fd=open(filename,O_RDWR);
    if(-1==fd){
        printf("can't open\n");
    }else{
        printf("open success\n");
    }

    offset=lseek(fd,0,SEEK_END);
    char buf[30];
    gets(buf);
    write(fd,buf,strlen(buf));
    if(-1==offset){
        printf("STDIN can't seek\n");
        return -1;
    }else{
        printf("STDIN can seek\n");
    }

    return 0;
}
