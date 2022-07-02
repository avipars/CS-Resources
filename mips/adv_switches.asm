.data
Funcs:
.word L1,L2,L3,L4
Lookup:
.asciiz "+-*/@" #the example was to make a calculutor
LookupTable:
.align 2
.space 168 #calculate the ascii values
.word L_ASTERISK, L_ADD
.space 4
.word L_SUB
.space 4
.word L_DIV

.text
li $s0, '*'
#Method 1
la $s1, Lookup
search:
   lbu $t0  0($s1)
   beq $t0, $zero, End
   beq $t0, $s0, Found
   addi $s1, $s1, 1
   j search
 
Found:
la $t0, Lookup
sub $s1, $s1, $t0
sll $s1, $s1, 2
la $s2, Funcs
add $s2,  $s2, $s1
lw $s2, 0($s2)
jr $s2
#Method 2 - may cause an infinite loop, make sure to change as necessary before running
#la $t0, LookupTable
#sll $t1, $s0, 2
#add $t0, $t0, $t1
#lw $t1, 0($t0)
#jr $t1
end_switch:


j End

L1:
L_ADD:
li $a0, '1'
jal print
j end_switch

L2:
L_SUB:
li $a0, '2'
jal print
j end_switch

L3:
L_ASTERISK:
li $a0, '3'
jal print
j end_switch

L4:
L_DIV:
li $a0, '4'
jal print
j end_switch

End:
li $v0, 10
syscall

print:
li $v0, 11
syscall
jr $ra
