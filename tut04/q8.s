    .data
x:  .space 4
y:  .space 4
z:  .space 4

    .text

# ...

# set $v0 to ((x*x + y*y) - x*y) * z

lw  $t0, x
lw  $t1, y

mul $t2, $t0, $t0
mul $t3, $t1, $t1
mul $t4, $t0, $t1
add $t5, $t2, $t3
sub $t6, $t5, $t4
lw  $t7, z
mul $v0, $t7, $t6

# less registers solution
lw  $t0, x
lw  $t1, y
mul $v0, $t0, $t0 # v0 = x^2
mul $t0, $t0, $t1 # t0 = xy
mul $t1, $t1, $t1 # t1 = y^2
add $v0, $v0, $t1 # v0 = x^2 + y^2
sub $v0, $v0, $t0 # v0 = x^2 + y^2 - xy
lw  $t0, z
mul $v0, $v0, $t0 # v0 = ((x*x + y*y) - x*y) * z

# less instructions solution
lw      $t0, x
lw      $t1, y
mul     $v0, $t0, $v0 # v0 = xy
sub     $t0, $t0, $t1 # t0 = x-y
mul     $t0, $t0, $t0 # t0 = x^2 + y^2 - 2xy
add     $v0, $v0, $t0 # v0 = x^2 + y^2 - xy
lw      $t0, z
mul     $v0, $v0, $t0 # v0 = ((x*x + y*y) - x*y) * z
