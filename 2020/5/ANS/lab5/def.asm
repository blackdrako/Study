.386 
.model flat, stdcall 
option casemap: none 

include c:\masm32\include\windows.inc
include c:\masm32\include\kernel32.inc
include c:\masm32\include\user32.inc
include c:\masm32\include\msvcrt.inc

includelib c:\masm32\lib\user32.lib
includelib c:\masm32\lib\kernel32.lib
includelib c:\masm32\lib\msvcrt.lib

.DATA
        x dd 2
        y dd 10
		i dd 1
        format db "n = %d, val = %G",13, 10, 0
.CODE

start:
mov ecx, 100
mov eax, i
l1:
;1/n
fild eax;st(1)
fild i;st(0)
fdiv st(0), st(1);st(0)/st(1) 1/n(st(0)) 1(st(1))
;arcsin= arctg (x / sqrt(1-x^2))
fld st(0)
fmul st(0), st(1);x*x st
fsub st(0), st(2);1-x^2
fsqrt st(0) ;sqrt(1-x^2)
;fdiv st(1), st(0) ;x / sqrt(1-x^2)
fpatan ;arctg (x / sqrt(1-x^2))
push offset format
call crt_printf
inc eax
loop l1
;arcsin x
;Вывод format

start:
    xor eax,eax
    xor ebx,ebx
    xor edx,edx
    xor ecx,ecx
loop_start:
    inc ecx
    push ecx
    call row
    push eax
    push 0
    push ecx
    push offset format
    call crt_printf
    add esp,4
    pop ecx
    cmp ecx,100
    jl loop_start
END start
