// Consider the following small C program:

#include <stdio.h>

int main(void) {
    int n = 1234;
    int *p;

    p = &n;
    n++;
    printf("%d\n", *p);
    printf("%p\n", p);
    p++;
    printf("%p\n", p);
    return 0;
}

// If we assume that the variable n has address 0x7654, then what values
// will the program print?

/* ANSWER:
1235
0x7654
0x7658
*/