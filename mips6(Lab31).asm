.data 
array: .space 40

inputRequest: .asciiz "Enter the number of elements:\n"
errorOutOfRange: .asciiz "Error array can't have more than 10 elements, try again!!"
errorNegative: .asciiz "Error number of elements must be postive, try again!!"
reversePrint: .asciiz "The content of array in reverse order is:\n"
enterNumber: .asciiz "Enter number "
colon: .asciiz ": "
bars: .asciiz "=============================================\n"
newLine: .asciiz "\n"
.text

main:
# Prompt user for number of elements
li $v0,4
la $a0, inputRequest
syscall
inputNumber:
# Store number of elements in $s0
li $v0,5
syscall
add $s0,$v0,$0 
# Error check on range of input
bgt $s0, 10, errorOutOfRangeSpot
ble $s0, 0, errorNegativeSpot
li $v0,4
la $a0, bars
syscall
# Load $t0 with counter = 1
li $t0, 1
# Load $s1 with array address
la $s1, array
fillArrayStart:
# Load values until $t0 > num inputs
bgt $t0, $s0, endFillArray
li $v0, 4
la $a0, enterNumber
syscall
li $v0, 1
add $a0, $t0, $0
syscall
li $v0, 4
la $a0, colon
syscall
li $v0, 5
syscall
# Save input value into array
sw $v0, 0($s1)
# Add 4 to the address so next time through the index is incremented
addi $s1,$s1,4
addi $t0,$t0,1
j fillArrayStart

endFillArray:
li $v0, 4
la $a0, bars
syscall
la $a0, reversePrint
syscall
# Reset the address index to the last element of the array
addi $s1,$s1,-4
reverseStart:
# Continue printing values until reaching end of array
beq $t0, 1, end
li $v0, 1
# Load the value of the array into $t2
lw $t2,0($s1)
add $a0,$t2,$0
syscall
li $v0, 4
la $a0, newLine
syscall
# Work backwards, decrement counter, subtract 4 from the memory address
addi $t0, $t0, -1
addi $s1, $s1, -4
j reverseStart

# Error print
errorOutOfRangeSpot:
li $v0, 4
la $a0, errorOutOfRange
syscall
j inputNumber
# Error print
errorNegativeSpot:
li $v0, 4
la $a0, errorNegative
syscall
j inputNumber
# End program
end:
li $v0, 4
la $a0, bars
syscall
li $v0, 10
syscall
