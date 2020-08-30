; int ft_strlen(char *str);

global _ft_strlen

section .text
; | input
; rdi = str
_ft_strlen:
    xor rax, rax
    .next_iter:
        cmp [rdi+rax], byte 0
        je .close
        inc rax
        jmp .next_iter
    .close:
        ret