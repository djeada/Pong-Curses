# Makefile for the ncurses game with source files in src directory

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Directories
SRCDIR = src
BINDIR = bin

# Executable name
TARGET = $(BINDIR)/game

# Source and header files
SRCS = $(wildcard $(SRCDIR)/*.c)
HDRS = $(wildcard $(SRCDIR)/*.h)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(SRCDIR)/%.o)

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lncurses

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o $(TARGET)
	rm -rf $(BINDIR)

.PHONY: all clean
