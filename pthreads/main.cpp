#include <iostream>

void *thread(void *vargp) {
    printf("Hello, world!\n");
    return nullptr;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, nullptr, thread, nullptr);
    pthread_join(tid, nullptr);
    return 0;
}
