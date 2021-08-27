#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig){
    printf("Caught SIGINT!\n");
    exit(0);
}

int main(){
    alarm(1);
    signal(SIGALRM,sigint_handler);
    pause();/*wait for the receipt of a signal*/
    return 0;
}
