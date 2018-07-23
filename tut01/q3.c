// What is the output from the following program and how does it work?
// Try to work out the output without copy-paste-compile-execute.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char* str = "abc123\n";
    char* c;

    for (c = str; *c != '\0'; c++)
        putchar(*c);

    return 0;
}