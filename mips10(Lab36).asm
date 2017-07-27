.data
strInput: .byte ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
space: .asciiz " "
strEncrypt: .byte ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
space2: .asciiz " "
strDecrypt: .byte ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
space3: .asciiz " "
inputPrompt: .asciiz "Please enter a string of 9 characters: "
outputString: .asciiz "\nInput: "
encryptedString: .asciiz "\nEncrypted: "
decryptedString: .asciiz "\nDecrypted: "

.text
main:
#li $s0, 10 # Key is 10
li $a1, 10 # Length of buffer 10
li $v0, 4
la $a0, inputPrompt
syscall
li $v0, 8
la $a0, strInput
syscall
li $v0, 4
la $a0, outputString
syscall
la $a0, strInput
syscall
# Send input to be encrypted
la $s1, strInput 
la $s3, strEncrypt
jal Encrypt_Decrypt
li $v0, 4
la $a0, encryptedString
syscall
la $a0, strEncrypt
syscall
# Decrypt the encrypted string
la $s1, strEncrypt 
la $s3, strDecrypt
jal Encrypt_Decrypt
li $v0, 4
la $a0, decryptedString
syscall
la $a0, strDecrypt
syscall
# Exit
li $v0, 10
syscall

Encrypt_Decrypt:
li $t0, 10 # Counter
li $s0, 10 # Key = 10
loop:
beq $t0, 0, exitLoop
lb $t1,0($s1)
xor $t2, $t1,$s0
sb $t2, 0($s3)
li $t1,0
sub $t0, $t0, 1 # Increment counter
add $s1, $s1, 1 # Increment input
add $s3, $s3, 1 # Increment key
j loop
exitLoop:
jr $ra
