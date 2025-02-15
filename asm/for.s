.global _main

_main:
    MOV X0, #48
    STR X0, [SP, #-16]!
    MOV X19, #0

loop:
    MOV X0, #1
    MOV X1, SP
    MOV X2, #1
    MOV X16, #4
    SVC #0x80
    
    MOV X0, #10
    STR X0, [SP]
    MOV X0, #1
    MOV X1, SP
    MOV X2, #1
    MOV X16, #4
    SVC #0x80

    ADD X19, X19, #1
    ADD X0, X19, #48
    STR X0, [SP]

    CMP X19, #10
    B.LT loop
    B exit

exit:
    ADD SP, SP, #16
    MOV X16, #1
    SVC #0x80