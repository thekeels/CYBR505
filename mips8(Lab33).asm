.data
# Set up space for the coupon and price arrays, containing max of 20 words each
couponArray: .space 80
priceArray: .space 80
inputPrompt: .asciiz "Please enter the number of items you are purchasing\n"
pricePrompt: .asciiz "Please enter the price of item "
couponPrompt: .asciiz "Please enter the amount of coupon for item "
errorCoupon: .asciiz "Sorry this coupon is not acceptable\n\n"
total:	.asciiz "\nYour total charge is:\t$"
thankYou: .asciiz "\n\nThank you for shopping from us.\n"
errorOutOfRange: .asciiz "Sorry, this is outside the range of acceptable inputs (0<n<21).\n\n"

newlineDollar: .asciiz "\n$"

.text

main:
# Prompt user for number of items
li $v0, 4
la $a0, inputPrompt
syscall
# Store the number of items in $s0
li $v0, 5
syscall
add $s0, $v0, $0
# Range check on the input
bgt $s0, 20, errorOutOfRangeSpot
ble $s0, 0, errorOutOfRangeSpot
# Jump to the FillPriceArray function
jal FillPriceArray
# Jump to the FillCouponArray function
jal FillCouponArray
# After filling the arrays, compute the total price of (item - coupon)
computeTotal:
la $t0, priceArray
la $t1, couponArray
li $t2,0 # $t2 is the item cost after discount (item - coupon)
li $t3,1 # t3 is the counter
li $t4,0 # $t4 is the running tally of the total cost
computeTotalStart:
bgt $t3, $s0, computeTotalEnd
# Load the values of the item and coupon for the current index
lw $t5,0($t0)
lw $t6,0($t1)
# Find the discounted price
sub $t2,$t5,$t6
# Add the discounted item price to the subtotal
add $t4,$t4,$t2
# Increase the indeces, and the counter
add $t0,$t0,4
add $t1,$t1,4
add $t3,$t3,1
j computeTotalStart
computeTotalEnd:
# Print the total
li $v0, 4
la $a0, total
syscall
li $v0,1
add $a0, $t4,0
syscall
li $v0,4
la $a0, thankYou
syscall
li $v0,10
syscall



################# FillPriceArray ###################
FillPriceArray:
# Load array and counter
li $s1, 1
la $s2, priceArray
FillPriceArrayStart:
# Go to end of function if number of items has been reached
bgt $s1,$s0, FillPriceArrayEnd
li $v0, 4
la $a0, pricePrompt
syscall
li $v0, 1
add $a0, $s1,$0
syscall
li $v0,4
la $a0,newlineDollar
syscall
# Read the price from the user, store in $s3
li $v0, 5
syscall
add $s3, $v0, $0
# Save the price in the priceArray, and increment the priceArray index
sw $s3,0($s2)
add $s2, $s2, 4
# Increment counter
addi $s1, $s1, 1
j FillPriceArrayStart
FillPriceArrayEnd:
# Return to main
jr $ra

##############  FillCouponArray ####################
FillCouponArray:
# Load the counter, and the array indeces
li $s1, 1 
la $s2, couponArray
la $t2, priceArray
FillCouponArrayStart:
# End function if number of coupons equals number of items
bgt $s1, $s0, FillCouponArrayEnd
li $v0, 4
la $a0, couponPrompt
syscall
li $v0,1
add $a0, $s1, $0
syscall
li $v0, 4
la $a0, newlineDollar
syscall
li $v0, 5
syscall
add $t1,$v0,$0
# Validity check on the coupon value ($0 <coupon< $10)
bge $t1, 10, errorCouponSpot
blt $t1, 0, errorCouponSpot
# Validity check on the coupon value (coupon must be < item price
lw $t3, 0($t2)
bgt $t1, $t3, errorCouponSpot
# Save the coupon value in the couponArray
sw $t1,0($s2)
continueCouponArray:
# Increment the counter, and the indeces of the arrays
add $s1, $s1, 1
add $t2, $t2, 4
add $s2, $s2, 4
j FillCouponArrayStart
FillCouponArrayEnd:
# Return to main
jr $ra
# Print coupon error, and save 0 dollars for the coupon in the couponArray
errorCouponSpot:
sw $0,0($s2)
li $v0, 4
la $a0, errorCoupon
syscall
j continueCouponArray
# Print out of range error on user input
errorOutOfRangeSpot:
li $v0, 4
la $a0, errorOutOfRange
syscall
j main
