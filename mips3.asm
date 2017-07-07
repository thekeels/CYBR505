.data
inputRequest: .asciiz "How many numbers you like to add together? "
sumResult: .asciiz "The sum of the numbers is "
newline: .asciiz "\n"

.text

main:
# Ask for numbers
li $v0, 4
la $a0, inputRequest
syscall
# Read how many numbers user wants to add
li $v0, 5
syscall
# Save that number in $s0
add $s0, $v0,$0
# Print a new line
li $v0, 4
la $a0, newline
syscall 
 # Set counter ($t0) to 0
add $t0,$t0,$0
loopStart: 
# Go to exit loop if counter = how many numbers user wants to add
beq $t0,$s0, exitLoop
# Read a number to add
li $v0, 5
syscall
# Save the sum in $s1
add $s1,$s1,$v0
addi $t0,$t0,1
# Repeat loop
j loopStart
exitLoop:
# Print new line
li $v0, 4
la $a0, newline
syscall
# Print sum (string)
la $a0, sumResult
syscall
# Print sum (result)
li $v0, 1
add $a0,$s1,$0
syscall

