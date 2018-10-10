// COMP1521 18s2 GDB debugging example

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char *str);
char **tokenise(char *str, char *sep);
void freeTokens(char **toks);

int main(int argc, char **argv) {
    char *string;

    string = strdup(argv[1]);
    printf("Input: \"%s\"\n", string);
    trim(string);
    printf("Trimmed: \"%s\"\n", string);
    return 0;
}

// trim: remove leading/trailing spaces from a string
void trim(char *str) {
    int first, last;
    first = 0;
    while (isspace(str[first]))
        first++;
    last = strlen(str) - 1;
    while (isspace(str[last]))
        last--;
    int i, j = 0;
    for (i = first; i <= last; i++)
        str[j++] = str[i];
    str[j] = '\0';
}
