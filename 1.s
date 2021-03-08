.data
printf_format1: .string "%d\n"

array:
	.long 0,1,2,3,4,5,6,7,8,9
array_end: 
 
.text
.global main
main:
	movl $array, %ebx
        movl  $0, %eax   
        movl  $10, %ecx
        movl  $5, %edx
        movl  $0, %esi
 
sum:
        cmpl %edx,(%ebx)
        jl les
        jg gr
        je equ
        
les:
	addl  $1, %esi
	addl  $4, %ebx
	jmp s
	
gr:
	addl (%ebx),%eax
	addl  $4, %ebx
	jmp s
	
equ:
	addl  $4, %ebx
	jmp s

s:
        loop  sum

/*
 * следующий код выводит на экран и завершает программу
 */

        pushl %eax
        pushl $printf_format1
        call  printf
        addl  $8, %esp
        movl  $0, %eax
        
        pushl %esi
        pushl $printf_format1
        call  printf
        addl  $8, %esp
        movl  $0, %esi
        
        ret
