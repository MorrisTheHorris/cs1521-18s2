    .data
nrows:
    .word 6
ncols:
    .word 12
flag:
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'


    .text
    .globl main
# for (int row = 0; row < nrows; row++) {
#     for (int col = 0; col < ncols; col++)
#         printf("%c", flag[row][col]);
#     printf("\n");
# }

# s0 nrows
# s1 ncols
# t0 row
# t1 col

main:
    # prologue
        # left as excercise to SPIM

    lw   $s0, nrows
    lw   $s1, ncols
    
row_init:
    li   $t0, 0
row_cond:
    bge  $t0, $s0, row_false
row_step:

col_init:
    li   $t1, 0
col_cond:
    bge  $t1, $s1, col_false
col_step:
    # printf("%c", flag[row][col]);
    mul  $t2, $s1, $t0
    add  $t2, $t2, $t1
    mul  $t2, $t2, 1 # nop
    lb   $a0, flag($t2)
    li   $v0, 11
    syscall

    addi $t1, $t1, 1
    j col_cond
col_false:
    li   $a0, 10
    li   $v0, 11
    syscall

    addi $t0, $t0, 1
    j row_cond
row_false:

    # epilogue
        # left as excercise to SPIM
    jr $ra