CC = gcc
CFLAGS = -Wall -Wextra -I./src $(shell pkg-config --cflags gtk+-3.0 ) $(shell pkg-config --libs gtk+-3.0 )
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRCFILES := $(shell find $(SRCDIR) -type f -name '*.c')

OBJFILES := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o,$(SRCFILES))
EXECUTABLE = $(BINDIR)/main

$(EXECUTABLE): $(OBJFILES)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(OBJDIR)/* $(EXECUTABLE)

run:
	./$(EXECUTABLE)