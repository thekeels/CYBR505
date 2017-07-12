.data
inputPrompt:	.asciiz "Enter an integer value betweem 0-10? "
errorMessage:	.asciiz "===>****ERROR: "
errorOutOfRange:	.asciiz " is not within range. Enter another number.\n"
factorial:	.asciiz "! = "

.text

main:
# Prompt user for input
li $v0,4
la $a0, inputPrompt
syscall
# Read input from user, store in $s0
loopStart:
li $v0,5
syscall
add $s0,$v0,$0 # $s0 contains the integer n
# Range check 0 < n < 10, if in range, jump to factorial function
bgt $s0,10,errorOutOfRangeSpot
blt $s0,$0,errorOutOfRangeSpot
j factorialSpot
# If out of range, print error message, and return to get user input
errorOutOfRangeSpot:
li $v0,4
la $a0,errorMessage
syscall
li $v0,1
add $a0,$s0,$0
syscall
li $v0, 4
la $a0, errorOutOfRange
syscall
j loopStart
# Start factorial function, load initial conditions
factorialSpot:
# Print factorial "n! = " to screen
li $v0, 1
add $a0, $s0, $0
syscall
li $v0, 4
la $a0, factorial
syscall
# Set counter to 0, start value to 1, and variable to hold factorial result to 1
li $t0, 0  # %t0 contains counter, starting at 0
li $t1, 1 # $t1 contains 1
li $t2, 1 # $t2 contains factorial result
factorialLoopSpot:
# Repeat this loop until counter($t0) = n ($s0)
beq $t0, $s0, end
# Multiply factorial result, then increment by 1
mult $t2 $t1
mflo $t2
addi $t1, $t1,1
addi $t0,$t0,1
j factorialLoopSpot
end:
# Print result to screen
li $v0, 1
add $a0, $t2, $0
syscall


