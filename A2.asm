.data
array:	.space 80
inputPrompt: .asciiz "Enter a value for array size (0<n<20): "






.text

main:

Begin:
li $v0, 4
la $a0, inputPrompt
syscall
jal readNum
add $a0, $v0, $0 # Store the readNum value in $a0 for sendingto verifySize function
jal verifySize
add $s0, $v0, $0 # Store the validity check answer in $s0 for later use
add $a0, $s0, $0 # Store the validity check answer in $a0 for sending to createArray function
bne $a0, $0, createArray # Go to createArray if the validity check 0<n<20 is OK 
j Begin
li $v0, 10 # Exit
syscall




######## readNum function ##################
readNum:
li $v0, 5 # Returns the read num in the $v0 register
syscall 
jr $ra # Return to main

######## verifySize function ###############
verifySize:
bgt $a0,19, verifySizeNotOk
blt $a0, 1, verifySizeNotOk
li $v0, 1
jr $ra
verifySizeNotOk:
li $v0, 0
jr $ra
######## createArray function ##############
createArray:
li $t0, 0 ## Store counter = 0 in $t0
sw $ra, 0($sp) # Save the return to main address on the stack, and move the stack pointer
add $sp, $sp,-4
sw $a0, 0($sp) # Save the arraySize for later use on the stack
add $sp, $sp,-4
making_array:
jal readNum # Go to readNum function to retrieve a user entered array value
add $a0, $v0, $0 # Store the user entered array value in $a0 for sending to checkNumPositive function
sw $a0, 0($sp) # Store the user entered array value on the stack for later checking of the validity
add $sp, $sp,-4
jal checkNumPositive
add $t3, $v0, $0 # Store the positive value check in $t3 for use in this create Array function
bne $t3, $0, making_array
lw $a0, 0($sp) # Pull the user entered value off the stack for checking inthe divisibleBy3 function
add $sp, $sp,4 
jal divisibleBy3
# Ended work here


######## reverseArray function #############
reverseArray:

######## printArray function ###############
printArray:

######## divisibleBy3 function #############
divisibleBy3:
sw $ra, 0($sp) # Save the return to main address on the stack, and move the stack pointer
add $sp, $sp,-4
li $t0, 3
div $a0, $t0
# Ended work here


######## checkNumPositive function #########
checkNumPositive:
blt $a0, 0, numPositiveNotOk
li $v0, 1
jr $ra
numPositiveNotOk:
li $v0,0
jr $ra