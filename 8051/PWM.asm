ORG 0x0


MOV R0, #0xfe   ; Duty out of 8-bits
MOV R1, #0x3F   ; Total time out of 8-bits
MOV 0x23, R0

MAINLOOP:
    MOV     A,  #0xFF

    MOV     P1, #0x0
    
    CYCLE:  JZ      MAINLOOP
            DEC     A
            MOV     0x22,R1
			D1:     DJNZ 0x22,D1
            CJNE    A,0x23,CYCLE
            MOV     P1, #0x1

END




