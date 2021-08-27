#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {
    pid_t pid;

    /*Child sleeps until SIGKILL signal received, the dies*/
    if ((pid = fork()) == 0) {
        pause();/*wait for a signal received*/
        printf("control should never reach here!\n");
        exit(0);
    }

    /*parent sends a SIGKILL signal to a child*/
    kill(pid, SIGKILL);/*SIGKILL means kill the progress right now*/
    sleep(3);
    return 0;
}
