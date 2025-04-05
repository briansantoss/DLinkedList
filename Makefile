CC = gcc
CFLAGS = -Iinclude

SRCDIR = src/
OBJDIR = obj/
BINDIR = bin/

SRCS = $(wildcard $(SRCDIR)*.c)
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

all: main
	@./$(BINDIR)$<

main: $(OBJS)
	@$(CC) $(CFLAGS) -o $(BINDIR)$@ $^

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm $(OBJDIR)*
	@rm $(BINDIR)*