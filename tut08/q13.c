#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handler(int sig) {
    printf("Qutting because of %d\n", sig);
    exit(EXIT_SUCCESS);
}

void stayAlive(int sig) {
    puts("I can't be killed");
}

int main(int argc, char *argv[]) {
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = &handler;

    struct sigaction act2;
    memset(&act, 0, sizeof(act2));
    act2.sa_handler = &stayAlive;

    sigaction(SIGINT, &act, NULL);
    sigaction(SIGKILL, &act2, NULL);

    while (1)
        sleep(5);
    return 0;
}