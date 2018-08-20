
    .data
M:  .word 1, 2, 3, 4
    .word 3, 4, 5, 6
    .word 5, 6, 7, 8


    .text
    .globl main
main:

    # ...

    li   $a0, 3
    li   $a1, 4
    la   $a2, M
    li   $a3, 2
    jal  change

    # ...



# void change(int nrows, int ncols, int M[nrows][ncols], int factor) {
#     for (int row = 0; row < nrows; row++) {
#         for (int col = 0; col < ncols; col++) {
#             M[row][col] = factor * M[row][col];
#         }
#     }
# }
change:
    # prologue


    # function body


    # epilogue

