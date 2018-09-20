#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    void delay(int);
    int pid;
    sem_t *lock = sem_open("lock", O_CREAT, 0644, 1);
    if (lock == SEM_FAILED) {
        perror("Semaphore borke");
        exit(EXIT_FAILURE);
    }

    setbuf(stdout, NULL);
    if ((pid = fork()) != 0) {
        for (int i = 0; i < 5; i++) {
            sem_wait(lock);
            for (int j = 0; j < 26; j++)
                putchar('a' + j);
            putchar('\n');
            sem_post(lock);
            delay(100000);
        }
    } else {
        for (int i = 0; i < 5; i++) {
            sem_wait(lock);
            for (int j = 0; j < 26; j++)
                putchar('A' + j);
            putchar('\n');
            sem_post(lock);
            delay(100000);
        }
    }

    sem_close(lock);
    return 0;
}

void delay(int max) {
    for (int i = 0; i < max; i++)
        ; /* waste time */
}
