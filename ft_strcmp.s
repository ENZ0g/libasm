; int ft_strcmp(char *str1, char *str2);

global _ft_strcmp

section .text
; | input
; rdi = str1
; rsi = str2
_ft_strcmp:
    xor rax, rax
    .next_iter:
        movzx rbx, byte [rdi + rax]
        movzx rcx, byte [rsi + rax]
        cmp rbx, byte 0
        je .eol_exit
        cmp rcx, byte 0
        je .eol_exit
        inc rax
        cmp rbx, rcx
        je .next_iter
        jne .diff_exit

    .eol_exit:
        cmp rbx, rcx
        je .exit
        jne .diff_exit

    .diff_exit:
        mov rax, rbx
        sub rax, rcx
        ret

    .exit:
        xor rax, rax
        ret