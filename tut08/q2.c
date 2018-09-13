#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
    int r;
    pid_t pid = fork();
    if (pid == 0) {
        execve("/bin/sh", argv, envp);
        perror("I can't run that");
    } else {
        wait(NULL);
        printf("The child is done!\n");
    }
    return 0;
}