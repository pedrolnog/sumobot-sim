CC = gcc

# Flags de compilação: 
# -Wall (todos os avisos) 
# -Iinclude (procura os .h na pasta include)
# -g (inclui info de debug para o GDB)
CFLAGS = -Wall -Iinclude -g 
TARGET = sumo-sim_v0.1 # Lembra de mudar no .gitignore


# LDFLAGS = -lm // Vou começar a usar quando incluir math.h


SRC = $(wildcard src/*.c)

# Cria uma lista de arquivos .o baseada nos .c
# src/main.c vira src/main.o
OBJ = $(SRC: .c=.o)

# Alvo principal
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) 

# Compila cada arquivo .c em um .o
# $< é o arquivo de origem (.c)
# $@ é o arquivo de destino (.o)
%.o: %.c
	$(CC) $(CLFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

# Avisa o make que 'all' e 'clean' não são arquivos físicos
.PHONY: all clean