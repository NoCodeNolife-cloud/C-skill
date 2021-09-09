#include <csapp.h>
#include <sys/sem.h>

int main() {
    int semid = semget(IPC_PRIVATE,6,IPC_CREAT | 0666);
    for(int i = 0;i < 6;++i){
        semctl(semid,i,SETVAL,1);
    }

    struct sembuf buf[2]={
            {1,1,0},
            {2,1,0}
    };
    semop(semid,buf,2);

    struct semid_ds semidDs;
    semctl(semid,NULL,IPC_STAT,semidDs);
    printf("%d",semidDs.sem_nsems);

    return 0;
}
