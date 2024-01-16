# Defina o compilador a ser usado (gcc, clang, etc.)
CC = gcc
# Defina as opções de compilação
CFLAGS = -Wall -Wextra -pedantic
# Defina o nome dos executáveis
EXECUTABLE1 = trabalho
# Arquivos fonte do primeiro projeto
SOURCES1 = decisionTree.c tree.c
HEADERS1 = tree.h
# Objetos gerados para o primeiro projeto
OBJECTS1 = $(patsubst %.c,%.o,$(SOURCES1))
# Defina o alvo padrão (gera todos os executáveis)
all: $(EXECUTABLE1)
# Gera o executável para o primeiro projeto
$(EXECUTABLE1): $(OBJECTS1)
	$(CC) $(CFLAGS) -o $(EXECUTABLE1) $(OBJECTS1)
# Regras para compilar objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Comando para limpar os arquivos objetos e os executáveis
clean:
	rm -f *.o $(EXECUTABLE1)
.PHONY: all clean