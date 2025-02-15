.global _main
.align 2

_main:
    ADRP X1, num1@PAGE
    ADD X1, X1, num1@PAGEOFF
    
    MOV X0, #1          // X0 - file descriptor (1 = stdout)
    MOV X2, #1          // X2 - str length
    MOV X16, #4         // X16 - write syscall number
    SVC #0x80           // syscall
    
    ADRP X1, str@PAGE
    ADD X1, X1, str@PAGEOFF
    MOV X2, #8
    MOV X16, #4
    SVC #0x80
    
    // Exit
    MOV X16, #1
    SVC #0x80

.data
    .align 2
    num1: .byte 48
    .align 2
    num2: .byte 49
    .align 2
    str: .ascii "\nString\n"

