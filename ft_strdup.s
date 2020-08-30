; char *ft_strdup(const char *str)

extern _malloc
extern ___error

global _ft_strdup

section .text
; | input
; rdi = str
_ft_strdup:
    call .str_len
    push rdi
    mov rdi, rbx    ; size for malloc
    call _malloc    ; put pointer to rax
    jc .error
    pop rdi
    call .strcpy
    ret

    .str_len:
        xor rbx, rbx
        .next_char:
            cmp [rdi + rbx], byte 0
            je .end
            inc rbx
            jmp .next_char
        .end:
            inc rbx
            ret
    
    .strcpy:
        xor rbx, rbx
        .next_iter:
            cmp [rdi + rbx], byte 0
            je .close
            mov rcx, [rdi + rbx]
            mov [rax + rbx], rcx
            inc rbx
            jmp .next_iter
        .close:
            inc rbx
            mov [rax + rbx], byte 0
            ret

    .error:
        mov rbx, rax
        call ___error
        mov [rax], rbx
        xor rax, rax
        ret
