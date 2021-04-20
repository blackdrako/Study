.386 
.MODEL FLAT, STDCALL 
OPTION CASEMAP: NONE
INCLUDE D:\masm32\INCLUDE\WINDOWS.INC
INCLUDE D:\masm32\INCLUDE\KERNEL32.INC
INCLUDE D:\masm32\INCLUDE\USER32.INC
INCLUDE D:\masm32\INCLUDE\msvcrt.INC
INCLUDELIB D:\masm32\LIB\USER32.LIB
INCLUDELIB D:\masm32\LIB\KERNEL32.LIB
INCLUDELIB D:\masm32\LIB\msvcrt.LIB

.DATA		
	x dd 0.2 ; значения в радианах
	y dd ?
	n dd 50
	frm db "s = %f", 0
.CODE 
;arcsin fun
arcsin proc
    fld   x                ;st(0)=x
    fld   st(0)             ;st(0)=st(1)=x
    fmul  st(0),st(0)          ;st(0)=x*x  st(1)=x
    fld1                     ;st(0)=1 st(1)=x*x  st(2)=x
    fsubrp st(1),st(0)                   ;st(0)=1-x*x st(1)=x
	;fsubr st(1),st(0) ;st(0)
    fsqrt                   ;st(0)=sqrt(1-x*x) st(1)=x
    fpatan                  ;arctg(st(1)/st(0))
    fstp y                   ;y=arcsin(x)
	push OFFSET y
	push OFFSET frm
	call crt_printf
	sub esp, 8
    RET
arcsin endp

START:
	CALL arcsin
	
	PUSH 0
	CALL ExitProcess
END START 