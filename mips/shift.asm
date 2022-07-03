.data
ll: .asciiz "\nLeft Shift5 "
rl: .asciiz "\nRight Shift5 "
.text

li $t5, 5 
sll $t6, $t5, 1 #left logical shift 1

li $v0, 4 
la $a0 ll 
syscall

li $v0, 1 #print int
addi $a0, $t6,0 #move to syscall reg
syscall

li $t5, 5 
srl $t6, $t5, 1 #right logical shift 1

li $v0, 4 
la $a0 rl 
syscall

li $v0, 1 #print int
addi $a0, $t6,0 #move to syscall reg
syscall
