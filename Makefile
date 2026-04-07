# Makefile for Snake Game with Raylib
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -W
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Directories
SRC_DIR = src
OBJ_DIR = build
BIN = build/snake.exe
INCLUDE_DIR = include

# Source files
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/snake.c
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/snake.o

# Targets
all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Build successful! Run with: ./build/snake.exe"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BIN)
	@echo "Clean complete!"

run: $(BIN)
	./$(BIN)

.PHONY: all clean run
