; int ft_write(int fd, char *str, int len);

extern ___error

global _ft_write

section .text
; | input
; rdi = fd
; rsi = str
; rdx = len
_ft_write:
    mov rax, 0x02000004
    syscall
    jc .error
    ret

    .error:
        mov rbx, rax
        call ___error
        mov [rax], rbx
        mov rax, -1
        ret