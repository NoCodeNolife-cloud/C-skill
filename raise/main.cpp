#include <iostream>
#include <sys/types.h>
#include <signal.h>

static void function(int _signal){
    if(_signal==SIGALRM){
        printf("receive SIGALRM");
    }
}

int main() {
    signal(SIGALRM,function);
    raise(SIGALRM);
    return 0;
}
