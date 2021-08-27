#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid,child_pid;
    pid=getpgrp();
    if((child_pid=fork())==0){
        printf("pid group is %d \n",pid);
        exit(0);
    }
    printf("pid group is %d \n",pid);
    sleep(5);
    return 0;
}
