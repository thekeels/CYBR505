
.data
str:	.asciiz "Program Description:\tOutput\n\nAuthor:\t\t\tKyle\n\nCreation Date:\t\t"
str2:	.asciiz "/"

str3:	.asciiz "Here is the report of top 3 employees in Texas Instruments Company:\n"
str4:	.asciiz "=====================================================================\n"
str5:	.asciiz "Last Name\tFirst Name\tPosition\tSalary\n"
str6:	.asciiz "~~~~~~~~~\t~~~~~~~~~~\t~~~~~~~~~\t~~~~~~\n"
str7:	.asciiz "Smith\t\tAdam\t\tDirector\t"
str8:	.asciiz "Hadden\t\tMary\t\tDirector\t"
str9:	.asciiz "Simpson\t\tMike\t\tManager\t\t"
str10:	.asciiz "\n"

.text

main: 
	li $v0, 4
	la $a0, str #Print header
	syscall
	li $v0, 1   #Print 09
	li $a0, 0
	syscall
	li $a0, 9
	syscall
	li $v0, 4 # Print '/'
	la $a0, str2
	syscall
	li $v0, 1 # Print 08
	li $a0, 0
	syscall
	li $a0, 8
	syscall
	li $v0, 4 # Print '/'
	la $a0, str2
	syscall
	li $v0, 1 # Print 2008
	li $a0, 2008
	syscall
	li $v0, 4 
	la $a0, str10
	syscall # Newlines
	la $a0, str10
	syscall 
	la $a0, str3
	syscall # Here is the report of top 3 employees in Texas Instruments Company:
	la $a0, str4
	syscall # =====================================================================
	la $a0, str5
	syscall #Last Name	First Name	Position	Salary
	la $a0, str6
	syscall #~~~~~~~~~	~~~~~~~~~~	~~~~~~~~~	~~~~~~
	la $a0, str7
	syscall # Smith		Adam		Director
	li $v0, 1
	li $a0, 99010
	syscall # Print 99010
	li $v0, 4
	la $a0, str10
	syscall # New line
	la $a0, str8
	syscall #Hadden		Mary		Director
	li $v0, 1
	li $a0, 95220
	syscall # Print 95220
	li $v0, 4
	la $a0, str10
	syscall # New line
	la $a0, str9
	syscall #Simpson	Mike		Manager
	li $v0, 1
	li $a0, 80000
	syscall # Print 80000
	li $v0, 4
	la $a0, str10
	syscall # New line
	la $a0, str4
	syscall # =====================================================================
	
