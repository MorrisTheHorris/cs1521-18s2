//  For each of the following commands, describe what kind of output
//  would be produced:

// gcc -E x.c
// gcc -S x.c
// gcc -c x.c
// gcc x.c

// Use the following simple C code as an example:

#include <stdio.h>
#define N 10

int main(void) {
    char str[N] = {'H', 'i', '\0'};
    printf("%s\n", str);
    return 0;
}

/* ANSWER:
-E Preprocess only; do not compile, assemble or link
-S Compile only; do not assemble or link
-c Compile and assemble, but do not link
*/