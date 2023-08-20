# Defina o compilador a ser usado (gcc, clang, etc.)
CC = gcc

# Defina as opções de compilação
CFLAGS = -Wall -Wextra -pedantic

# Defina o nome dos executáveis
EXECUTABLE1 = trabalho
EXECUTABLE2 = trabalho2listas
EXECUTABLE3 = trabalho2ordenalistas

# Arquivos fonte do primeiro projeto
SOURCES1 = trabalho.c estoque.c
HEADERS1 = estoque.h

# Arquivos fonte do segundo projeto
SOURCES2 = trabalho2_listas.c lista.c
HEADERS2 = lista.h

# Arquivos fonte do terceiro projeto
SOURCES3 = trabalho2_ordenalistas.c estoque.c
HEADERS3 = estoque.h

# Objetos gerados para o primeiro projeto
OBJECTS1 = $(patsubst %.c,%.o,$(SOURCES1))

# Objetos gerados para o segundo projeto
OBJECTS2 = $(patsubst %.c,%.o,$(SOURCES2))

# Objetos gerados para o terceiro projeto
OBJECTS3 = $(patsubst %.c,%.o,$(SOURCES3))

# Defina o alvo padrão (gera todos os executáveis)
all: $(EXECUTABLE1) $(EXECUTABLE2) $(EXECUTABLE3)

# Gera o executável para o primeiro projeto
$(EXECUTABLE1): $(OBJECTS1)
	$(CC) $(CFLAGS) -o $(EXECUTABLE1) $(OBJECTS1)

# Gera o executável para o segundo projeto
$(EXECUTABLE2): $(OBJECTS2)
	$(CC) $(CFLAGS) -o $(EXECUTABLE2) $(OBJECTS2)

# Gera o executável para o terceiro projeto
$(EXECUTABLE3): $(OBJECTS3)
	$(CC) $(CFLAGS) -o $(EXECUTABLE3) $(OBJECTS3)

# Regras para compilar objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Comando para limpar os arquivos objetos e os executáveis
clean:
	rm -f *.o $(EXECUTABLE1) $(EXECUTABLE2) $(EXECUTABLE3)

.PHONY: all clean
