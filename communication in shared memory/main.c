#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <string.h>
#include <unistd.h>

static char msg[] = "你好，共享内存\n";
union semun {/*信号量操作的联合结构*/
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main() {
    key_t key;
    int semid, shmid;
    char i, *shms, *shmc;
    struct semid_ds buf;
    int value = 0;
    char buffer[80];
    pid_t p;

    key = ftok("/tmp", 'a');/*生成键值*/
    shmid = shmget(key, 1024, IPC_CREAT | 0604);/*获得内存大小，为1024个字节*/

    union semun sem;/*信号量结构变量*/
    sem.val = 0;/*设置初始值*/

    semid = semget(key, 0, IPC_CREAT | 0666);/*获得信号量的ID*/
    semctl(semid, 0, SETVAL, sem);/*发送命令，建立value个初始值的信号量*/

    p = fork();/*生成子进程*/
    if (p > 0) {/*父进程*/
        shms = (char *) shmat(shmid, 0, 0);/*挂接共享内存*/

        memcpy(shms, msg, strlen(msg) + 1);/*复制内容*/
        sleep(10);/*等待10s*/

        struct sembuf sops = {0, +1, IPC_NOWAIT};/*获得共享内存的信号量*/
        semop(semid, &sops, 1);

        shmdt(shms);/*摘除共享内存*/

        sem.val=0;/*销毁信号量*/
        semctl(semid,0,IPC_RMID,sem);
    }else if(p==0){/*子进程*/
        shmc=(char*)shmat(shmid,0,0);/*挂接共享内存*/

        struct sembuf sops = {0, -1, IPC_NOWAIT};/*减少信号量*/
        semop(semid, &sops, 1);

        printf("共享内存的值为：%s\n",shmc);/*打印信息*/
        shmdt(shmc);/*摘除共享内存*/
    }

    return 0;
}
