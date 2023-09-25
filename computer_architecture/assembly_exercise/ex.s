	.file	"ex.c"                  ; Nome do arquivo fonte original.
	.text                           ; Começo da seção de código.
	.section	.rodata            ; Seção de dados somente leitura.
	.align 8                        ; Alinha a próxima instrução na memória (em múltiplos de 8 bytes).
.LC0:
	.string	"Digite o valor do primeiro número: "  ; Define a mensagem a ser impressa.
.LC1:
	.string	"%d"                    ; Define o formato para leitura de um número inteiro.
	.align 8                        ; Alinha a próxima instrução na memória.
.LC2:
	.string	"Digite o valor do segundo número: "   ; Define a segunda mensagem a ser impressa.
.LC3:
	.string	"A soma de %d e %d é: %d\n"            ; Define o formato da mensagem de saída.
	.text                           ; Começo da seção de código.
	.globl	main                    ; Define a função principal (global).
	.type	main, @function         ; Indica que 'main' é uma função.
main:
.LFB0:
	.cfi_startproc                  ; Marca o início da função 'main'.
	pushq	%rbp                        ; Salva o valor de %rbp na pilha.
	.cfi_def_cfa_offset 16           ; Define o deslocamento de %rsp para %rbp como 16.
	.cfi_offset 6, -16               ; Define o deslocamento de %rbp em relação a %rsp como -16.
	movq	%rsp, %rbp                  ; Copia o valor de %rsp para %rbp.
	.cfi_def_cfa_register 6          ; Define %rbp como o registrador de controle de frame atual.
	subq	$32, %rsp                   ; Aloca espaço na pilha para variáveis locais.
	movq	%fs:40, %rax                ; Carrega o valor do registrador %fs:40 em %rax.
	movq	%rax, -8(%rbp)              ; Salva o valor de %rax na pilha.
	xorl	%eax, %eax                  ; Coloca 0 em %eax (limpa o registro).
	leaq	.LC0(%rip), %rax            ; Carrega o endereço de .LC0 em %rax.
	movq	%rax, %rdi                  ; Move %rax (endereço da mensagem) para %rdi (registro de destino).
	movl	$0, %eax                    ; Coloca 0 em %eax (limpa o registro).
	call	printf@PLT                ; Chama a função printf para imprimir a mensagem.
	leaq	-20(%rbp), %rax             ; Carrega o endereço de uma variável local em %rax.
	movq	%rax, %rsi                  ; Move o endereço de %rax para %rsi (usado para leitura).
	leaq	.LC1(%rip), %rax            ; Carrega o endereço de .LC1 em %rax.
	movq	%rax, %rdi                  ; Move %rax (formato de leitura) para %rdi (registro de destino).
	movl	$0, %eax                    ; Coloca 0 em %eax (limpa o registro).
	call	__isoc99_scanf@PLT         ; Chama a função scanf para ler um número inteiro.
	leaq	.LC2(%rip), %rax            ; Carrega o endereço de .LC2 em %rax.
	movq	%rax, %rdi                  ; Move %rax (endereço da segunda mensagem) para %rdi.
	movl	$0, %eax                    ; Coloca 0 em %eax (limpa o registro).
	call	printf@PLT                ; Chama a função printf para imprimir a segunda mensagem.
	leaq	-16(%rbp), %rax             ; Carrega o endereço de outra variável local em %rax.
	movq	%rax, %rsi                  ; Move o endereço de %rax para %rsi (usado para leitura).
	leaq	.LC1(%rip), %rax            ; Carrega o endereço de .LC1 em %rax.
	movq	%rax, %rdi                  ; Move %rax (formato de leitura) para %rdi (registro de destino).
	movl	$0, %eax                    ; Coloca 0 em %eax (limpa o registro).
	call	__isoc99_scanf@PLT         ; Chama a função scanf para ler outro número inteiro.
	movl	-20(%rbp), %edx             ; Move o primeiro número lido para %edx.
	movl	-16(%rbp), %eax             ; Move o segundo número lido para %eax.
	addl	%edx, %eax                  ; Soma os dois números e armazena em %eax.
	movl	%eax, -12(%rbp)             ; Armazena o resultado da soma em uma variável local.
	movl	-16(%rbp), %edx             ; Move o segundo número lido para %edx.
	movl	-20(%rbp), %eax             ; Move o primeiro número lido para %eax.
	movl	-12(%rbp), %ecx             ; Move o resultado da soma para %ecx.
	movl	%eax, %esi                  ; Move o primeiro número lido para %esi (usado para imprimir).
	leaq	.LC3(%rip), %rax            ; Carrega o endereço da mensagem de saída em %rax.
	movq	%rax, %rdi                  ; Move %rax (endereço da mensagem de saída) para %rdi.
	movl	$0, %eax                    ; Coloca 0 em %eax (limpa o registro).
	call	printf@PLT                ; Chama a função printf para imprimir o resultado.
	movl	$0, %eax                    ; Coloca 0 em %eax (limpa o registro).
	movq	-8(%rbp), %rdx              ; Carrega o valor salvo de %fs:40 em %rdx.
	subq	%fs:40, %rdx                ; Subtrai o valor atual de %fs:40 de %rdx.
	je	.L3                          ; Se a comparação resultar em zero, vá para .L3 (verificação de stack smashing).
	call	__stack_chk_fail@PLT        ; Chama a função de verificação de stack smashing.
.L3:
	leave                           ; Sai da função principal.
	.cfi_def_cfa 7, 8               ; Define o registro %rsp como registro de controle de frame atual.
	ret                             ; Retorna da função.
	.cfi_endproc                     ; Marca o fim da função 'main'.
.LFE0:
	.size	main, .-main               ; Define

