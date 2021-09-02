#include <csapp.h>

int main() {
    pid_t pid, ppid;

    pid = getpid();
    ppid = getppid();

    printf("pid=%d\n", pid);
    printf("ppid=%d\n", ppid);

    return 0;
}
