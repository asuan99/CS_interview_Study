#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main(void) {
    int shmid;
    char* shmaddr;
    char str[SIZE];
    
    // 1. 공유 메모리 생성 및 메모리 주소 얻기
    if ((shmid = shmget((key_t)1234, SIZE, IPC_CREAT|0666)) == -1) {
        perror("shmget failed");
        exit(1);
    }
    if ((shmaddr = shmat(shmid, (void*)0, 0)) == (char*)-1) {
        perror("shmat failed");
        exit(1);
    }
    
    // 2. 공유 메모리에 쓰기
    strcpy(str, "Linux Programming");
    memcpy(shmaddr, str, strlen(str) + 1);
    
    // 3. 공유 메모리 읽기
    printf("%s\n", (char*)shmaddr);
    
    // 공유 메모리 해제
    if (shmdt(shmaddr) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl(IPC_RMID) failed");
        exit(1);
    }
    
    return 0;
}
