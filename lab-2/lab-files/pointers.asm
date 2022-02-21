
        # pointers.asm
# By David Broman, 2015-09-14
# This file is in the public domain


.macro	PUSH (%reg)
	addi	$sp,$sp,-4
	sw	%reg,0($sp)
.end_macro

.macro	POP (%reg)
	lw	%reg,0($sp)
	addi	$sp,$sp,4
.end_macro

.data


text1: 	  .asciiz "This is a string."
text2:	  .asciiz "Yet another thing."

.align 2
list1: 	.space 80
list2: 	.space 80
count:	.word  0

.text
main:
	jal	work
stop:	j	stop

# function work()
work:
	PUSH	($ra)
	la 	$a0,text1
	la	$a1,list1
	la	$a2,count
	jal	copycodes
	
	la 	$a0,text2
	la	$a1,list2
	la	$a2,count
	jal	copycodes
	POP	($ra)
	
	
# function copycodes()
copycodes:
loop:
	
	lb	$t0,0($a0) # loads first byte from $a0 to €t0

	
	beq	$t0,$0,done	
	# while($t0 != 0)
	
	sw	$t0,0($a1) # stores word to adress $a1 from $t0 

	addi $a0,$a0,1 # increments $a0 with 1


	addi $a1,$a1,4 # increments $a1 with 4 bits, offset for next adress
	
	lw	 $t1,0($a2)  # loads word from adress $a2 to $t1

	addi $t1,$t1,1 # increments $t1 with 1
	
	sw	 $t1,0($a2) #stores word to $a2 from $t1 
	
	j	loop

done:
	jr	$ra
		



