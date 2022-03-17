  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
   # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line

.global delay
.global hexasc
.global time2string

.data
.text
hexasc:	
	andi $t0, $a0, 0xf  #masks last 4 bits in $a0 (possible 0x0 - 0xf)
	addi $v0, $t0, 0x30 #last 4 bits + 0x30 to get to min char 0
	slti $t1, $v0, 0x3a #$v0 < 0x3A, 1 true, 0 false
	
	beq $t1, 1, skip # jump to skip if true, else
	nop
	addi $v0, $v0, 0x7 #  add 0x7 for A

	skip:

  	jr $ra #jump back to where linked
  	nop
  	
delay:

	while:	
	slt $t0, $0, $a0 # 0 < ms
	beq $t0, $0, whileEnd
	addi $a0,$a0,-1
	
	add $t0, $0, $0 #i=0
	
	for:
	slti $t1, $t0, 4711 # $t0(i) < 4711
	beq $t1, $0, forEnd # jump to forEnd if i !< 4711
	addi $t0,$t0,1
	j for
	nop
	
	forEnd:
	j while
	nop

	whileEnd:
	nop
	
	jr $ra
	nop
time2string:
	PUSH $ra
	PUSH $a0	

	#$a0 contains adress for 
	#$a1 contains NBDC string

	andi $a0, $a1, 0xf000 #masks first digit in last 4 bits
	srl $a0, $a0, 12
	PUSH $a1
	jal hexasc
	nop
	POP $a1
	POP $a0
	sb $v0, 0($a0) # saves first digit
	PUSH $a0
	
	andi $a0, $a1, 0xf00 #mask second digit in last 4 bits
	srl $a0, $a0, 8
	PUSH $a1
	jal hexasc
	nop
	POP $a1
	POP $a0
	sb $v0, 1($a0) # saves second digit
	
	addi $t0, $0, 0x3a
	sb $t0, 2($a0) # saves :
	PUSH $a0

	andi $a0, $a1, 0xf0 #mask 3 digit in last 4 bits
	srl $a0, $a0, 4
	PUSH $a1
	jal hexasc
	nop
	POP $a1
	POP $a0
	sb $v0, 3($a0) # saves third digit
	PUSH $a0
	
	andi $a0, $a1, 0x0000f #fourth digit in last 4 bits
	PUSH $a1
	jal hexasc
	nop

	POP $a1
	POP $a0
	sb $v0, 4($a0) # saves last digit
			
	sb $0, 5($a0) # saves null
	
	POP $ra
	nop
	jr $ra
	nop
