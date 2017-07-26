.data
inputPrompt: .asciiz "Please input a temperature in Celsius\n==>"
outputFahrenheit: .asciiz "The temperature in Fahrenheit is: ==>\n"
num9: .float 9.0
num5: .float 5.0
num32: .float 32.0
.text

main:
li $v0, 4
la $a0, inputPrompt
syscall
# Read an integer
li $v0,5
syscall
# Move integer into $s0
add $s0, $v0, 0
# Move integer to coprocessor 1
mtc1 $s0, $f0
# Convert integer to single float
cvt.s.w $f1, $f0

# Load the float values to compute fahrenheit conversion
l.s $f3, num9
l.s $f5, num5
l.s $f7, num32
# F = (9.0/5.0) * C + 32
div.s $f9, $f3,$f5
mul.s $f12, $f1, $f9
add.s $f12, $f12, $f7
# Print output
li $v0, 4
la $a0, outputFahrenheit
syscall
# Print value in $f12 (conversion from C to F
li $v0, 2
syscall
# Exit
li $v0,10
syscall