; ssize_t ft_read(int fd, char *buf, int len)

extern ___error

global _ft_read

section .text
; | input
; rdi = fd
; rsi = buf
; rdx = len
_ft_read:
    mov rax, 0x02000003
    syscall
    jc .error
    ret

    .error:
        mov rbx, rax
        call ___error
        mov [rax], rbx
        mov rax, -1
        ret