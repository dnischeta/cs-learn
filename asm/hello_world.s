.global _main
.align 2

_main:
    MOV     x0, #1
    ADRP    x1, hello@PAGE
    ADD     x1, x1, hello@PAGEOFF
    MOV     x2, #12
    MOV     x16, #4
    SVC     #0x80
    
    MOV     x0, #0
    MOV     x16, #1
    SVC     #0x80

.data
    hello: .ascii "Hello World\n"
