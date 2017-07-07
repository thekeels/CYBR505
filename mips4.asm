.data
frame: .asciiz "\n=============================================\n"
inputRequest: .asciiz "How many positive numbers that are divisible by 6 do you want to add?\n"
enterNumber: .asciiz "\nEnter a number: "
errorPrint: .asciiz "\n****ERROR: "
errorNegative: .asciiz " is not a positive number. Enter another number.\n"
errorOutOfRange: .asciiz " is not in the range of 1 to 100. Enter another number.\n"
errorNotDivisible: .asciiz " is not divisible by 6. Enter another number.\n"
isDivisible: .asciiz " is divisible by 6\n"
result: .asciiz "\nThe Sum of the positive numbers between 1 and 100 that are divisible by 6, is: "

.text

main:
# Print header and input prompt
li $v0, 4
la $a0, frame
syscall
la $a0, inputRequest
syscall
# Set $s1 to 6 (for division), counter ($s2) to 0, sum accumulator ($s3) to 0
li $s1, 6
li $s2, 0
li $s3, 0
# Get number of inputs from user
li $v0, 5
syscall
# Save numbers to add in $s0
add $s0,$v0,$0
# Loop here to check the counter
checkCounter:
beq $s2, $s0, end
# Prompt for a number
li $v0, 4
la $a0, enterNumber
syscall
# Loop here after errors to retrieve a new number
enterNumberAgain:
# Read a number
li $v0, 5
syscall
# Place read number in ($t0)
add $t0,$v0,$0
# Check if number is negative or out of range
blt $t0, $0, errorNegativeSpot 
bgt $t0, 100, errorOutOfRangeSpot
ble $t0, $0, errorOutOfRangeSpot
# Divide number ($t0) by 6 ($s1)
div $t0,$s1
# Place remainde into $t1
mfhi $t1
# Check if remainder is 0 (if number is divisble by 6)
beq $t1, $0, isDivisibleSpot
# If not divisible by 6, read a new number
j errorNotDivisibleSpot

isDivisibleSpot:
# Print the number
li $v0, 1
add $a0, $t0, $0
syscall
# Display that the number is divisible by 6
li $v0, 4
la $a0, isDivisible
syscall
# Increment counter and add to the sum accumulator
add $s3, $s3, $t0
addi $s2,$s2,1
# Check if number of valid inputs has been reached
j checkCounter

errorNegativeSpot:
# Print error
li $v0, 4
la $a0, errorPrint
syscall
# Print the number
li $v0, 1
add $a0, $t0, $0
syscall
# Print the error message
li $v0, 4
la $a0, errorNegative
syscall
# Read a new number
j enterNumberAgain

errorOutOfRangeSpot:
# Print error
li $v0, 4
la $a0, errorPrint
syscall
# Print the number
li $v0, 1
add $a0, $t0, $0
syscall
# Print the error message
li $v0, 4
la $a0, errorOutOfRange
syscall
# Read a new number
j enterNumberAgain

errorNotDivisibleSpot:
# Print error
li $v0, 4
la $a0, errorPrint
syscall
# Print the number
li $v0, 1
add $a0, $t0, $0
syscall
# Print the error message
li $v0, 4
la $a0, errorNotDivisible
syscall
# Read a new number
j enterNumberAgain

end:
# Print the result
li $v0, 4
la $a0, result
syscall

li $v0, 1
add $a0, $s3, $0
syscall
