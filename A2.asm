.data
array:	.space 80
inputPrompt: .asciiz "Enter a value for array size (0<n<20): "
arrayPrint: .asciiz "\nThe array values are: "
spacePrint: .asciiz " "




.text

main:

Begin:
li $v0, 4
la $a0, inputPrompt
syscall
jal readNum
add $a0, $v0, $0 # Store the readNum value in $a0 for sending to verifySize function
sw $v0, 0($sp) # Save the arraysize on stack for use later
jal verifySize

add $a0, $v0, $0 # Store the validity check answer in $a0 for sending to createArray function
beq $v0, $0, Begin # Go to createArray if the validity check 0<n<20 is OK 
lw $s0, 0($sp) # Retrieve array size from stack
add $a0, $s0,$0 # Store the array size in $a0 for sending to createArray
jal createArray
lw $s0, 0($sp)
add $a0, $s0, $0 # Store the array size in $a0 for sending to printArray
jal printArray
lw $s0, 0($sp)
add $a0, $s0, $0 # Store the array size in $a0 for sending to reverseArray
jal reverseArray
lw $s0, 0($sp)
add $a0, $s0, $0 # Store the array size in $a0 for sending to printArray
jal printArray
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
li $s0, 0 ## Store counter = 0 in $s0
add $sp, $sp, -4 # Make room on the stack
sw $ra, 0($sp) # Save the return to main address on the stack
add $s1, $a0, $0 # Save the array size in $s1
making_array:
jal readNum # Go to readNum function to retrieve a user entered array value
add $s2, $v0, $0 # Store the user entered array value in $s2
add $a0, $v0, $0 # Store the user entered array value in $a0 for sending to checkNumPositive function
jal checkNumPositive
beq $v0, $0, making_array
jal divisibleBy3
beq $v0, $0, making_array
la $t0, array
li $t1, 4
mult $s0, $t1
mflo $t2
add $t0, $t0, $t2
sw $s2, 0($t0)
add $s0, $s0,1
blt $s0, $s1, making_array
lw $ra, 0($sp)
add $sp, $sp,4
jr $ra

######## reverseArray function #############
reverseArray:
li $t0, $0 # Head index = 0
add $s0, $a0, $0 # Tail index = arraySize = $s0
swap:
bgt $t0, $s0, exitReverse

la $s1, array # Base Address of array in $t0
add $t1, $s0, $0 # Tail ($t1) = arraySize
add $t1, $t1,$t1 # Index Tail x 2
add $t1, $t1, $t1 # Index Tail x 4

add $t2, $t0,$0 #Head $t2 index
add $t2, $t2, $t2 #Index head x2
add $t2, $t2, $t2 #Index head x4

add $t0, $t0,1
add $s0, $s0,-1
j swap:
exitReverse:
jr $ra
######## printArray function ###############
printArray:
li $t4, 0 # Counter stored in $t4
li $t2, 4 # 4 stored in $t2
add $t1, $a0,$0 # Save the array size in $t1
li $v0, 4
la $a0, arrayPrint
syscall
printArrayloop:
la $t0, array # Save the base address in $t0
mult $t4,$t2 # offset calculated
mflo $t3 # Offset stored in $t3
add $t0, $t0,$t3 # Add offset to array base address
lw $a0, 0($t0) # Load array value
li $v0, 1
syscall
li $v0, 4
la $a0, spacePrint
syscall
add $t4, $t4, 1 # Add 1 to counter
blt $t4, $t1, printArrayloop
jr $ra


 
######## divisibleBy3 function #############
divisibleBy3:
li $t0, 3
div $a0, $t0
mfhi $t1
beq $t1, $0, divisibleBy3OK
li $v0,0
jr $ra
divisibleBy3OK:
li $v0,1
jr $ra


######## checkNumPositive function #########
checkNumPositive:
blt $a0, 0, numPositiveNotOk
li $v0, 1
jr $ra
numPositiveNotOk:
li $v0,0
jr $ra
