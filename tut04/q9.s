    .data
# char *string = "...."; 
string:
    .asciiz  "...." 
# ...
    .text

    la   $t0, string     # s = &string[0];
    li   $t1, 0
while:
    lb   $t2, ($t0)      # if (*s == 0) goto end_loop
    beq  $t2, $0, end_loop

    addi $t1, $t1, 1     # length++
    addi $t0, $t0, 1     # s++
    j    while           # goto while

end_loop:
#   $t1 contains the length of the string