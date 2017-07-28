.data
array:	.space 40 # Space for 40 byte array
inputPrompt: .asciiz "Input the size of the array: "
outputPrint: .asciiz "The array is: "
enterValue: .asciiz "\Enter value for array element "
colon: .asciiz ": "
space: .asciiz " "
maxPrint: .asciiz "\nMaximum value is: "
sortPrint: .asciiz "\nSorted array is: "
errorOutOfRange: .asciiz "\nError, out of range 1 < n < 11, try again.\n\n"
.text
# Read the array size from the user
main:
li $v0, 4
la $a0, inputPrompt
syscall
li $v0, 5
syscall
# Validity range check on input
bgt $v0, 10, errorOutOfRangeSpot
blt $v0, 2, errorOutOfRangeSpot
add $a0, $v0, $0 # Store n in $a0,$s0 for sending to functions
add $s0, $v0, $0
# Jump to fill an Array of size n
jal FillArray
# Print the Array
li $v0, 4
la $a0, outputPrint
syscall
add $a0, $s0,$0
jal PrintArray
# Find and print the max value of the entered array elements
li $v0, 4
la $a0, maxPrint
syscall
add $a0, $s0,0
jal FindMax
# Sort and print the sorted array
li $v0, 4
la $a0, sortPrint
syscall
add $a0, $s0,0
jal SortArray
add $a0, $s0, $0
jal PrintArray
# Exit
li $v0, 10
syscall

#################################
errorOutOfRangeSpot:
li $v0, 4
la $a0, errorOutOfRange
syscall
j main
### FillArray function ###
FillArray:
add $t0, $a0, $0 # Store array length (n) in $t0
la $s1, array
li $t1, 0 # Store the printing counter in $t1
Loop:
beq $t0, $0, endLoop
# Print the enter prompt
li $v0, 4
la $a0, enterValue
syscall
li $v0,1
add $a0, $t1, $0
syscall
li $v0, 4
la $a0, colon
syscall
# Read user input
li $v0, 5
syscall
# Save the input then index to the next array element
sw $v0, 0($s1)
addi $s1, $s1,4
# Adjust counters
add $t0, $t0, -1
add $t1, $t1,1
j Loop
endLoop:
jr $ra

## PrintArray function ###
PrintArray:
add $t0, $a0, $0 # Counter
la $t1, array
startPrint:
beq $t0, $0, endPrint
# Load the array element to print
lw $t2, 0($t1)
li $v0, 1
add $a0, $t2, $0
syscall
li $v0, 4
la $a0, space
syscall
add $t1, $t1,4 # Index the next array element
add $t0, $t0,-1 # Decrement counter
j startPrint
endPrint:
jr $ra

## FindMax function ###
FindMax:
add $t0, $a0, $0 # Array size, counter
la $t1, array # Array address
li $t3, 0
startMax:
lw $t2, 0($t1) # initialization value
beq $t0, $0, endMax
ble $t2, $t3, lessSpot
greaterSpot:
add $t3, $t2, $0 # set the max
lessSpot:
add $t1, $t1, 4 # Index the next array element
add $t0, $t0,-1 # Decrement counter
j startMax
endMax:
li $v0, 1 # Print the max value
add $a0, $t3, $0
syscall
jr $ra

### Sort Array function ###
SortArray:
li $t0, 0 # i counter
add $s0, $a0, $0 # Store length in $s0
la $s1, array
startiLoop:
beq $t0, $s0, endSort
add $t1,$t0,1 # j = i+1
add $s2, $s1,4 # address of Array[j] (j=i+1)
startjLoop:
beq $t1, $s0, endiLoop
lw $t2, 0($s1) # Value of Array[i]
lw $t3, 0($s2) # value of Array[j]
bgt $t3, $t2 endjLoop
add $t4, $t2, $0 # Load temp = Array[i]
sw $t3, 0($s1)
sw $t2, 0($s2)
endjLoop:
add $s2, $s2,4
add $t1, $t1, 1
j startjLoop
endiLoop:
add $t0,$t0,1
add $s1, $s1,4
j startiLoop
endSort:
jr $ra



