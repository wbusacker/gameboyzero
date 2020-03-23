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

# Surpress stdout
M	:= @

all: $(EXE) $(GTS)

exe: $(EXE)

img: $(IMG)

test: $(GTS)
	./$(GTS)

stat:
	$(M)echo Main Source Files
	$(M)echo $(SOURCE_FILES)
	$(M)echo Test Source Files
	$(M)echo $(TEST_SOURCE_FILES)
	$(M)echo Main OBJECT Files
	$(M)echo $(OBJECT_FILES)
	$(M)echo Test OBJECT Files
	$(M)echo $(TEST_OBJECT_FILES)

clean:
<<<<<<< HEAD
<<<<<<< HEAD
	rm -rf $(BLD)/* *.o *.exe *.asm
=======
	@echo Cleaning
	@rm -rf $(BLD)/*.o $(EXE) $(GTS)
=======
	$(M)echo Cleaning
	$(M)rm -rf $(BLD)/*.o $(EXE) $(GTS)
>>>>>>> 45f3852... Added 16 bit loads

cleanall:
	$(M)echo Cleaning all
	$(M)rm -rf $(BLD)/* $(EXE) $(GTS)	

remake: clean all

$(EXE): $(OBJECT_FILES)
	$(M)echo Linking
	$(M)$(CXX) $(CFLAGS) -o $@ $^

$(IMG): $(EXE)
	$(M)echo Building Image
	$(M)$(IMG_CMD) -Obinary $^ $@

$(GTS): $(TEST_OBJECT_FILES)
	$(M)echo Linking Test 
	$(M)$(CXX) $(CFLAGS) -o $@ $^ -lgtest -lgmock

# Generic Rules
$(BLD)/%.o: **/**/%.c **/**/%.h  | $(DEPDIR) $(DEPDIR)/%.d
	$(M)echo Compiling $(@F)
	$(M)$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.c | $(DEPDIR) $(DEPDIR)/%.d
	$(M)echo Compiling $(@F)
	$(M)$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.cpp **/**/%.h  | $(DEPDIR) $(DEPDIR)/%.d
	$(M)echo Compiling $(@F)
	$(M)$(CXX) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.cpp | $(DEPDIR) $(DEPDIR)/%.d
	$(M)echo Compiling $(@F)
	$(M)$(CXX) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

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