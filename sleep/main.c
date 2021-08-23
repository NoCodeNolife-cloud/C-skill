#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid[5];
    int i=0;
    for(int i=0;i<sizeof(pid)/sizeof(pid[0]);i++){
        if((pid[i]=fork())==0){
            printf("%d\n",++i);
            exit(0);
        }
    }
    sleep(5);
    exit(0);
}
