#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char *msg = "Hello Child Process";
    size_t MSGSIZE = strlen(msg);
    char buf[255];
    int fd[2], pid, nbytes;

    if (pipe(fd) < 0) // pipe(fd)로 파이프 생성
        exit(1);

    pid = fork(); // 이 함수 실행 다음 코드부터 부모/자식 프로세스로 나눠짐

    if (pid > 0) { // 부모 프로세스는 pid에 실제 프로세스 ID가 들어감
        write(fd[1], msg, MSGSIZE); // fd[1]에 씀(write 파일 디스크립터)
    }
    else { // 자식 프로세스는 pid가 0이 들어감
        nbytes = read(fd[0], buf, MSGSIZE); // fd[0]으로 읽음(read 파일 디스크립터)
        printf("%d %s\n", nbytes, buf);
        exit(0);
    }

    return 0;
}
