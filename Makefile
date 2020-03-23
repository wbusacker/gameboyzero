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

CC 		:= gcc
CXX		:= g++
ASM_CMD := objdump
IMG_CMD := objcopy

OPT 			:= -O0 -g
INCLUDE_DIRS 	:= $(addprefix -I, $(SOURCE_DIRS)) $(addprefix -I, $(TEST_SOURCE_DIRS))
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
<<<<<<< HEAD
	rm -rf $(BLD)/* *.o *.exe *.asm
=======
	@echo Cleaning
	@rm -rf $(BLD)/*.o $(EXE) $(GTS)

cleanall:
	@echo Cleaning all
	@rm -rf $(BLD)/* $(EXE) $(GTS)	

remake: clean all

$(EXE): $(OBJECT_FILES)
	@echo Linking
	@$(CXX) $(CFLAGS) -o $@ $^

$(IMG): $(EXE)
	@echo Building Image
	@$(IMG_CMD) -Obinary $^ $@

$(GTS): $(TEST_OBJECT_FILES)
	@echo Linking Test 
	@$(CXX) $(CFLAGS) -o $@ $^ -lgtest -lgmock

# Generic Rules
$(BLD)/%.o: **/**/%.c **/**/%.h  | $(DEPDIR) $(DEPDIR)/%.d
	@echo Compiling $(@F)
	@$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.c | $(DEPDIR) $(DEPDIR)/%.d
	@echo Compiling $(@F)
	@$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.cpp **/**/%.h  | $(DEPDIR) $(DEPDIR)/%.d
	@echo Compiling $(@F)
	@$(CXX) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.cpp | $(DEPDIR) $(DEPDIR)/%.d
	@echo Compiling $(@F)
	@$(CXX) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

.PHONY: all exe img clean remake test

$(DEP_FILES):

$(TEST_DEP_FILES):

$(SRC):
	mkdir $@

$(BLD):
	mkdir $@

$(DEPDIR): 
	mkdir $@
>>>>>>> 9cb9829... Unit tested main Arithmetic Functions

remake:
	make clean; make