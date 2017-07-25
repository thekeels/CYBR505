.data
array:	.space 80
inputPrompt: .asciiz "Enter a value for array size (0<n<20): "
readNumPrompt: .asciiz "Please enter a number to input into the array: "
forwardArrayPrint: .asciiz "\nThe entered array values are: "
reverseArrayPrint: .asciiz "\nThe reversed array values are: "
spacePrint: .asciiz " "
errorValidity: .asciiz "Error, entered value is outside the valid range.\n\n"
errorNegative: .asciiz "Error, entered value is outside the valid range (negative).\n\n"
errorDivisible: .asciiz "Error, entered value is outside the valid range (not divisible by 3).\n\n"
.text

Begin:
li $v0, 4
la $a0, inputPrompt
syscall
jal readNum
add $a0, $v0, $0 # Store the readNum value in $a0 for sending to verifySize function
sw $v0, 0($sp) # Save the arraysize on stack for use later
jal verifySize
beq $v0, $0, FailValidity # Go to createArray if the validity check 0<n<20 is OK 
lw $a0, 0($sp) # Retrieve array size from stack, store in $a0 for sending to createArray
jal createArray
li $v0, 4
la $a0, forwardArrayPrint
syscall
lw $a0, 0($sp) # Retrieve array size from stack, store in $a0 for sending to printArray
jal printArray
lw $a0, 0($sp) # Retrieve array size from stack, store in $a0 for sending to reverseArray
jal reverseArray
li $v0, 4
la $a0, reverseArrayPrint
syscall
lw $a0, 0($sp) # Retrieve array size from stack, store in $a0 for sending to printArray 
jal printArray
li $v0, 10 # Exit
syscall

######## FailValidity function #############
FailValidity:
li $v0, 4
la $a0, errorValidity
syscall
j Begin

######## FailNegative function #############
FailNegative:
li $v0, 4
la $a0, errorNegative
syscall
j making_array

######## FailDivisible function ############
FailDivisible:
li $v0, 4
la $a0, errorDivisible
syscall
j making_array

######## readNum function ##################
readNum:
li $v0, 5 # Returns the read num in the $v0 register
syscall 
jr $ra # Return to main

######## verifySize function ###############
verifySize:
bgt $a0,19, verifySizeNotOk
blt $a0, 1, verifySizeNotOk
# Return 1 if size is valid
li $v0, 1
jr $ra
verifySizeNotOk:
# Return 0 if size is invalid
li $v0, 0
jr $ra

######## createArray function ##############
# s0 = counter
# s1 = array size
# s2 = user entered array value
# t0 = array base address
# t1 = 4
# t2 = offset from base address (counter * 4)
createArray:
li $s0, 0 # Store counter = 0 in $s0
add $sp, $sp, -4 # Make room on the stack
sw $ra, 0($sp) # Save the return to main address on the stack
add $s1, $a0, $0 # Save the array size in $s1
making_array:
li $v0, 4
la $a0, readNumPrompt
syscall
jal readNum # Go to readNum function to retrieve a user entered array value
add $s2, $v0, $0 # Store the user entered array value in $s2
add $a0, $v0, $0 # Store the user entered array value in $a0 for sending to checkNumPositive function
jal checkNumPositive
beq $v0, $0, FailNegative
jal divisibleBy3
beq $v0, $0, FailDivisible
la $t0, array
li $t1, 4
# Calculate the offset from the base address of the array, and store the value at that location
mult $s0, $t1
mflo $t2
add $t0, $t0, $t2
sw $s2, 0($t0)
# Increment counter
add $s0, $s0,1
blt $s0, $s1, making_array
# Return to main
lw $ra, 0($sp)
add $sp, $sp,4
jr $ra

######## reverseArray function #############
# s0 = head index
# s1 = tail index
# s2 = array base address
# t1 = head index byte offset
# t2 = tail index byte offset
# t3 = head value
# t4 = tail value
reverseArray:
li $s0, 0 # Head index = $s0 = 0
add $s1, $a0, $0 # Tail index = arraySize = $s1
add $s1, $s1,-1
la $s2, array # Base Address of array in $s2
swap:
bgt $s0, $s1, exitReverse
# Calculate the index offset for the head value
add $t1, $s0, $0 # Head ($t1) index = 0
add $t1, $t1,$t1 # Index Head x 2
add $t1, $t1, $t1 # Index Head x 4
add $t1, $s2, $t1
# Calculate the index offset for the tail value
add $t2, $s1,$0 # Tail ($t2) index = array size
add $t2, $t2, $t2 #Index tail x2
add $t2, $t2, $t2 #Index tail x4
add $t2, $s2, $t2
# Perform the swap of head into the tail and tail into the head
lw $t4, 0($t2)
lw $t3, 0($t1)
sw $t4, 0($t1)
sw $t3, 0($t2)
# Increment the head value, decrement the tail value
add $s0, $s0,1
add $s1, $s1,-1
j swap
exitReverse:
jr $ra

######## printArray function ###############
printArray:
# t4 = counter
# t2 = 4
# t1 = array size
# t0 = array base address
# t3 = offset from base address (counter * 4)
li $t4, 0 # Counter stored in $t4
li $t2, 4 # 4 stored in $t2
add $t1, $a0,$0 # Save the array size in $t1
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
# Divide entered value by 3, if remainder = 0, then number is divisible by 3
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
