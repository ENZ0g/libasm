; int ft_list_size(t_list *list);

global _ft_list_size

section .text
; | input
; rdi = list
_ft_list_size:
    xor rax, rax
    cmp rdi, 0
    je .end
    .next_iter:
        inc rax
        cmp [rdi + 8], byte 0
        je .end
        mov rdi, [rdi + 8]
        jmp .next_iter
    .end:
        ret