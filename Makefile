# Nome do executável
TARGET = tinyengine.exe

# Diretórios
SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
OBJ_DIR = obj

# Compilador e flags
CC = gcc
CFLAGS = -I$(INC_DIR) -I$(INC_DIR)/SDL3 -I$(INC_DIR)/SDL3_ttf
LDFLAGS = -L$(LIB_DIR) -lSDL3 -lSDL3_ttf -lfreetype


# Lista de arquivos .c e .o
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regra padrão
all: $(TARGET)

# Compila o executável
$(TARGET): $(OBJS)
	@echo Linking...
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo Build complete!

# Compila cada .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@

# Cria a pasta obj se não existir
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# Limpa tudo
clean:
	del /Q $(OBJ_DIR)\*.o 2>nul || echo No object files to remove.
	del /Q $(TARGET) 2>nul || echo No executable to remove.
	@echo Clean done! 🧹

# Evita conflitos com arquivos de mesmo nome
.PHONY: all clean
