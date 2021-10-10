.386
.MODEL FLAT

.CODE
apply PROC NEAR C PUBLIC
    pop eax
    pop ecx
    push eax
    jmp ecx
apply ENDP

END
