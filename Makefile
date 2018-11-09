CC = gcc
NAME = gameboyZero

#Auto file grabbing
INIT = main.c
FILES = $(wildcard *.c)
LIBS = $(filter-out $(INIT), $(FILES))
OBJS = $(patsubst %.c, $(BLD)/%.o, $(LIBS))
BLD = bld

WARN = -Wall
OPT = -O3
LINK = -pthread


EXE = $(NAME).exe
DIS = $(NAME).asm


all: $(EXE)

$(EXE): $(INIT) $(OBJS)
	$(CC) $(WARN) $(OPT) -o $@ $^

$(BLD)/%.o: %.c
	$(CC) $(WARN) $(OPT) -o $@ -c $^

$(BLD)/%.o: %.c %.h
	$(CC) $(WARN) $(OPT) -o $@ -c $^

.PHONY: all clean remake

clean:
	rm -rf $(BLD)/* *.o *.exe *.asm

remake:
	make clean; make