.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE
.DATA
	a DB 5
	b DD a, 6
	DF 15
	DD 13.5, 15.6, 18.9
	DQ 17890.65432
.CODE
START:
	XOR EAX, EAX
	MOV EAX, b[0]
	ADD EAX, DWORD PTR b[8]
END START

