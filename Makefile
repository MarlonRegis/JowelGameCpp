# Nome do executável
TARGET = JewelCollector

CC = g++
CFLAGS = -c -Wall -ansi -pedantic -std=c++17

# Diretórios de origem e destino
CORE_DIR = Core
MAIN_DIR = Main
OBJ_DIR = obj
BIN_DIR = bin
CORE := -I./Core/
MAIN := -I./Main/

# Lista de arquivos fonte e objetos para as classes Core
CORE_SRCS = Core/ItemModel.cpp Core/FoodModel.cpp Core/JewelModel.cpp
CORE_OBJS = $(patsubst $(CORE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CORE_SRCS))

# Lista de arquivos fonte e objetos para as classes Main
MAIN_SRCS = $(wildcard $(MAIN_DIR)/*.cpp)
MAIN_OBJS = $(patsubst $(MAIN_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SRCS))

#Remove Command
RM = -del

all: $(BIN_DIR)/$(TARGET)

# Compilação dos arquivos fonte em objetos para as classes Core
$(OBJ_DIR)/%.o: $(CORE_DIR)/%.cpp
	$(CC) -c $< -o $@

# Compilação dos arquivos fonte em objetos para as classes Main
$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.cpp
	$(CC) -c $< -o $@

# Linkagem dos objetos para gerar o executável
$(BIN_DIR)/$(TARGET): $(CORE_OBJS) $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o $@ $(MAIN_DIR)/JewelCollector.cpp $(CORE) $(MAIN) $^

clean:
	$(RM) $(OBJ_DIR)\*.o $(BIN_DIR)\$(TARGET).exe
