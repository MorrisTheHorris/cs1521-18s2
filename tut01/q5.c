#include <stdio.h>

void f(void);
void g(void);

int main(void) {
    f();f();f();
    g();g();g();
    return 0;
}

void f(void) {
    static int x = 0;
    x++;
    printf("%d\n", x);
}

void g(void) {
    int x = 0;
    x++;
    printf("%d\n", x);
}