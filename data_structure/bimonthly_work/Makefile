# makefile

# Defina o compilador a ser usado (gcc, clang, etc.)
CC = x86_64-w64-mingw32-gcc

# Defina as opções de compilação
CFLAGS = -Wall -Wextra -pedantic

# Defina o nome do executável
EXECUTABLE = trabalho.exe

# Defina os arquivos fonte do projeto
SOURCES = trabalho.c estoque.c

# Defina o alvo padrão (gera o executável)
all: $(EXECUTABLE)

# Gera o executável
$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

# Comando para limpar os arquivos objetos e o executável
clean:
	rm -f $(EXECUTABLE)