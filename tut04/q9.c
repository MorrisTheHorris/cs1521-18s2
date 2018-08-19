#include <stdio.h>

int main(void) {
    int i = 0;
    
while_loop:
    if (i >= 10) 
        goto end_while_loop;
    printf("%d\n", i);
    i++;
    goto while_loop;
end_while_loop:
    puts("Finished printing!");
    return 0;
}
