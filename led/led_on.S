.text
.global _start
_start:
    LDR R0, =0x56000010
    MOV R1, #0x00000400
    STR R1, [R0]

    LDR R0, =0x56000014
    MOV R1, #0x00000000
    STR R1, [R0]

main_loop:
    b main_loop
