#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSZ 128

typedef struct msgbuf {
    long mtype;
    char mtext[MSGSZ];
} message_buf;

int main() {
    key_t key = 1234;
    int msgflg = IPC_CREAT | 0666;
    int msqid;
    message_buf buf, rbuf;

    // A 프로세스
    msqid = msgget(key, msgflg);
    buf.mtype = 1;
    strcpy(buf.mtext, "Hello, World!");
    int buf_length = strlen(buf.mtext) + 1;
    msgsnd(msqid, &buf, buf_length, IPC_NOWAIT);

    // B 프로세스
    msqid = msgget(key, msgflg);
    msgrcv(msqid, &rbuf, MSGSZ, 1, 0);
    printf("Received message: %s\n", rbuf.mtext);

    return 0;
}
