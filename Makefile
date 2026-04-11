# SuperFetch Makefile

CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99
TARGET = superfetch
SRC = src/main.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean install

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)

test: $(TARGET)
	./$(TARGET) --help
	./$(TARGET)

.PHONY: help
help:
	@echo "SuperFetch Build System"
	@echo ""
	@echo "Targets:"
	@echo "  all      - Build SuperFetch (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  install  - Install SuperFetch to /usr/local/bin"
	@echo "  test     - Run basic tests"
	@echo "  help     - Show this help"