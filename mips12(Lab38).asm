.data
array:	.space 40
inputPrompt: .asciiz "Input the size of the array: "
outputPrint: .asciiz "The array is: "
space: .asciiz " "
maxPrint: .asciiz "\nMaximum value is: "
sortPrint: .asciiz "\nSorted array is: "


.text

li $v0, 4
la $a0, inputPrompt
syscall
li $v0, 5
syscall
add $a0, $v0, $0 # Store n in $a0
add $s0, $v0, $0 # Store n in $s0
jal FillArray

li $v0, 4
la $a0, outputPrint
syscall
add $a0, $s0,$0
jal PrintArray
li $v0, 4
la $a0, maxPrint
syscall
add $a0, $s0,0
jal FindMax

li $v0, 4
la $a0, sortPrint
syscall
add $a0, $s0,0
jal SortArray
add $a0, $s0, $0
jal PrintArray

li $v0, 10
syscall

### FillArray function ###
FillArray:
#sw $ra, 0($sp) # Store the return to main on the stack
add $t0, $a0, $0 # Store n in $t0
la $s1, array
Loop:

beq $t0, $0, endLoop
li $v0, 5
syscall
sw $v0, 0($s1)

addi $s1, $s1,4
add $t0, $t0, -1
j Loop
endLoop:
jr $ra

## PrintArray function ###
PrintArray:
add $t0, $a0, $0 # Counter
la $t1, array
startPrint:
beq $t0, $0, endPrint

lw $t2, 0($t1)
li $v0, 1
add $a0, $t2, $0
syscall
li $v0, 4
la $a0, space
syscall
add $t1, $t1,4
add $t0, $t0,-1 # Decrement counter
j startPrint
endPrint:
jr $ra

## FindMax function ###
FindMax:
add $t0, $a0, $0
la $t1, array

startMax:
lw $t2, 0($t1) # initial max
beq $t0, $0, endMax

ble $t2, $t3, lessSpot

greaterSpot:
add $t3, $t2, $0 # new max
lessSpot:
add $t1, $t1, 4
add $t0, $t0,-1
j startMax
endMax:
li $v0, 1
add $a0, $t3, $0
syscall
jr $ra

### Sort Array function ###
SortArray:
add $t0, $a0, $0 # Store length in array

add $t1, $t0,$0 # i counter
la $s4, array
add $s5, $s5, 4 # value of 4 for calculating offset
startiLoop:

#li $t2, 0 # j counter
#addi $t2, $t1, 1
#mult $t2, $s5
#mflo $t2
#add $s4, $s4,$t1 # address of Array[i] (i)
lw $t5, 0($s4) # Value of Array[i]
add $t2,$t1,1 # j = i+1
add $s6, $s4,4 # address of Array[j] (j=i+1)
lw $t3, 0($s6) # value of Array[j]
beq $t1, $0, endSort
startjLoop:

beq $t2, $0, endjLoop
bgt $t3, $t5 endjLoop
add $t4, $t5, $0 # Load temp = Array[i]
sw $t3, 0($s4)
sw $t5, 0($s6)
#add $t5, $t3, $0
#add $t3, $t4,$0



add $t2,$t2,-1
add $s6, $s6,4
add $s4,$s4,4
endjLoop:
add $t2, $t2, -1
j startjLoop
endiLoop:
add $t1,$t1,-1
j startiLoop
endSort:
jr $ra



