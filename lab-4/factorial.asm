addi $at, $0, 1
beq $at, $0, zero


addi $a0, $at, 0 #a0 = n
addi $a2, $a0, -1 #a2 = n - 1 
addi $a3, $0, 0 #a3 = 0

addi $v1, $0, 1
beq $v1, $at, zero	

loop:
    beq $a2, $v1, done #if a2 == 1


mult:
    beq $a3, $a2, nextCount #if a3 == n - 1

    add $v0, $v0, $a0 #nested loop return value
    addi $a3, $a3, 1 #loop increment
    beq $0, $0, mult

nextCount:
    addi $a0, $v0, 0 # $a0 = nested loop return value
    addi $a2, $a2, -1 # loop increment
    addi $a3, $0, 1    #inner loop increment
    beq $0, $0, loop
    nop

zero:
    addi $v0, $0, 1

done:
j done
