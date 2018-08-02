// If the following program is in a file called q1.c:

#define LIFE 42
#define VAL random() % 20
#define sq(x) (x * x)
#define woof(y) (LIFE + y)

int main() {
    char s[LIFE];
    int i = woof(5);
    i = VAL;
    return (sq(i) > LIFE) ? 1 : 0;
}

// then what will be the output of the following command:
// $ gcc -E q1.c
// You can ignore the additional directives inserted by the C
// pre-processor.

/* ANSWER:
int main() {
    char s[42];
    int i = (42 + 5);
    i = random() % 20;
    return ((i * i) > 42) ? 1 : 0;
}
*/