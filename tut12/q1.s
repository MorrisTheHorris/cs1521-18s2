# COMP1521 Practice Prac Exam #1
# int lowerfy(char *src, char *dest)

   .text
   .globl lowerfy

# params: src=$a0, dest=$a1
lowerfy:
# prologue
   addi $sp, $sp, -4
   sw   $fp, ($sp)
   la   $fp, ($sp)
   addi $sp, $sp, -4
   sw   $ra, ($sp)
   addi $sp, $sp, -4
   sw   $s0, ($sp)
   addi $sp, $sp, -4
   sw   $s1, ($sp)
   # if you need to save more $s? registers
   # add the code to save them here

# function body
# locals: ...

    li   $s0, 0 # i = 0
    li   $s1, 0 # n = 0
              # ch in $t0
for:
    add  $t0, $a0, $s0
    lb   $t0, ($t0) # ch = src[i]
    beq  $t0, '\0', end_for

if:
    blt  $t0, 'A', end_if
    bgt  $t0, 'Z', end_if
    sub  $t0, $t0, 'A'
    add  $t0, $t0, 'a'
    addi $s1, $s1, 1

end_if:
    add  $t1, $a1, $s0
    sb   $t0, ($t1)
    addi $s0, $s0, 1
    j    for

end_for:
    add  $t1, $a1, $s0
    sb   $0,  ($t1)
    move $v0, $s1



# epilogue
   # if you saved more than two $s? registers
   # add the code to restore them here
   lw   $s1, ($sp)
   addi $sp, $sp, 4
   lw   $s0, ($sp)
   addi $sp, $sp, 4
   lw   $ra, ($sp)
   addi $sp, $sp, 4
   lw   $fp, ($sp)
   addi $sp, $sp, 4
   j    $ra

