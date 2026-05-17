# Makefile - Festinha junina
# Usado para compilação e execução do programa

CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
TARGET = build/festa

build: $(TARGET)

$(TARGET): $(OBJ) | build/
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c | build/
	$(CC) $(CFLAGS) -c -o $@ $<

build/:
	mkdir -p build

run: build
	./$(TARGET)

clean:
	rm -rf build

help:
	@echo 'Ajuda Makefile'
	@echo '  build            compila o programa'
	@echo '  run              executa o programa'
	@echo '  clean            limpa os arquivos de compilação'
	@echo '  help             exibe essa ajuda'

.PHONY: build run clean help