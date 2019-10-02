# Opções do compilador
CC = g++
CFLAGS = -I/usr/include -Iresources/include -Isrc/utils/classes -Isrc/thirdparty -O2 -Wall -std=c++11 -DDEBUG
LDFLAGS = -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system

# Diretórios
SRC_DIR = ./src
BUILD_DIR = ./build

# Nome dos executáveis
BIN = jogo
CPP_BIN = $(SRC_DIR)/main.cpp

# Código-fonte (emendar outros wildcards caso tenha mais diretórios)
CPP = $(wildcard $(SRC_DIR)/utils/classes/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.hpp) $(wildcard $(SRC_DIR)/utils/classes/*.hpp)

# Objetos
OBJ = $(subst $(SRC_DIR),$(BUILD_DIR),$(CPP:%.cpp=%.cpp.o))
OBJ_BIN = $(subst $(SRC_DIR),$(BUILD_DIR),$(CPP_BIN:%.cpp=%.cpp.o))

# Makefile targets

.PHONY = default all clean

default: $(BIN)
all: default

$(BUILD_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@echo "CC      $<"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ_BIN) $(OBJ)
	@echo "LD      $<"
	@$(CC) $(OBJ_BIN) $(OBJ) $(LDFLAGS) -o $@

clean:
	-rm -f $(BIN)
	-rm -f $(BUILD_DIR)/*.cpp.o
	-rm -f $(BUILD_DIR)/utils/classes/*.cpp.o
