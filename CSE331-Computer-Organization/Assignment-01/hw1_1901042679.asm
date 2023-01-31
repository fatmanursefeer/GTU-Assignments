.data
	getArraySize: 		.asciiz "Please enter the array size (max limit 100): "
	getNumberT: 		.asciiz "Please enter the k number: "
	getArrayNumbers: 	.asciiz "Enter number: \n"
	numberOfPairs: 		.asciiz "\nNumber of pairs: "
	print_1:		.asciiz "\n["
	print_2:		.asciiz ","
	print_3:		.asciiz "]"
	arr: 			.word 100 	# int array[MAX_SIZE = 100]

.globl main
.text
main:

	while_1:
		addi $s5, $zero, 2	#for size >= 2
		addi $s6, $zero, 100	#for size, k number <= 100
		addi $s7, $zero, 1	#for k number >= 1
	
		li $v0, 4
		la $a0 getArraySize	#takes array size
		syscall
		li $v0, 5
		syscall
		move $s0, $v0
	
		blt $s0, $s5, while_1
		bgt $s0, $s6, while_1
	
		li $v0, 4
		la $a0 getNumberT	#takes k number
		syscall
		li $v0, 5
		syscall
		move $s1, $v0
	
		blt $s1, $s7, while_1
		bgt $s1, $s6, while_1
	
		mul $s2, $s0, 4
		addi $s3, $s2, -4
		loop_1:
			beq $t0, $s2, exit_1
			la $a0 getArrayNumbers	#takes array numbers
			li $v0, 4
			syscall
			li $v0, 5
			syscall
			blt $v0, $s7, edit
			bgt $v0, $s6, edit
			sw $v0, arr($t0)
			addi $t0, $t0, 4
			j loop_1
			edit:
				addi $t0, $zero, 0	#clear the t0
				j while_1
		exit_1:
			j exit_while
	exit_while:
		jal divisibleSumPairs

	li $v0, 10
    	syscall

divisibleSumPairs:
	for_1:
		beq $s3, $t2, exit_3
		addi $t3, $t2, 4	#j=i+1
		for_2:
			beq $t3, $s2, exit_2
			lw $t4, arr($t2)	#arr[i]
			lw $t5, arr($t3)	#arr[j]
			add $t6, $t4, $t5	#arr[i] + arr[j]
			div $t6, $s1
			mfhi $t7		#(arr[i] + arr[j]) % k
			bne  $t7, $zero, assign
			addi $s4, $s4, 1
			la $a0 print_1		#prints the pair
			li $v0, 4
			syscall
			li $v0, 1
			move $a0, $t4
    			syscall
    			la $a0 print_2
			li $v0, 4
			syscall
			li $v0, 1
			move $a0, $t5
    			syscall
    			la $a0 print_3
			li $v0, 4
			syscall
			j assign
			assign:
				addi $t3, $t3, 4	#j++
				j for_2
		exit_2:
			addi $t2, $t2, 4	#i++
			j for_1
	exit_3:
		la $a0, numberOfPairs	#prints the pairs number
    		li $v0, 4    
    		syscall
    		li $v0, 1
    		move $a0, $s4
    		syscall
    	jr $ra
	
