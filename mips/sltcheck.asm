.data
.asciiz 
invalidNumber: "\nError: Invalid number, please try again"
.text

li $t8 '1'
li $t6 'A'
li $t1 '0'
slt $t2, $t8, $t1

li $t4 '9' 
li $t5 'F'
slt $t3, $t8, $t4

bge $t8, '0', exit #valid dig 

#bge $t8,$t6 , exit  #A
#ble $t8, $t5, exit  #F

sle $s1, $t8, '0' #checjk

li  $t0, '0'
bltu   $t1,$t0, notdig        # Jump if char < '0'

li $t0,'9'
bltu   $t0,$t1, notdig       # Jump if '9' < char

#j exit

notdig:
li $v0, 4 #print dialog
		la $a0, invalidNumber #show error
		syscall 
		
		
		exit: 
