CC = g++
CFLAGS = -c -Wall -ansi -pedantic -std=c++17

# Diretórios de origem e destino
CORE_DIR = Core
MAIN_DIR = Main
OBJ_DIR = obj
BIN_DIR = bin

# Lista de arquivos fonte e objetos para as classes Core
CORE_SRCS = $(wildcard $(CORE_DIR)/*.cpp)
CORE_OBJS = $(patsubst $(CORE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CORE_SRCS))

# Lista de arquivos fonte e objetos para as classes Main
MAIN_SRCS = $(wildcard $(MAIN_DIR)/*.cpp)
MAIN_OBJS = $(patsubst $(MAIN_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SRCS))

# Nome do executável
EXEC = JewelGame

all: $(BIN_DIR)/$(EXEC)

# Compilação dos arquivos fonte em objetos para as classes Core
$(OBJ_DIR)/%.o: $(CORE_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Compilação dos arquivos fonte em objetos para as classes Main
$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Linkagem dos objetos para gerar o executável
$(BIN_DIR)/$(EXEC): $(CORE_OBJS) $(MAIN_OBJS)
	$(CC) $(CFLAGS)  $^ -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC)
