.data
array: .word 40
inputPrompt: .asciiz "How many numbers you like to enter to calculate median of (0<n<11): "
enterNumber: .asciiz "Enter number "
errorOutOfRange: .asciiz "Error, out of range 0<n<11, try again: "
colon: .asciiz ": "
dashes: .asciiz "=======================================\n"
median: .asciiz "The median is: "
newline: .asciiz "\n"
.text

main:
# Load address of array into $s1
la $s1, array 
# Prompt for number of inputs
li $v0, 4
la $a0, inputPrompt
syscall
enterNumberSpot:
li $v0,5
syscall
# Store number of inputs in $s0
add $s0, $v0, $0
li $v0, 4
la $a0, newline
syscall

# Error check on size of input range
bgt $s0, 10, errorOutOfRangeSpot
blt $s0, 1, errorOutOfRangeSpot
# Store counter variable in $t0
li $t0,1 
# Store address of array temporarily in $t1
add $t1,$s1,$0
fillStart:
# Branch to median calculation if counter > num inputs
bgt $t0,$s0, medianStart
li $v0, 4
la $a0, enterNumber
syscall
li $v0,1
add $a0,$t0,$0
syscall
li $v0,4
la $a0, colon
syscall
li $v0, 5
syscall
sw $v0,0($t1)
addi $t1,$t1,4
addi $t0,$t0,1
j fillStart


medianStart:
li $v0, 4
la $a0, dashes
syscall
# Store 2 in $s3
li $s3,2
# Divide the num inputs by 2
div $s0,$s3
# Check remainder = 1? If so, store the median is the middle index number
mfhi $t1
beq $t1, 1, medianOdd
# If remainder = 0, we need to add the middle values and divide by 2 to find the median
# $t2 is the higher index value
mflo $t2
# Calculate 4 * indexHI
add $t3,$t2,$t2
add $t3,$t3,$t3
# Calculate (4* indexHI) + base address
add $t3,$t3,$s1
# Load the HI value into $t4
lw $t4,0($t3)
# Now find the index of the LO value
add $t2, $t2,-1
# Calculate 4 * indexLO
add $t3,$t2,$t2
add $t3,$t3,$t3
# Calculate (4* IndexLO) + base address
add $t5, $t3,$s1
# Load the LO value into $t6
lw $t6, 0($t5)
# Calculate the average of (LO + HI)/2
add $t6,$t6,$t4
div $t6,$s3
mflo $s2
j end

medianOdd:
# If the median is the middle index number, then load the array value of that index
# Middle index = $t1
mflo $t1
# For integer, calculate 4 * index
add $t2, $t1,$t1 
add $t2, $t2,$t2
# Add (4* index) + base address of array
add $t2,$t2,$s1
# Load the value at the memory location
lw $s2, 0($t2)
j end
# Print errors
errorOutOfRangeSpot:
li $v0, 4
la $a0, errorOutOfRange
syscall
j enterNumberSpot
# Print median value
end:
li $v0, 4
la $a0,median
syscall
li $v0,1
add $a0,$s2,$0
syscall
li $v0,4
la $a0,newline
syscall
la $a0,dashes
syscall
li $v0, 10
syscall
