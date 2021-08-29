#include <csapp.h>

int main() {
    int flags=-1;
    int accmode=-1;

    flags=fcntl(0,F_GETFL,0);/*获得标准输入的状态的文件*/
    if(flags<0){/*错误发生*/
        printf("failure to use fcntl\n");
        return -1;
    }

    /*由于3种存取方式(O_RDONLY, O_WRONLY和O_RDWR)并不是各占1位,这3个值分别为0、1、2,要正确地获得它们的值,
     * 只能用O_ACCMODE获得存取位,然后与这3种方式比较。*/
    accmode=flags&O_ACCMODE;/*获得访问模式*/
    if(accmode==O_RDONLY){/*只读*/
        printf("STDIN READ ONLY\n");
    }else if(accmode==O_WRONLY){/*只写*/
        printf("STDIN WRITE ONLY\n");
    }else if(accmode==O_RDWR){/*可读写*/
        printf("STDIN READ WRITE\n");
    }else{/*其他模式*/
        printf("STDIN UNKNOWN MODE\n");
    }

    if(flags&O_APPEND){/*附加模式*/
        printf("STDIN APPEND\n");
    }
    if(flags&O_NONBLOCK){/*非阻塞模式*/
        printf("STDIN NONBLOCK\n");
    }
    return 0;
}
