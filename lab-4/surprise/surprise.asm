addi $a0, $0, 4
beq $a0, $0, zero
addi $v1, $a0, -1 
addi $v0, $a0, 0 

loop:
beq $v1, $0, done
mul $v0, $v1, $v0  
addi $v1, $v1, -1

beq $0, $0, loop

zero:
    addi $v0, $0, 1
done:
