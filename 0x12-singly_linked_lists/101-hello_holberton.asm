section .data
    hello db 'Hello, Holberton', 0

section .text
    global main

extern printf

main:
    ; Save base pointer and stack pointer
    push rbp
    mov rbp, rsp

    ; Call printf with the hello string
    lea rdi, [hello]
    call printf

    ; Restore base pointer and stack pointer, and return
    leave
    ret
