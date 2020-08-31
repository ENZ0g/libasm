; void	ft_list_push_front(t_list **list, void *content)

extern _malloc

global _ft_list_push_front

section .text
; | input
; rdi = list
; rsi = content
_ft_list_push_front:
    xor rax, rax
    cmp rdi, 0
    je .end
    push rdi
    push rsi
    mov rdi, 16
    call _malloc
    jc .end
    pop rsi
    pop rdi
    mov [rax], rsi
    mov rdx, [rdi]
    mov [rax + 8], rdx
    mov [rdi], rax
    ret

    .end:
        ret