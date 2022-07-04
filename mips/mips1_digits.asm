
.data
input: .asciiz "Enter a two-digit number between -99 and 99 or 0 to finish: "
error: .asciiz "ERROR!! NOT A TWO-DIGIT NUMBER "
noavg: .asciiz "ERROR!! No Average"
final: .asciiz "The average is: "
.text

#jump to here to continue the loop
More: 
li $v0, 51
la $a0, input 
syscall 	
	
li $t1, 0 #sum
li $t2, 0 #counter 
#exit - print
Results: 
beq $t2, $zero, NoNum 
#no numbers entered, error

div $t1, $t2 
mult 


NoNum: 
la $a0, noavg 
li $v0, 4
syscall 


li $v0, 4
la $a0, input 
syscall 

slti $t0, $a1, 0 
bne $t0, $zero, More 
#exit 

Exit:
li $v0, 10
syscall 