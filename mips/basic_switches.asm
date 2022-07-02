.data
JumpTable:
.word L0,L1,L2,L3
.text
li 	$s1,		2
li 	$s2,		4
li 	$s3, 	8
li 	$s4, 	16

li 	$s5, 	0 #0,1,2,3 
   #switch (k) k = $s5
slt	$t3, $s5, $zero 	# Test if k < 0
bne 	$t3, $zero, Exit # if k < 0, go to Exit
slti 	$t3, $s5, 4	#Test if k < 4
beq	$t3, $zero, Exit	# if k >= 4, go to Exit
add	$t1, $s5, $s5	# $t1 = 2 * k
add 	$t1, $t1, $t1	# $t1 = 4 *k

la 	$t4, JumpTable
add 	$t1,$t1, $t4	#$t1 = address of JumpTable[k]
lw	$t0, 0($t1)	# $t0 = JumpTable[k]
jr	$t0 # unconditional jump to address in register

L0: 	
	add	$s0,$s3, $s4  # i + j
	j	Exit
L1:
	add 	$s0,$s3,$s2	# g + h
	j	Exit
L2:	
	sub	$s0,$s3,$s4	# g -h
	j	Exit
L3:	
	sub	$s0,$s1,$s4	# i -j
Exit:
addiu	$a0, $s0, 0
li 	$v0,	1
syscall
li 	$v0,	10
syscall
