# Variáveis
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Isrc
SRC_DIR := src
BIN_DIR := bin
TARGET := $(BIN_DIR)/main
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Regra padrão
all: $(TARGET)
	@echo "Execução do programa..."
	@./$(TARGET)

# Criação do executável
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilação dos arquivos .cpp para .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/main.h
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(BIN_DIR)

# Remover binários e objetos intermediários
distclean: clean

# Falsos alvos
.PHONY: all clean distclean
