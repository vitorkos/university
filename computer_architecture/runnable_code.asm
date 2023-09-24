;adding two numbers(user input)

section .data
msg1 db "Enter the first number : ",0xa
len1 equ $ - msg1
msg2 db "Enter the 2nd number : ",0xa
len2 equ $ - msg2

msg3 db "The sum is: "
len3 equ $- msg3

section .bss
num1 resb 2
num2 resb 2 
res resb 1

section .text
global _start
_start :
  
  ;typing the first msg
  mov edx,len1
  mov ecx,msg1
  mov ebx,1 
  mov eax,4
  int 0x80
  
  ;getting the user input for the first number 
  mov edx,2 
  mov ecx,num1
  mov ebx,0 
  mov eax,3
  int 0x80
  
  ;typing the second msg 
  mov edx,len2
  mov ecx,msg2
  mov ebx,1 
  mov eax,4
  int 0x80
  
  ;getting the 2nd user input
  mov edx,2 
  mov ecx,num2
  mov ebx,0 
  mov eax,3
  int 0x80
  
  ; moving the first number to eax register and second number to ebx
  mov eax,[num1]
  sub eax,'0' ; subtract to convert ascii into decimal
  mov ebx,[num2]
  sub ebx,'0'
  
  add eax,ebx
  add eax,'0' ; to convert decimal into ascii again
  
  mov [res],eax ; storing the sum in res memory location
  
  ;typing the third msg 
  mov edx,len3
  mov ecx,msg3
  mov ebx,1 
  mov eax,4
  int 0x80
  
  ;printing the sum
  mov edx,1
  mov ecx,res
  mov ebx,1 
  mov eax,4
  int 0x80
  
  
  
  ;exiting
  mov ebx,0
  mov eax,1 
  int 0x80