// If the following program is in a file called prog.c:

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
// $ gcc -E prog.c
// You can ignore the additional directives inserted by the C
// pre-processor.