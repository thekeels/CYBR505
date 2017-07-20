.data
dashes: .asciiz "========================================================================\n"
inputPrompt: .asciiz "Input a number in decimal form:\t"
outputStart: .asciiz "The number "
outputEnd: .asciiz " in binary is:\t0"
newline: .asciiz "\n"


.text
main:
# Prompt for decimal number
li $v0, 4
la $a0,dashes
syscall
la $a0,inputPrompt
syscall
li $v0,5
syscall
# Save deciman number is register $s1, and as argument $a0
add $a0,$v0,$0
add $s1, $a0,$0
# Jump to function BaseChange
jal BaseChange
# After returning from the function and subroutine, exit the program
li $v0,4
la $a0, newline
syscall
la $a0,dashes
syscall
li $v0,10
syscall



########### BaseChange #########################
BaseChange:
# Save the return address on the stack, decrease stack pointer by 1 word
sw $ra, 0($sp)
sub $sp, $sp,4
# Load initial variables for the decimal to binary conversion
li $t0, 2
li $t1,1073741824
# Store the argument decimal number in $s0
add $s0,$a0,$0
# Set the counter to 0
li $t4, 0
BaseChangeStart:
# End the conversion after 31 digits (32nd digit is the sign bit and will not be considered)
beq $t4, 31, BaseChangeEnd
# Divide the number by the 2^x to see if x bit needs to be set to a 1
div $s0,$t1
# Move remainder to $t2
mfhi $t2
# Move quotient to $t3
mflo $t3
# Save the binary bit value on the stack, and decrease the stack pointer by 4
sw $t3,0($sp)
sub $sp, $sp,4
#  Replace our decimal value with the remainder
add $s0,$t2,$0
# Set the divisor to 2^(x-1)
div $t1,$t0
mflo $t1
# Increment the counter
add $t4,$t4,1
j BaseChangeStart
BaseChangeEnd:
# Save the number of bits calculated on the stack (uneccesary because it will always be 31
sw $t4,0($sp)
# Jump to the PrintBinary subroutine!
jal PrintBinary
# Load the $ra for the main function from the stack
lw $ra,0($sp)
# Return to main
jr $ra

############# PrintBinary Subroutine ##########################
PrintBinary:
# Load the number of binary bits to be printed (unnecessary, will always be 31)
lw $t1, 0($sp)
# Because of the nature of the BaseChange function, we need to jump 31 words down into the stack
add $sp,$sp,124
# Print the output string
li $v0,4
la $a0,dashes
syscall
la $a0,outputStart
syscall
# Print the decimal number to be converted
li $v0,1
add $a0,$s1,$0
syscall
li $v0,4
la $a0, outputEnd
syscall
PrintBinaryStart:
# Print the binary bit value, until the counter is back to 0
beq $t1,$0,printBinaryEnd
# Load the bit value from the stack and decrease the stack pointer
lw $t0, 0($sp)
add $sp,$sp,-4
# Print the bit value
li $v0,1
add $a0,$t0,$0
syscall
# Decrement counter
sub $t1,$t1,1
j PrintBinaryStart
printBinaryEnd:
# Return to the $ra value of the BaseChange function in the stack (now 32 words down from current $sp)
add $sp,$sp,128
# Return to BaseChange function!
jr $ra
