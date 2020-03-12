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

SOURCE_FILES			:= $(C_SOURCE_FILES) $(CXX_SOURCE_FILES)
SOURCE_FILES_BASE		:= $(C_SOURCE_FILES_BASE) $(CXX_SOURCE_FILES_BASE)
OBJECT_FILES			:= $(C_OBJECT_FILES) $(CXX_OBJECT_FILES)
SOURCE_DIRS				:= $(shell find ./$(SRC)/ -type d)
DEP_FILES				:= $(C_DEP_FILES) $(CXX_DEP_FILES)

EXE = $(NAME).exe
DIS = $(NAME).asm


TEST_SOURCE_FILES			:= $(C_TEST_SOURCE_FILES) $(CXX_TEST_SOURCE_FILES)
TEST_SOURCE_FILES_BASE		:= $(C_TEST_SOURCE_FILES_BASE) $(CXX_TEST_SOURCE_FILES_BASE)
TEST_OBJECT_FILES			:= $(C_TEST_OBJECT_FILES) $(CXX_TEST_OBJECT_FILES) $(filter-out $(BLD)/main.o, $(OBJECT_FILES))
TEST_SOURCE_DIRS			:= $(shell find ./$(TST)/ -type d)
TEST_DEP_FILES				:= $(C_TEST_DEP_FILES) $(CXX_TEST_DEP_FILES) 

CC 		:= gcc
CXX		:= g++
ASM_CMD := objdump
IMG_CMD := objcopy

.PHONY: all clean remake

clean:
	rm -rf $(BLD)/* *.o *.exe *.asm

remake:
	make clean; make