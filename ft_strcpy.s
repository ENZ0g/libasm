; char *ft_strcpy(char *dst, char *str)

global _ft_strcpy

section .text
; | input
; rdi = dst
; rsi = str
_ft_strcpy:
    xor rax, rax
    .next_iter:
        cmp [rsi+rax], byte 0
        je .close
        mov rbx, [rsi+rax]
        mov [rdi+rax], rbx
        inc rax
        jmp .next_iter
    .close:
        inc rax
        mov [rdi+rax], byte 0
        mov rax, rdi
        ret