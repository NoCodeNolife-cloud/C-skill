#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

static void sig_handle(int signo) {
    if (SIGSTOP == signo) {
        printf("接收到信号SIGSTOP\n");
    } else if (SIGKILL == signo) {
        printf("接收到信号SIGKILL\n");
    } else {
        printf("接收到信号：%d\n", signo);
    }
}

int main() {
    sighandler_t ret;
    ret = signal(SIGSTOP, sig_handle);
    if (SIG_ERR == ret) {
        printf("为SIGSTOP挂接信号处理函数失败\n");
        return -1;
    }

    ret = signal(SIGKILL, sig_handle);
    if (SIG_ERR == ret) {
        printf("为SIGKILL挂接处理函数失败\n");
        return -1;
    }
    while(1);
}
