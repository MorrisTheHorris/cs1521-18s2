    .data
cube: .word slice0, slice1, slice2, slice3
slice0: .word row00, row01, row02, row03
slice1: .word row10, row11, row12, row13
slice2: .word row20, row21, row22, row23
slice3: .word row30, row31, row32, row33

row00: .space 16
row01: .space 16
row02: .space 16
row03: .space 16
row10: .space 16
row11: .space 16
row12: .space 16
row13: .space 16
row20: .space 16
row21: .space 16
row22: .space 16
row23: .space 16
row30: .space 16
row31: .space 16
row32: .space 16
row33: .space 16

    .text
    .globl main
# int cube[4][4][4];

# int nzeroes = 0;
# for (int i = 0; i < 4; i++) {
#     for (int j = 0; j < 4; j++) {
#         for (int k = 0; k < 4; k++) {
#             if (cube[i][j][k] == 0) nzeroes++;
#     }
# }
main:
    