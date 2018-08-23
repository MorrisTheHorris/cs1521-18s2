# int max(int a[], int length) {
#     if (length == 1)
#         return a[0];
#     else {
#         // find max value in rest of array
#         int max_so_far = max(&a[1], length-1);
#         // check if it's bigger than the first element
#         return (a[0] > max_so_far) ? a[0] : max_so_far;
#     }
# }

max:
    # prologue
    sw    $fp, -4($sp)
    la    $fp, -4($sp)
    sw    $ra, -8($sp)
    sw    $s0, -12($sp)     # s0 to store array, &first segment in $a0
    sw    $s1, -16($sp)     # s1 to store length, comes from $a1
    sw    $s2, -20($sp)
    addi  $sp, $sp, -24

    move  $s1, $a1
    lw    $s0, ($a0)

if_main:
    beq   $s1, 1, base_case         # if (length == 1) do something
recursive_case:
    addi  $a1, $s1, -1              # putting length -1 in second arg
    addi  $a0, $a0, 4
    jal   max
    move  $t0, $v0                  # t0 = max_so_far
                                    # return (a[0] > max_so_far) ? a[0] : max_so_far;
if_return:
    bgt   $s0, $t0, return_a0
return_max_so_far:
    move  $v0, $t0
    j return

return_a0:
    move  $v0, $s0
    j return

base_case:
    move  $v0, $s0
    j return

return:
    # epilogue
    lw      $s2, -16($fp)
    lw      $s1, -12($fp)
    lw      $s0, -8($fp)
    lw      $ra, -4($fp)
    la      $sp, 4($fp)
    lw      $fp, ($fp) 

    jr $ra
