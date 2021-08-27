#include<unistd.h>
#include<signal.h>
#include<stdio.h>

void handler() {
    printf("Hello\n");
    signal(SIGALRM, handler);
    alarm(5);
}

int main() {
    int i;
    handler();
    for (i = 1; i < 21; i++) {
        printf("sleep %d ...\n", i);
        sleep(1);
    }
}