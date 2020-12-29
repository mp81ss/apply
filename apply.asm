.386
.MODEL FLAT

ifndef APPLY_NESTING_LEVEL
APPLY_NESTING_LEVEL EQU 16
endif

.DATA?
level dd ?
addresses dd APPLY_NESTING_LEVEL dup(?)
functions dd APPLY_NESTING_LEVEL dup(?)

.CODE
apply PROC NEAR C PUBLIC
    cmp [level], APPLY_NESTING_LEVEL
    je short err

    mov eax, [level]
    inc [level]
    lea ecx, [OFFSET addresses + eax*4]
    pop [ecx]
    lea ecx, [OFFSET functions + eax*4]
    pop eax
    mov [ecx], eax
    push OFFSET cont
    jmp eax

cont:
    dec [level]
    mov ecx, [level]
    lea ecx, [OFFSET functions + ecx*4]
    push [ecx]
    sub ecx, OFFSET functions
    add ecx, OFFSET addresses
    mov ecx, [ecx]
    jmp ecx

err:
    xor eax, eax
    xor edx, edx
    ret
apply ENDP

END
