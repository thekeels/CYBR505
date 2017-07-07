.data
inputRequest: .asciiz "Please input the two numbers?\n\n"
sum: .asciiz "Sum is:\t\t"
difference: .asciiz "Difference is:\t"
product:: .asciiz "Product is:\t"
quotient: .asciiz "Quotient is:\t"
remainder: .asciiz "Remainder is:\t"
newline: .asciiz "\n"

.text


main:
# Request 2 numbers
li $v0, 4
la $a0, inputRequest
syscall
# Read 1st number
li $v0, 5
syscall
# Place number in $s0
add $s0,$v0,$0
# Read 2nd number
li $v0, 5
syscall
# Place number is $s1
add $s1,$v0,$0
# Print new line
li $v0, 4
la $a0, newline
syscall 
# Print sum
la $a0, sum
syscall
# Add numbers
add $t0,$s0,$s1
li $v0, 1
add $a0, $t0, $0
syscall
# Print new line, difference
li $v0, 4
la $a0, newline
syscall 
la $a0, difference
syscall
# Subtract numbers
li $v0, 1
sub $t0, $s0,$s1
add $a0, $t0, $0
syscall
# Print new line, product
li $v0, 4
la $a0, newline
syscall 
la $a0, product
syscall
# Multiply numbers
li $v0,1
mult $s0,$s1
mfhi $t0
mflo $t1
add $a0, $t1, $0
syscall
# Print new line, quotient
li $v0, 4
la $a0, newline
syscall 
la $a0, quotient
syscall
# Divide numbers
li $v0, 1
div $s0,$s1
mfhi $t1
mflo $t0
add $a0, $t0, $0
syscall
# Print new line, remainder
li $v0, 4
la $a0, newline
syscall 
la $a0, remainder
syscall
# Print remainder
li $v0, 1
add $a0, $t1, $0
syscall


