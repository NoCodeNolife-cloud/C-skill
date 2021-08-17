#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void function(){
    printf("%d\n",getpid());
}

int main() {
    printf("%d\n",getpid());
    function();
    return 0;
}
