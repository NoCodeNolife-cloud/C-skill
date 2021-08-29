#include <csapp.h>

int main() {
    int fd=-1,i;
    ssize_t size=-1;
    char buf[10];/*存数据的缓冲区*/

    char filename[]="test.txt";
    fd=open(filename,O_RDONLY);/*打开文件，如果文件不存在，则报错*/
    if(-1==fd){/*文件已经存在*/
        printf("Open file %s failure,fd:%d\n",filename,fd);
    }else{/*文件不存在*/
        printf("Open file %s success,fd:%d\n",filename,fd);
    }
    while(size){
        size=read(fd,buf,10);/*每次读取10个字节数据*/
        if(-1==size){/*读取数据出错*/
            close(fd);/*关闭文件*/
            printf("read file error occurs\n");
            return -1;/*返回*/
        }else{
            if(size>0){
                printf("read %d bytes:",size);/*获得size个字节数据*/
                printf("\'");/*打印引号*/
                for(i=0;i<size;i++){/*将读取的数据打印出来*/
                    printf("%c",*(buf+i));
                }
                printf("\"\n");/*打印引号并换行*/
            }else{
                printf("reach the end of file\n");
            }
        }
    }

    return 0;
}
