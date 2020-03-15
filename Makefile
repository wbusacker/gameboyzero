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
DEP_FILES					+= $(C_TEST_DEP_FILES) $(CXX_TEST_DEP_FILES) 

CC 		:= /opt/gcc-9.3/bin/gcc
CXX		:= /opt/gcc-9.3/bin/g++
ASM_CMD := /opt/gcc-9.3/bin/objdump
IMG_CMD := /opt/gcc-9.3/bin/objcopy

OPT 			:= -O3 -g
INCLUDE_DIRS 	:= $(addprefix -I, $(SOURCE_DIRS))
WARN			:= -Wall
LINK			:= -lpthread -lncurses
CFLAGS 			:= $(INCLUDE_DIRS) $(OPT) $(WARN) $(LINK)
DEPFLAGS		= -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

# Output Files
EXE := $(PRJ_NAME).exe
IMG := $(PRJ_NAME).img
GTS := $(PRJ_NAME).test.exe

all: $(EXE) $(GTS)

exe: $(EXE)

img: $(IMG)

test: $(GTS)
	./$(GTS)

stat:
	@echo Main Source Files
	@echo $(SOURCE_FILES)
	@echo Test Source Files
	@echo $(TEST_SOURCE_FILES)
	@echo Main OBJECT Files
	@echo $(OBJECT_FILES)
	@echo Test OBJECT Files
	@echo $(TEST_OBJECT_FILES)

clean:
	rm -rf $(BLD)/* *.o *.exe *.asm

remake:
	make clean; make