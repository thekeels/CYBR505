.data
frame: .asciiz "\n=============================================\n"
inputRequest: .asciiz "How many positive numbers that are divisible by 6 do you want to add?\n"
enterNumber: .asciiz "\n\nEnter a number: "
errorPrint: .asciiz "\n==>****ERROR: "
errorNotPositive: .asciiz " is not a positive number. Enter another number.\n"
errorNotInRange: .asciiz " is not in the range of 1 to 100. Enter another number.\n"
errorNotDivisible: .asciiz " is not divisible by 6. Enter another number.\n"
isDivisible: .asciiz " is divisible by 6\n"
result: .asciiz "\nThe Sum of the positive numbers between 1 and 100 that are divisible by 6, is: "
newline: .asciiz "\n"

.text

main:
li $v0, 4
la $a0, frame
syscall
la $a0, inputRequest
syscall
# Set counter ($s2) to 0, max ($s3) to 100
li $s2, 0
li $s3, 100
# Load 6 into $s1
li $s1, 6
# Get number of inputs from user
li $v0, 5
syscall
# Save numbers to add in $s0
add $s0,$v0,$0

checkCounter:
beq $s2, $s0, end

li $v0, 4

la $a0, enterNumber
syscall
# Read a number
li $v0, 5
syscall

# Place number in $t0
add $t0,$v0,$0

# Divide number ($t0) by 6
div $t0,$s1
mfhi $t1
# Check if remainder is 0
beq $t1, $0, isDivisibleSpot
blt $t0, $0, errorNegative
bgt $t0, $s3, errorNotInRange
j checkCounter


isDivisibleSpot:
li $v0, 1
add $a0, $t0, $0
syscall

li $v0, 4
la $a0, isDivisible
syscall

add $s1, $s1, $t0
addi $s2,$s2,1
j checkCounter

errorNegative:
li $v0, 4
la $a0, errorNotPositive
syscall
j checkCounter

errorOutOfRange:
li $v0, 4
la $a0, errorNotInRange
syscall
j checkCounter


end:
li $v0, 4
la $a0, result
syscall

li $v0, 1
add $a0, $s1, $0
syscall