global  _main

section .text
_main:
    mov     rax, 0x02000004
	mov     rdi, 1
    lea     rsi, [message]
    mov     rdx, len
    syscall
	call    _exit

_exit:
    mov       rax, 0x02000001
    xor       rdi, rdi
    syscall

section   .data
message default rel
		db		"Congrats! Everything is working OK!", 10, 0
len 	equ 	$-message
